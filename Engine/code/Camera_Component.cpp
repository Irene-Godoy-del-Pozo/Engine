/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Camera_Component.hpp"



namespace Engine
{
	Camera_Component::Camera_Component(GameObject* gm) : Component(gm)
	{
		camera.reset ( new Camera);
	}

	Camera_Component::Camera_Component(float fov, float near, float far, float aspect_ratio, GameObject* gm): Component (gm)
	{

		camera.reset(new Camera( fov,  near,  far,  aspect_ratio));
	}
}