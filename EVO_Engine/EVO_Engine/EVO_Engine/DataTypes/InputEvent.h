#ifndef INPUTEVENT_H
#define INPUTEVENT_H

#include <vector>
#include <SDL.h>

namespace EVO_ENGINE {

	struct MouseEvent {
		int x;
		int y;
		int buttonType;
	};

	struct KeyEvent {
		std::vector<SDL_Keycode> keysDown;

		bool IsKeyPressed(SDL_Keycode key_) {
			if (std::find(keysDown.begin(), keysDown.end(), key_) != keysDown.end()) {
				return true;
			}
			return false;
		}
	};

	struct GamePadEvent {
		int xDirection;
		int yDirection;
		float angle;

		void UpdateAngle() {
			if (xDirection == 0 && yDirection == 0) {
				angle = 0.0f;
				return;
			}
			angle = atan2((float)yDirection, (float)xDirection) * (180.0f / M_PI);
		}
	};
}
#endif // !INPUTEVENT_H

