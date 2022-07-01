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
	/// <summary>
	/// Tarea que gestiona la recepcion de input del jugador
	/// </summary>
	class Input_Task : public Task 
	{
	public:

		Input_Task(Scene* s);
		void run(float) override;
        
	};

}


