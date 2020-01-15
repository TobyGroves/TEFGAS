#include "Sound.h"
#include <AL/al.h>
#include <AL/alc.h>
#include "stb_vorbis.h"

#include <iostream>
#include <vector>

namespace TEFGAS
{

	void Sound::Awake(std::string _path)
	{
		BufferID = 0;
		alGenBuffers(1, &BufferID);

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;
		load_ogg(_path, bufferData, format, freq);

		alBufferData(BufferID, format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), freq);
	}

	ALuint Sound::getID()
	{
		return BufferID;
	}

	void Sound::play()
	{

		std::cout << "spice girls" << std::endl;
		SourceID = 0;
		alGenSources(1, &SourceID);

		alSource3f(SourceID, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(SourceID, AL_BUFFER, BufferID);
		alSourcePlay(SourceID);
	}

	void Sound::Update()
	{
		ALint state = 0;
		alGetSourcei(SourceID, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			alDeleteSources(1, &SourceID);
		}
	}

	void Sound::Start()
	{
		std::cout << "we here" << std::endl;

		play();
	}

	void Sound::load_ogg(const std::string& fileName, std::vector<char>& buffer,
		ALenum& format, ALsizei& freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(
			fileName.c_str(), &channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::exception();
		}

		// Record the sample rate required by OpenAL
		freq = sampleRate;

		// Record the format required by OpenAL
		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}
		else
		{
			format = AL_FORMAT_STEREO16;

			// Force format to be mono (Useful for positional audio)
			// format = AL_FORMAT_MONO16;
			// freq *= 2;
		}

		// Allocate enough space based on short (two chars) multipled by the number of
		// channels and length of clip
		buffer.resize(sizeof(*output) * channels * samples);
		memcpy(&buffer.at(0), output, buffer.size());

		// Clean up the read data
		free(output);
	}
}
