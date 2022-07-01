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


#include <Message.hpp>
namespace Engine
{
	class Observer
	{
	public :
		/// <summary>
		/// Funcion hederada y llamada desde el message controller
		/// </summary>
		/// <param name="">mensaje a enviar</param>
		virtual void handle(const Message &) = 0;
	};

}