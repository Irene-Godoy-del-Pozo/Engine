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




#include <list>


namespace Engine {
	class Task;
	class Scene;

	class Kernel
	{

	public:
		/// <summary>
		/// Lista de tareas
		/// </summary>
		std::list <Task*> task_list;

		bool exit;
		float delta;

	public:

		Kernel();
		
		/// <summary>
		/// Ejecuta por orden la funcion run de las tareas de la lista
		/// </summary>
		void run();		

		/// <summary>
		/// A�ade tareas a la lista de tareas
		/// </summary>
		/// <param name="task">Tarea a a�adir</param>
		void add_task(Task& task);

	};

}