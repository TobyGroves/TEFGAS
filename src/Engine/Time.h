#pragma once
#include <ctime>

namespace TEFGAS
{
	class Time {
	public:
		/// Constructor.
		/** Initialises the time variable. */
		Time();

		clock_t clock;

		float oldTime;

		float newTime;
		/// Delta time.
		/** The time between last frame and this frame. */
		float deltaTime;

		float startTime;

		float time;
		/// gameStart.
		/** must eb called at once the engine is started so it can regulate time. */
		void gameStart();
		/// time Update.
		/** updates the delta time variable for use elsewhere. */
		void timeUpdate();
	};
}