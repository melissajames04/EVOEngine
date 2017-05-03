#ifndef GAMEPADRECEIVEROBJECT_H
#define GAMEPADRECEIVEROBJECT_H

#include "../DataTypes/InputEvent.h"

namespace EVO_ENGINE {

	class GamePadReceiverObject {

	public:
		GamePadReceiverObject() {}
		virtual ~GamePadReceiverObject() {}

		virtual void NotifyOfGamePadPressed(GamePadEvent event_) = 0;
		virtual void NotifyOfGamePadReleased(GamePadEvent event_) = 0;
		virtual void NotifyOfGamePadMoved(GamePadEvent event_) = 0;

	};

}

#endif // !MOUSERECEIVEROBJECT_H
#pragma once
