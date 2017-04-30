#ifndef EVOENGINE_H
#define EVOENGINE_H

#include <memory>

#include "Core\Window.h"
#include "DataTypes\GameState.h"

namespace EVO_ENGINE {
	
	class EVOEngine {
	public:
		EVOEngine(const EVOEngine&) = delete;
		EVOEngine(EVOEngine&&) = delete;
		EVOEngine& operator=(const EVOEngine&) = delete;
		EVOEngine& operator=(EVOEngine&&) = delete;

		static EVOEngine* GetInstance();

		virtual bool Initialize();
		virtual void Shutdown();
		void Run();

		static Window windowInstance;

	private:
		EVOEngine();
		~EVOEngine();

		static std::unique_ptr<EVOEngine> engineInstance;
		friend std::default_delete<EVOEngine>;

		void Update(const float deltaTime);
		void Render();
		
	};
}

#endif // !EVOENGINE_H
