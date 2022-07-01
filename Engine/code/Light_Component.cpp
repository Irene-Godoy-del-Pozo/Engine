/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Light_Component.hpp"



namespace Engine
{
	
	Light_Component::Light_Component(GameObject & gm):Component (&gm)
	{
		 light.reset( new Light);
	}
}