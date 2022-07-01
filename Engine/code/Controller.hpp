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
	/// <summary>
	/// Clase padre de la que deben heredar todos los controladores 
	/// </summary>
	class Controller
	{
	protected:
		/// <summary>
		/// Puntero al objeto que tiene este controlador
		/// </summary>
		GameObject* entity;
	public:

		/// <summary>
		/// Contructor
		/// </summary>
		/// <param name="_entity">Objeto al que añadimos el controlador</param>
		Controller(GameObject* _entity) :entity(_entity) {};

		/// <summary>
		/// Funcion que sera sobrescrita por sus hijos
		/// </summary>
		/// <param name=""></param>
		virtual void update(float) = 0;

	};

	

}