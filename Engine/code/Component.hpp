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
	class GameObject;

	/// <summary>
	/// Clase padre de la que deben heredar todos los componentes 
	/// </summary>
	class Component
	{
	protected:
		
		/// <summary>
		/// Puntero al objeto que tiene este controlador
		/// </summary>
		GameObject* parent_gameObject;
	public:

		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="gm">Objeto añadido</param>
		Component(GameObject* gm);
		virtual ~Component() = default;
		
	};

}

