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
#include <Component.hpp>
#include <Controller.hpp>
namespace Engine
{
	/// <summary>
	/// Componente que contiene un controlador 
	/// </summary>
	class Controller_Component : public Component
	{
	public:
		/// <summary>
		/// Referencia al controlador
		/// </summary>
		Controller* controller;

		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="c">Controlador que se quiere vincular al componente</param>
		/// <param name="gm">Objeto que tnedra este componente</param>
		Controller_Component(Controller* c, GameObject* gm);
	};
}