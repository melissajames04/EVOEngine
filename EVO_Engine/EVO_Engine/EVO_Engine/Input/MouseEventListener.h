#ifndef MOUSEEVENTLISTENER_H
#define MOUSEEVENTLISTENER_H

#include "EventListenerDevice.h"
#include "MouseReceiverObject.h"

namespace EVO_ENGINE {
	
	class MouseEventListener : public EventListenerDevice<MouseReceiverObject*>, public MouseReceiverObject {
	public:
		MouseEventListener(const MouseEventListener&) = delete;
		MouseEventListener(MouseEventListener&&) = delete;
		MouseEventListener& operator = (const MouseEventListener) = delete;
		MouseEventListener& operator = (MouseEventListener&&) = delete;

		void Update(SDL_Event e);

		static MouseEventListener* GetInstance();

	private:
		MouseEventListener();
		virtual ~MouseEventListener();

		static std::unique_ptr<MouseEventListener> mouseInstance;
		friend std::default_delete<MouseEventListener>;
		
		MouseEvent currentEvent, previousEvent;

		void NotifyOfMousePressed(MouseEvent event_);
		void NotifyOfMouseReleased(MouseEvent event_);
		void NotifyOfMouseMoved(MouseEvent event_);
		void NotifyOfMouseScroll(MouseEvent event_);

		MouseEvent CreateMouseEvent(SDL_Event e);
	};

}

#endif // !MOUSEEVENTLISTENER_H
