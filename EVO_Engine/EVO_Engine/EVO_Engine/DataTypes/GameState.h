#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <memory>

namespace EVO_ENGINE {
	
	class GameState{
	public:

		GameState(const GameState&) = delete;
		GameState(GameState&&) = delete;
		GameState& operator=(const GameState&) = delete;
		GameState& operator=(GameState&&) = delete;

		//Getters
		static GameState* GetInstance();

		inline bool IsRunning() { return isRunning; }
		inline bool IsPaused() { return isPaused; }
		inline short GetFPS() { return fps; }
		inline int GetWindowWidth() { return windowWidth; }
		inline int GetWindowHeight() { return windowHeight; }
		//Setters
		inline void SetRunning(bool running_) { isRunning = running_; }
		inline void SetPaused(bool paused_) { isPaused = paused_; }
		inline void SetFPS(short fps_) { fps = fps_; }
		inline void SetWindowSize(int width_, int height_) { windowWidth = width_; windowHeight = height_; }

	protected:
		GameState();
		~GameState();

		static std::unique_ptr<GameState> gameStateInstance;
		friend std::default_delete<GameState>;

		bool isRunning;
		bool isPaused;
		short fps;
		int windowWidth;
		int windowHeight;
	};
}

#endif // !GAMESTATE_H
