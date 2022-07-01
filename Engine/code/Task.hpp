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



namespace Engine 
{
	class Scene;

	/// <summary>
	/// Clase padre para todas las tareas 
	/// </summary>
	class Task
	{
		protected:
			/// <summary>
			/// Puntero a la escena a la que pertenece
			/// </summary>
			Scene* scene;
		public:
			Task(Scene* s);
			virtual ~Task() = default;
			virtual void run(float delta) = 0;
	};
}


