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

#include <glm.hpp>
#include <Render_Node.hpp>
#include <Component.hpp>
#include <GameObject.hpp>
using namespace std;
using namespace glt;

namespace Engine
{
	/// <summary>
	/// Clase que contiene la camara
	/// </summary>
	class Camera_Component : public Component
	{
	public:
		/// <summary>
		/// Referencia a la clase Camara
		/// </summary>
		shared_ptr< Camera > camera;
	public:
		/// <summary>
		/// Contructor simple
		/// </summary>
		/// <param name="gm">Objeto al que es añadido</param>
		Camera_Component(GameObject* gm);

		/// <summary>
		/// Contructor 
		/// </summary>
		/// <param name="fov">Campo de vision</param>
		/// <param name="near">Distancia minima</param>
		/// <param name="far">Distancia maxima</param>
		/// <param name="aspect_ratio"></param>
		/// <param name="gm">Objeto al que es añadido</param>
		Camera_Component(float fov, float near, float far, float aspect_ratio, GameObject* gm);
	};
}


