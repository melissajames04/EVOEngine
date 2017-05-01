#include "Window.h"

using namespace EVO_ENGINE;

Window::Window()
	: SDLWindow(nullptr), SDL_GLContext(0), windowBounds(SDL_Rect()), isInitialized(false), isFullScreen(false) {

}

Window::~Window() {
	//Shutdown();
}

void Window::Shutdown() {

	if (SDL_GLContext != 0) {
		SDL_GL_DeleteContext(SDL_GLContext);
	}

	SDL_DestroyWindow(SDLWindow);
	SDLWindow = nullptr;

	isInitialized = false;
}


bool Window::Initialize() {
	return Initialize("");
}
bool Window::Initialize(std::string windowName_) {

	isInitialized = false;

	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		return isInitialized;
	}

	SDLWindow = SDL_CreateWindow(windowName_.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowBounds.w, windowBounds.h, SDL_WINDOW_OPENGL);

	if (!SDLWindow) {
		Shutdown();
		return isInitialized;
	}

	SDL_GLContext = SDL_GL_CreateContext(SDLWindow);

	InitializeAttributes();

	SDL_GL_SetSwapInterval(1);

	glewExperimental = GL_TRUE;

	GLenum err = glewInit();
	if (err != GLEW_OK) {
		Shutdown();
		return isInitialized;
	}

	InitializeEnables();

	isInitialized = true;

	return isInitialized;

}


void Window::InitializeAttributes() {
	
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

}

void Window::InitializeEnables() {
	
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_2D);

}

void Window::Update() {

	SDL_GL_SwapWindow(SDLWindow);
}

void Window::SetWindowSize(const int width_, const int height_) {

	windowBounds.w = width_;
	windowBounds.h = height_;

}

void Window::ToggleFullScreen() {
	
	isFullScreen = !isFullScreen;
	SDL_SetWindowFullscreen(SDLWindow, (isFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));

}



