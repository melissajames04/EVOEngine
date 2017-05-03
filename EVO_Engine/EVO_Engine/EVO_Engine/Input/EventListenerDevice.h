#ifndef EVENTLISTENERDEVICE_H
#define EVENTLISTENERDEVICE_H

#include <SDL.h>
#include <vector>
#include <memory>

namespace EVO_ENGINE {
	
	template<class T>
	class EventListenerDevice {

	public:
		
		EventListenerDevice(const EventListenerDevice&) = delete;
		EventListenerDevice(EventListenerDevice&&) = delete;
		EventListenerDevice& operator = (const EventListenerDevice) = delete;
		EventListenerDevice& operator = (EventListenerDevice&&) = delete;
		
		EventListenerDevice() {}
		virtual ~EventListenerDevice() {}

		inline void RegisterListeningObject(T object_) {
			registeredObjects.push_back(object_);
		}

		inline void RemoveListeningObject(T object_) {
			
			bool isFound = false;
			for (int i = 0; i < registeredObjects.size(); i++) {
				if (registeredObjects[i] == object_) {
					isFound = true;
					registeredObjects[i] = nullptr;
				}
				if (isFound && (i + 1) < registeredObjects.size()) {
					registeredObjects[i] = registeredObjects[i + 1];
				}
			}
			if (isFound) {
				registeredObjects.pop_back();
			}
		}

		inline void ClearAllListeningObjects() {
			
			for (auto obj : registeredObjects) {
				obj = nullptr;
			}
			registeredObjects.clear();
			registeredObjects.shrink_to_fit();

		}

		virtual void Update(SDL_Event e) = 0;

	protected:
		std::vector<T> registeredObjects;
	};

	
}

#endif // !EVENTLISTENERDEVICE_H
