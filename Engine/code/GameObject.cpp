/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "GameObject.hpp"
#include <Scene.hpp>
#include <Transform_Component.hpp>

namespace Engine
{
	GameObject::GameObject(Scene* scene, glm::vec3 t, glm::vec3 r, glm::vec3 s):
		transform_component(this,t,r,s) 
	{
		parent_scene = scene;		
	}
	void GameObject::add(std::string id, Component* component)
	{
		components.insert(std::pair<std::string, Component*>(id,component));
	}

	Component* GameObject::get_component(std::string id)
	{
		//Si la key esta en el map devolvemos el objeto
		if (components.find(id) != components.end())
			return components.find(id)->second ;

		return nullptr;
	}

	

	Transform_Component* GameObject::get_transform()
	{
		return &transform_component;
	}

	glm::vec3 GameObject::get_position()
	{
		return transform_component.position;
	}

	glm::vec3 GameObject::get_rotation()
	{
		return transform_component.rotation;
	}

	glm::vec3 GameObject::get_scale()
	{
		return transform_component.scale;
	}

}