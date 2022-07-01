/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Controller_System.hpp"
#include <GameObject.hpp>
#include <Controller_Component.hpp>
#include <Scene.hpp>

namespace Engine
{
	Controller_System::Controller_System(Scene* s) :Task(s)
	{
	}
	void Controller_System::run(float delta)
	{

		for (auto & item : Task::scene->get_gameObjects())
		{

			GameObject*  gameObject = item.second.get();
			Component* component = gameObject->get_component("controller_component");

			if (component)
			{
				dynamic_cast<Controller_Component*> (component)->controller->update(delta);
			}
		}

		
	}
}
