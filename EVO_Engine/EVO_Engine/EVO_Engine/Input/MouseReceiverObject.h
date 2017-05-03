#ifndef MOUSERECEIVEROBJECT_H
#define MOUSERECEIVEROBJECT_H

#include "../DataTypes/InputEvent.h"

namespace EVO_ENGINE {

	class MouseReceiverObject {

	public:
		MouseReceiverObject() {}
		virtual ~MouseReceiverObject() {}

		virtual void NotifyOfMousePressed(MouseEvent event_) = 0;
		virtual void NotifyOfMouseReleased(MouseEvent event_) = 0;
		virtual void NotifyOfMouseMoved(MouseEvent event_) = 0;
		virtual void NotifyOfMouseScroll(MouseEvent event_) = 0;

	};

}

#endif // !MOUSERECEIVEROBJECT_H
