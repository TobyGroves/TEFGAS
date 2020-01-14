#pragma once
#include <ctime>

namespace TEFGAS
{
	class Time {
	public:

		Time();

		clock_t clock;

		float oldTime;

		float newTime;

		float deltaTime;

		float startTime;

		float time;

		void gameStart();

		void timeUpdate();
	};
}