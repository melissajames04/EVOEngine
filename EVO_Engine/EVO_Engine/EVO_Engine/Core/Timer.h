#ifndef TIMER_H
#define TIMER_H

#include "EngineSystem.h"

#include <SDL.h>

namespace EVO_ENGINE {

	class Timer : public EngineSystem {
	public:
		Timer();
		~Timer();

		Timer(const Timer&) = delete;
		Timer(Timer&&) = delete;
		Timer& operator=(const Timer&) = delete;
		Timer& operator=(Timer&&) = delete;

		bool Initialize();
		void Update();
		void Shutdown() {}

		//Getters
		float GetDeltaTime() const;
		unsigned int GetSleepTime(const short fps) const;
		float GetCurrentTick() { return currTicks; }

	private:
		unsigned int prevTicks;
		unsigned int currTicks;
	};

}

#endif // !TIMER_H
