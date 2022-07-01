

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

#include <Component.hpp>
#include <OpenGL.hpp>
#include <glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Engine
{


	class Transform_Component: public Component
	{
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="gm">Objeto al que se añade</param>
		/// <param name="t">posicion</param>
		/// <param name="r">rotacion</param>
		/// <param name="s">escala</param>
		Transform_Component(GameObject* gm, glm::vec3 t, glm::vec3 r, glm::vec3 s);
	    Transform_Component(GameObject* gm);

		/// <summary>
		/// Sobrecarga del operador =
		/// </summary>
		/// <param name="other"> componente al que se quiere igualar</param>
		/// <returns></returns>
		Transform_Component& operator=(const Transform_Component& other);

		~Transform_Component() ;

		/// <summary>
		/// Devuelve la posicion
		/// </summary>
		glm::vec3 position ;

		/// <summary>
		/// Devuelve la rotacion
		/// </summary>
		glm::vec3 rotation;  

		/// <summary>
		/// Devuelve la escala
		/// </summary>
		glm::vec3 scale;

		/// <summary>
		/// Devuelve la matriz de transformacion
		/// </summary>
		/// <returns></returns>
		glm::mat4 get_transform () const;
		

	};
}

