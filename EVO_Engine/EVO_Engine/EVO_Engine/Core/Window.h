#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <glew.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "EngineSystem.h"

namespace EVO_ENGINE {

	class Window : public EngineSystem {
	public:
		Window();
		~Window();

		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) = delete;

		virtual bool Initialize();
		bool Initialize(std::string windowName_);
		virtual void Update();
		virtual void Shutdown();

		//Setters
		void SetWindowSize(const int width_, const int height_);
		void ToggleFullScreen();

		//Getters
		inline int GetWidth() const { return windowBounds.w; }
		inline int GetHeight() const { return windowBounds.h; }
		inline SDL_Window* GetWindow() const { return SDLWindow; }
		inline SDL_Rect GetWindowBounds() const { return windowBounds; }

	private:
		void InitializeAttributes();
		void InitializeEnables();
		SDL_Window* SDLWindow;
		SDL_GLContext SDL_GLContext;
		SDL_Rect windowBounds;
		bool isInitialized;
		bool isFullScreen;
	};
}

#endif // !WINDOW_H
