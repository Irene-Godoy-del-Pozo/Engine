/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Model_Component.hpp"


#include <Cube.hpp>

namespace Engine
{
	Model_Component::Model_Component(GameObject& gm): Component (&gm)
	{
		model.reset(new Model);
		model->add(shared_ptr< Drawable >(new Cube), Material::default_material());
	}
}