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

#include <string>
#include <map>
#include <any>

namespace Engine
{
	struct Message
	{
		/// <summary>
		/// Observador al que va dirigido
		/// </summary>
		std::string id; 


		int info_int = -1;
		bool info_bool = false;

	};

}