#include "KeyEventListener.h"

#include <iostream>

using namespace EVO_ENGINE;

std::unique_ptr<KeyEventListener> KeyEventListener::keyInstance(nullptr);

KeyEventListener::KeyEventListener() : currentEvent(KeyEvent()) {
	currentEvent.keysDown = std::vector<SDL_Keycode>();
}

KeyEventListener::~KeyEventListener() {

	ClearAllListeningObjects();

}

KeyEventListener* KeyEventListener::GetInstance() {
	if (keyInstance.get() == nullptr) {
		keyInstance.reset(new KeyEventListener);
	}
	return keyInstance.get();
}

void KeyEventListener::Update(SDL_Event e) {


	switch (e.type) {
	case SDL_KEYDOWN:
		AddKey(e);
		NotifyOfKeyPressed(currentEvent);
		break;
	case SDL_KEYUP:
		ReleaseKey(e);
		NotifyOfKeyReleased(currentEvent);
		break;
	default:
		break;
	}

}

void KeyEventListener::ReleaseKey(SDL_Event e) {
	bool isFound = false;
	for (int i = 0; i < currentEvent.keysDown.size(); i++) {
		if (currentEvent.keysDown[i] == e.key.keysym.sym) {
			isFound = true;
			std::cout << "Key Released" << std::endl;
		}
		if (isFound && (i + 1) < currentEvent.keysDown.size()) {
			currentEvent.keysDown[i] = currentEvent.keysDown[i + 1];
		}
	}
	if (isFound) {
		currentEvent.keysDown.pop_back();
	}
}

void KeyEventListener::AddKey(SDL_Event e) {
	if (std::find(currentEvent.keysDown.begin(), currentEvent.keysDown.end(), e.key.keysym.sym) == currentEvent.keysDown.end()) {
		currentEvent.keysDown.push_back(e.key.keysym.sym);
		std::cout << "Key Pressed" << std::endl;
	}
}

void KeyEventListener::NotifyOfKeyPressed(KeyEvent event_) {

	for (auto obj : registeredObjects) {
		obj->NotifyOfKeyPressed(event_);
	}

}

void KeyEventListener::NotifyOfKeyReleased(KeyEvent event_) {
	
	for (auto obj : registeredObjects) {
		obj->NotifyOfKeyReleased(event_);
	}

}