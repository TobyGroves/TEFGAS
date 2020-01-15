#ifndef TEFGAS_SOUND_H
#define TEFGAS_SOUND_H

#include "Component.h"
#include <memory>
#include <string>
#include <vector>
#include <AL/al.h>
namespace TEFGAS
{	
	class Sound : public Component
	{

	private:

		//Vars
		ALuint BufferID;
		ALuint SourceID;

		//Functions
		void Sound::load_ogg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);
	public:

		void Awake(std::string _path);
		ALuint getID();

		void play();
		void Update();
		void Start(); // make it play the thing once the engine has started before the loop 
	};
}
#endif