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



#include <Light.hpp>
#include <Render_Node.hpp>
#include <Component.hpp>
#include <GameObject.hpp>
using namespace std;
using namespace glt;

namespace Engine
{
	/// <summary>
	/// Contiene el componente de luz
	/// </summary>
	class Light_Component : public Component
	{		
	public:
		/// <summary>
		/// Luz
		/// </summary>
		shared_ptr < Light  > light;

		Light_Component(GameObject & gm);
	};

}