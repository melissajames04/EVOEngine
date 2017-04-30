#include "GameState.h"

using namespace EVO_ENGINE;

std::unique_ptr<GameState> GameState::gameStateInstance(nullptr);

GameState::GameState() : isRunning(false), isPaused(false) {

}

GameState::~GameState() {

}

GameState* GameState::GetInstance() {
	if (gameStateInstance.get() == nullptr) {
		gameStateInstance.reset(new GameState);
	}
	return gameStateInstance.get();
}