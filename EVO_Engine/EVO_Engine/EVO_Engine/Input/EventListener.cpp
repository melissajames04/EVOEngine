#include "EventListener.h"
#include "../DataTypes/GameState.h"

using namespace EVO_ENGINE;

void EventListener::Update() {

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			GameState::GetInstance()->SetRunning(false);
			return;
		}

		switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEWHEEL:
			MouseEventListener::GetInstance()->Update(event);
			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			KeyEventListener::GetInstance()->Update(event);
			break;
		case SDL_JOYAXISMOTION:
		case SDL_JOYBUTTONUP:
		case SDL_JOYBUTTONDOWN:
			GamePadEventListener::GetInstance()->Update(event);
			break;
		default:
			break;
		}
	}

}