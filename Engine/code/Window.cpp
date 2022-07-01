/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */



#include "Window.hpp"
#include <SDL.h>
#include <SDL_mixer.h>
#include <OpenGL.hpp>
#include <string>
#include <cassert>



namespace Engine {


	Window::Window(const std::string & title, int width, int height, bool fullscreen)
	{
		window = nullptr;
		gl_context = nullptr;

		
		if (SDL_Init(SDL_INIT_VIDEO) < 0) 
			SDL_Log("No se pudo inicializar SDL2");		
		else 
		{
			// Determinamos las caracteristicas de la ventana antes de crearla :
			//Máxima version del contexto de OpenGL
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
			//Mínima version del contexto de OpenGL
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

			window = SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);



			//Comprobamos que se ha podido hacer la ventana
			if (!window)
				SDL_Log("No se pudo crear la ventana");
			else
			{
				//Creamos el contexto 
				gl_context = SDL_GL_CreateContext(window);

				//Comprobamos que  hemos podido crearlo
				if (gl_context)
				{
					if (gl_context && glt::initialize_opengl_extensions())
					{

						FullScreen(window, fullscreen);
					}
				}
				else
					SDL_Log("No se pudo crear el contexto de OpenGL");
			}
		}
		//Si no se puede iniciar el audio
		if (SDL_Init(SDL_INIT_AUDIO) < 0) 
			SDL_Log("No se pudo inicializar SDL audio");
		else
		{
			
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096))
				SDL_Log("Failed to Initizlie SDL Mixer");
				
			
		}

	}
	

	Window::~Window()
	{
		if (gl_context) SDL_GL_DeleteContext(gl_context);
		if (window) SDL_DestroyWindow(window);
	}


	void Window::FullScreen(SDL_Window * window, bool full)
	{
		if (full == true)
			SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
		else
			SDL_SetWindowFullscreen(window, 0);
	}



	unsigned Window::get_width() const
	{
		int width = 0, height;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(width);
	}

	unsigned Window::get_height() const
	{
		int width, height = 0;

		if (window) SDL_GetWindowSize(window, &width, &height);

		return unsigned(height);
	}

	bool Window::poll(Event& event) const
	{
		if (window)     
		{
			// Se extrae un evento usando SDL y se convierte a un evento propio de
			// nuestro engine:

			SDL_Event sdl_event;

			if (SDL_PollEvent(&sdl_event) > 0)
			{
				switch (sdl_event.type)
				{
					case SDL_QUIT:
					{
						event.type = Event::CLOSE;
						break;
					}

					case SDL_KEYDOWN:
					{
						event.type = Event::KEY_PRESSED;
						event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
						break;
					}

					case SDL_KEYUP:
					{
						event.type = Event::KEY_RELEASED;
						event.data.keyboard.key_code = Keyboard::translate_sdl_key_code(sdl_event.key.keysym.sym);
						break;
					}
				}

				return true;
			}
		}

		return false;
	}


	void Window::enable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(1);
	}

	void Window::disable_vsync()
	{
		if (gl_context) SDL_GL_SetSwapInterval(0);
	}

	void Window::clear() const
	{
		if (gl_context) glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::swap_buffers() const
	{
		if (gl_context) SDL_GL_SwapWindow(window);
	}


}