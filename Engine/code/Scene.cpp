/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include <Window.hpp>

#include <GameObject.hpp>
#include <ModelObj_Component.hpp>
#include <Camera_Component.hpp>
#include <Light_Component.hpp>
#include <Node.hpp>
#include "Scene.hpp"


using namespace glt;

namespace Engine
{
	
	Scene::Scene(Window &w):
		input_task (this),
		control_system  (this),
		render_system (this)
	{
		window = &w;

		

		//Añadimos las tareas al kernel
		kernel.add_task(input_task);
		kernel.add_task(control_system);
		kernel.add_task(render_system);
			
	}

	Window& Scene::get_window()
	{
		return *window;
	}

	Message_Controller& Scene::get_message_controller()
	{
		return message_controller;

	}

	std::map<std::string, std::shared_ptr<GameObject>>& Scene::get_gameObjects()
	{

		return gameObjects;

	}

	std::shared_ptr<GameObject> Scene::get_gameobject_by_id(std::string id)
	{
		if (gameObjects.find(id) != gameObjects.end())
			return gameObjects.find(id)->second;
		else
			return nullptr;
	}

	Render_System* Scene::get_render_system()
	{
		return &render_system;
	}

	void Scene::run()
	{
		
		kernel.run();
		
	}
	void Scene::add_observer(const std::string& id, Observer& o)
	{
		message_controller.add_observer(id, &o);
	}

	void Scene::add_gameobject(const std::string& id, GameObject& o)
	{
		gameObjects.insert(std::pair< std::string, std::shared_ptr< GameObject>>(id, &o));
	}

	void Scene::add_to_render(const std::string& id, std::shared_ptr< glt::Node > o)
	{
		render_system.render_node->add(id, o);
	}


	Kernel& Scene::get_kernel()
	{
		return kernel;
	}

	
}