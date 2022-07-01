
/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#pragma once

#include <Task.hpp>
#include <iostream>
typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;



namespace glt
{

	class Render_Node;

}

namespace Engine
{
	class Scene;
	class GameObject;
	class ModelObj_Component;
	class Transform_Component;

	class Render_System : public Task
	{
		
	public:
		/// <summary>
		/// Puntero al Render node
		/// </summary>
		std::unique_ptr< glt::Render_Node >render_node = nullptr;

		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="s"> Escena a la que pertenece</param>
		Render_System(Scene* s);
		~Render_System();

		/// <summary>
		/// Funcion que actualiza los renders de cada modelo
		/// </summary>
		/// <param name="delta"></param>
		void run(float delta) override;
	};
}


