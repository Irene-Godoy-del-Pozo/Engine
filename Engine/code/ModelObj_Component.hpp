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

#include <Model.hpp>
#include <Render_Node.hpp>
#include <Model_Obj.hpp>
#include <Component.hpp>
using namespace std;
using namespace glt;

class Component;
namespace Engine {
	
	class ModelObj_Component : public Component
	{
	public:
		/// <summary>
		/// Puntero al modelo 
		/// </summary>
		shared_ptr< Model  > model_obj;

		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="rute">Ruta del archivo obj </param>
		/// <param name="gm">Objeto al que pertenece</param>
		ModelObj_Component(std::string rute, GameObject& gm);
	};
}

