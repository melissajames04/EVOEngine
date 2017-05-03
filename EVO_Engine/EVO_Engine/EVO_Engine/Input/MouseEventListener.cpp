#include "MouseEventListener.h"

#include <iostream>
#include "../DataTypes/GameState.h"

using namespace EVO_ENGINE;

std::unique_ptr<MouseEventListener> MouseEventListener::mouseInstance(nullptr);

MouseEventListener::MouseEventListener(): currentEvent(MouseEvent()), previousEvent(MouseEvent()){

}

MouseEventListener::~MouseEventListener() {

	ClearAllListeningObjects();

}

MouseEventListener* MouseEventListener::GetInstance() {
	if (mouseInstance.get() == nullptr) {
		mouseInstance.reset(new MouseEventListener);
	}
	return mouseInstance.get();
}

void MouseEventListener::Update(SDL_Event e) {

	currentEvent = CreateMouseEvent(e);

	switch (e.type) {
	case SDL_MOUSEBUTTONDOWN:
		NotifyOfMousePressed(currentEvent);
		break;
	case SDL_MOUSEBUTTONUP:
		NotifyOfMouseReleased(currentEvent);
		break;
	case SDL_MOUSEMOTION:
		NotifyOfMouseMoved(currentEvent);
		break;
	case SDL_MOUSEWHEEL:
		NotifyOfMouseScroll(currentEvent);
		break;

	default:
		break;
	}

}

MouseEvent MouseEventListener::CreateMouseEvent(SDL_Event e) {
	MouseEvent mEvent = MouseEvent();
	SDL_GetMouseState(&mEvent.x, &mEvent.y);
	mEvent.y = GameState::GetInstance()->GetWindowHeight() - mEvent.y;
	mEvent.buttonType = e.button.button;
	
	previousEvent = currentEvent;

	return mEvent;
}

void MouseEventListener::NotifyOfMousePressed(MouseEvent event_) {
	
	for (auto obj : registeredObjects) {
		obj->NotifyOfMousePressed(event_);
	}

}

void MouseEventListener::NotifyOfMouseReleased(MouseEvent event_) {

	for (auto obj : registeredObjects) {
		obj->NotifyOfMouseReleased(event_);
	}

}

void MouseEventListener::NotifyOfMouseMoved(MouseEvent event_) {

	std::cout << "Mouse Move-> X: " << event_.x << " Y: " << event_.y << std::endl;
	for (auto obj : registeredObjects) {
		obj->NotifyOfMouseMoved(event_);
	}

}

void MouseEventListener::NotifyOfMouseScroll(MouseEvent event_) {

	for (auto obj : registeredObjects) {
		obj->NotifyOfMouseScroll(event_);
	}

}