#ifndef KEYEVENTLISTENER_H
#define KEYEVENTLISTENER_H

#include "EventListenerDevice.h"
#include "KeyReceiverObject.h"

namespace EVO_ENGINE {
	
	class KeyEventListener : public EventListenerDevice<KeyReceiverObject*>, public KeyReceiverObject {
	public:
		KeyEventListener(const KeyEventListener&) = delete;
		KeyEventListener(KeyEventListener&&) = delete;
		KeyEventListener& operator = (const KeyEventListener) = delete;
		KeyEventListener& operator = (KeyEventListener&&) = delete;

		void Update(SDL_Event e);

		static KeyEventListener* GetInstance();

	private:
		KeyEventListener();
		virtual ~KeyEventListener();

		static std::unique_ptr<KeyEventListener> keyInstance;
		friend std::default_delete<KeyEventListener>;

		KeyEvent currentEvent;

		void NotifyOfKeyPressed(KeyEvent event_);
		void NotifyOfKeyReleased(KeyEvent event_);


		void ReleaseKey(SDL_Event e);
		void AddKey(SDL_Event e);
	};

}

#endif // !KEYEVENTLISTENER_H
