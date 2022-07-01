
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


#include <Transform_Component.hpp>



#include <glm.hpp>
#include <map> 
#include <memory>
#include <string>






namespace Engine
{
    class Scene;
    class Component;
    class Transform_Component;

	/// <summary>
	/// Clase Que representa los objetos de la escena
	/// </summary>
	class GameObject
	{
		/// <summary>
		/// Escena a la que pertenece
		/// </summary>
		Scene* parent_scene;

        /// <summary>
        /// Componente de transform. Todos los gameobjects lo tienen
        /// </summary>
        Transform_Component transform_component;

        /// <summary>
        /// Mapa que relaciona cada componente con un nombre
        /// </summary>
        std::map <std::string, Component*> components;

        
    public:

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="scene">Escena a la que pertenece</param>
        /// <param name="t">Posicion</param>
        /// <param name="r">Rotacion</param>
        /// <param name="s">Escala</param>
        GameObject(Scene* scene, glm::vec3 t, glm::vec3 r, glm::vec3 s);

        /// <summary>
        /// Funcion para añadir componentes
        /// </summary>
        /// <param name="">Nombre del componente</param>
        /// <param name="">Puntero al componente</param>
        void add(std::string, Component*);
        
        /// <summary>
        /// Devuelve un puntero al componente por su nombre
        /// </summary>
        /// <param name="">Nombre del componente que se quiere devolver</param>
        /// <returns></returns>
        Component* get_component(std::string);
     
        /// <summary>
        /// Devuelve el componente transform del objeto
        /// </summary>
        /// <returns></returns>
        Transform_Component* get_transform();
     
        /// <summary>
        /// Devuelve el vector 3 de posicion del objeto
        /// </summary>
        /// <returns></returns>
        glm::vec3 get_position();

        /// <summary>
        /// Devuelve la escena a la que pertenece el onjeto
        /// </summary>
        /// <returns></returns>
        Scene* get_parent_scene()
        {
            return parent_scene;
        }

        /// <summary>
        /// Modifica la posicion
        /// </summary>
        /// <param name="new_pos">Nueva posicion</param>
        void set_position(glm::vec3 new_pos)
        {
            transform_component.position = new_pos;
        }

        /// <summary>
        /// Devuelve el vector 3 de rotacion
        /// </summary>
        /// <returns></returns>
        glm::vec3 get_rotation();

        /// <summary>
        /// Modifica la rotacion
        /// </summary>
        /// <param name="new_rot">nueva rotacion</param>
        void set_rotation(glm::vec3 new_rot)
        {
            transform_component.rotation = new_rot;
        }

        /// <summary>
        /// Devuelve la escala del objeto
        /// </summary>
        /// <returns></returns>
        glm::vec3 get_scale();

        /// <summary>
        /// Modifica la escala
        /// </summary>
        /// <param name="new_scale">nueva escala</param>
        void set_scale(glm::vec3 new_scale)
        {
            transform_component.scale = new_scale;
        }
	};
}

