/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include <Scene.hpp>
#include <Window.hpp>
#include <GameObject.hpp>
#include <Model_Component.hpp>
#include <ModelObj_Component.hpp>
#include <Transform_Component.hpp>
#include <Camera_Component.hpp>
#include <Light_Component.hpp>
#include <Render_Node.hpp>
#include "Render_System.hpp"

using namespace std;
using namespace glt;

namespace Engine
{
	Render_System::Render_System(Scene* s):Task(s)
	{
		render_node.reset(new Render_Node);
		

	}
	Render_System::~Render_System() {}

	void Render_System::run(float delta)
	{
		render_node->get_active_camera()->set_aspect_ratio((float)scene->get_window().get_width() / (float)scene->get_window().get_height());

		glViewport(0, 0, scene->get_window().get_width(), scene->get_window().get_height());

		// Se ajusta el viewport por si el tamaño de la ventana ha cambiado:
		GLsizei width = GLsizei(scene->get_window().get_width());
		GLsizei height = GLsizei(scene->get_window().get_height());

		auto c = render_node->get_active_camera();
		c->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		for (auto& item : scene->get_gameObjects())
		{

			GameObject * gameObject = item.second.get();
			Component* component = gameObject->get_component("modelo"); 

			
			if (component && dynamic_cast<ModelObj_Component*> (component) )
			{
				dynamic_cast<ModelObj_Component*> (component)->model_obj->set_transformation(gameObject->get_transform()->get_transform());
				dynamic_cast<ModelObj_Component*> (component)->model_obj->rotate_around_x(gameObject->get_rotation().x);

			
			}

			
		}

		scene->get_window().clear();

		render_node->render();
		scene->get_window().swap_buffers();
		

	}

}
