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


class Task;
class Scene;
namespace Engine
{

	class Controller_Component;

	/// <summary>
	/// Tarea que se encarga de gestionar los controladores
	/// </summary>
	class Controller_System : public Task
	{
	public:
		/// <summary>
		/// Contructor 
		/// </summary>
		/// <param name="s">Escena a la que pertenece</param>
		Controller_System(Scene* s);

		/// <summary>
		/// Funcion que llama a todos los updates 
		/// </summary>
		/// <param name="delta"></param>
		void run(float delta) override;
	};

}

