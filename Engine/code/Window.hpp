/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#ifndef WINDOW_EXERCISE
#define WINDOW_EXERCISE


#include <string>
#include <Keyboard.hpp>

struct SDL_Window;
typedef void* SDL_GLContext;
namespace glt
{

    class Render_Node;

}

namespace Engine {
	
	class Window
	{
	private:

		/// <summary>
		/// Puntero a la clase window de SDL
		/// </summary>
		SDL_Window* window;

        /// <summary>
        /// Contexto de SDL
        /// </summary>
        SDL_GLContext gl_context;

	public:

        //Sistema de eventos para registrar acciones del usuario
        struct Event
        {
            enum Type
            {
                CLOSE,
                KEY_PRESSED,
                KEY_RELEASED
            };
            Type type;

            union Data
            {
                struct 
                {
                    int key_code;
                }
                keyboard;

                struct
                {
                    float x, y;
                    int   buttons;
                }
                mouse;
            };
            Data data;
        };


		Window(const std::string & title, int weith, int height, bool fullscreen = false);

		~Window();



		void FullScreen(SDL_Window * window, bool full);

        /// <summary>
        /// Devuelve el ancho de la ventana
        /// </summary>
        /// <returns></returns>
        unsigned get_width() const;

        /// <summary>
        ///  Devuelve el alto de la ventana
        /// </summary>
        /// <returns></returns>
        unsigned get_height() const;

        /// <summary>
        /// Coge un evento de las lista de eventos Events
        /// </summary>
        /// <param name="event"></param>
        /// <returns></returns>
        bool poll(Event& event) const;

        /// <summary>
        /// Habilita la sincronizacion vertical
        /// </summary>
        void enable_vsync();

        /// <summary>
        /// Deshabilita la sincronizacion vertical
        /// </summary>
        void disable_vsync();

        /// <summary>
        /// Borra el buffer
        /// </summary>
        void clear() const;

        /// <summary>
        /// Intercambia el buffer actual con el oculto
        /// </summary>
        void swap_buffers() const;

	};

}



#endif 


