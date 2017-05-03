#ifndef KEYRECEIVEROBJECT_H
#define KEYRECEIVEROBJECT_H

#include "../DataTypes/InputEvent.h"

namespace EVO_ENGINE {

	class KeyReceiverObject {

	public:
		KeyReceiverObject() {}
		virtual ~KeyReceiverObject() {}

		virtual void NotifyOfKeyPressed(KeyEvent event_) = 0;
		virtual void NotifyOfKeyReleased(KeyEvent event_) = 0;


	};

}

#endif // !MOUSERECEIVEROBJECT_H
