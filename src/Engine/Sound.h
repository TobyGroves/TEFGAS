#ifndef TEFGAS_SOUND_H
#define TEFGAS_SOUND_H

#include "Component.h"
#include <memory>
#include <string>
#include <vector>
#include <AL/al.h>
namespace TEFGAS
{	

	/// Sound Component.
	/** This Component can be placed on any Entity to allow it to emit audio. */
	class Sound : public Component
	{

	private:

		//Vars
		ALuint BufferID;
		ALuint SourceID;
		void Sound::load_ogg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
	public:

		///Awake.
		/** Takes the path of the audio file and loads it into memory. */
		void Awake(std::string _path);
		ALuint getID();

		/// play's the sound.
		/** Begins playing the sound when called. */
		void play();
		/// stop's the sound.
		/** Stop's playing the sound when called. */
		void stop();
		/// Update.
		/** This is automatically called by the engine every frame.*/
		void Update();
	};
}
#endif