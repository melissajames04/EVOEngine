#include "GamePadEventListener.h"

#include <iostream>
#include "../DataTypes/GameState.h"

using namespace EVO_ENGINE;

std::unique_ptr<GamePadEventListener> GamePadEventListener::gamepadInstance(nullptr);

GamePadEventListener::GamePadEventListener()  {

}

GamePadEventListener::~GamePadEventListener() {

	ClearAllListeningObjects();

}

GamePadEventListener* GamePadEventListener::GetInstance() {
	if (gamepadInstance.get() == nullptr) {
		gamepadInstance.reset(new GamePadEventListener);
	}
	return gamepadInstance.get();
}

void GamePadEventListener::Update(SDL_Event e) {

	
	switch (e.type) {
	case SDL_JOYAXISMOTION:
		UpdateGamePadMovement(e);
		NotifyOfGamePadMoved(currentEvent);
		break;
	case SDL_JOYBUTTONUP:
		ReleaseButton(e);
		NotifyOfGamePadReleased(currentEvent);
		break;
	case SDL_JOYBUTTONDOWN:
		AddButton(e);
		NotifyOfGamePadPressed(currentEvent);
		break;
	default:
		break;
	}

}

void GamePadEventListener::UpdateGamePadMovement(SDL_Event e) {


}

void GamePadEventListener::AddButton(SDL_Event e) {

}

void GamePadEventListener::ReleaseButton(SDL_Event e) {

}

void GamePadEventListener::NotifyOfGamePadPressed(GamePadEvent event_) {

	for (auto obj : registeredObjects) {
		obj->NotifyOfGamePadPressed(event_);
	}

}

void GamePadEventListener::NotifyOfGamePadReleased(GamePadEvent event_) {

	for (auto obj : registeredObjects) {
		obj->NotifyOfGamePadReleased(event_);
	}

}

void GamePadEventListener::NotifyOfGamePadMoved(GamePadEvent event_) {

	for (auto obj : registeredObjects) {
		obj->NotifyOfGamePadMoved(event_);
	}

}
