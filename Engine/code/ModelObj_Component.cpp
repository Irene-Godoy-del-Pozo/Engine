/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "ModelObj_Component.hpp"



namespace Engine
{
	ModelObj_Component::ModelObj_Component(std::string rute, GameObject& gm) : Component(&gm)
	{
		
		model_obj.reset(new Model_Obj(rute));
	}
}