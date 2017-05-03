#ifndef GAMEPADEVENTLISTENER_H
#define GAMEPADEVENTLISTENER_H

#include "EventListenerDevice.h"
#include "GamePadReceiverObject.h"

namespace EVO_ENGINE {

	class GamePadEventListener : public EventListenerDevice<GamePadReceiverObject*>, public GamePadReceiverObject {
	public:
		GamePadEventListener(const GamePadEventListener&) = delete;
		GamePadEventListener(GamePadEventListener&&) = delete;
		GamePadEventListener& operator = (const GamePadEventListener) = delete;
		GamePadEventListener& operator = (GamePadEventListener&&) = delete;

		void Update(SDL_Event e);

		static GamePadEventListener* GetInstance();

	private:
		GamePadEventListener();
		virtual ~GamePadEventListener();

		GamePadEvent currentEvent;

		static std::unique_ptr<GamePadEventListener> gamepadInstance;
		friend std::default_delete<GamePadEventListener>;

		void NotifyOfGamePadPressed(GamePadEvent event_);
		void NotifyOfGamePadReleased(GamePadEvent event_);
		void NotifyOfGamePadMoved(GamePadEvent event_);

		void UpdateGamePadMovement(SDL_Event e);
		void AddButton(SDL_Event e);
		void ReleaseButton(SDL_Event e);

	};

}

#endif // !MOUSEEVENTLISTENER_H
