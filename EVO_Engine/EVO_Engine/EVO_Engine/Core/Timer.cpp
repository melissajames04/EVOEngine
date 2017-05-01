#include "Timer.h"

using namespace EVO_ENGINE;

Timer::Timer() : prevTicks(0), currTicks(0) {

}

Timer::~Timer() {

}


bool Timer::Initialize() {
	prevTicks = currTicks = SDL_GetTicks();
	return true;
}

void Timer::Update() {
	prevTicks = currTicks;
	currTicks = SDL_GetTicks();
}

float Timer::GetDeltaTime() const {
	return(currTicks - prevTicks) / 1000.0f;
}

unsigned int Timer::GetSleepTime(const short fps_) const {
	unsigned int millisecsPerFrame = 1000 / fps_;

	if (millisecsPerFrame == 0) {
		return millisecsPerFrame;
	}

	unsigned int sleepTime = millisecsPerFrame - (SDL_GetTicks());
	if (sleepTime > millisecsPerFrame) {
		return millisecsPerFrame;
	}
	return sleepTime;
}

