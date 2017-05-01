#include "EVOEngine.h"

using namespace EVO_ENGINE;

Window EVOEngine::windowInstance;
std::unique_ptr<EVOEngine> EVOEngine::engineInstance(nullptr);


EVOEngine::EVOEngine() {

}

EVOEngine* EVOEngine::GetInstance() {
	if (engineInstance.get() == nullptr) {
		engineInstance.reset(new EVOEngine);
	}
	return engineInstance.get();
}

EVOEngine::~EVOEngine() {
	
	
}

void EVOEngine::Shutdown() {
	windowInstance.Shutdown();
	SDL_Quit();
	exit(0);
}

bool EVOEngine::Initialize() {
	windowInstance.SetWindowSize(800, 400);
	if (!windowInstance.Initialize("MyFirstWindow")) {
		return false;
	}

	timer.Initialize();

	GameState::GetInstance()->SetRunning(true);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	return true;
}

void EVOEngine::Run() {

	while (GameState::GetInstance()->IsRunning()) {
		Update(1 / 60.f);
		Render();
		SDL_Delay(timer.GetSleepTime(GameState::GetInstance()->GetFPS()));
	}
	
	if (!GameState::GetInstance()->IsRunning()) {
		Shutdown();
	}
}

void EVOEngine::Update(const float deltaTime) {

}

void EVOEngine::Render() {

	//Swaps the windows
	windowInstance.Update();
}


