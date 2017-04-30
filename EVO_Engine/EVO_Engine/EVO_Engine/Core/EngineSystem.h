#ifndef ENGINESYSTEM_H
#define ENGINESYSTEM_H

namespace EVO_ENGINE {

	class EngineSystem {
	public:
		EngineSystem() {}
		virtual ~EngineSystem() {}

		virtual bool Initialize() = 0;
		virtual void Shutdown() = 0;

	};
}
#endif // !ENGINESYSTEM_H
