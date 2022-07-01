/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Kernel.hpp"
#include <Task.hpp>
#include <Input_Task.hpp>
#include <Controller_System.hpp>
#include <Render_System.hpp>
#include <Scene.hpp>
#include <SDL.h>
struct SDL_Window;
typedef void* SDL_GLContext;
namespace Engine 
{
	Kernel::Kernel()
	{
		delta = 0;
		exit = false;

	}
	
	void Kernel::run()
	{
		exit = false;
		delta = 1.f / 60.f; //Estimacion primer fotograma
		
		while (true)
		{ 
			
			for (auto& t : task_list) t->run(delta);
			
		}
	}

	void Kernel::add_task(Task & task)
	{		
		task_list.push_back(&task);
	}
}


