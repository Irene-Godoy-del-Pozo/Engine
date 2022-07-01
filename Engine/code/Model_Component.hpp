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
#include <Component.hpp>
using namespace std;
using namespace glt;

class Component;
namespace Engine
{
	class Model_Component : public Component
	{
	public:
		/// <summary>
		/// Puntero al modelo
		/// </summary>
		shared_ptr< Model  > model;

		/// <summary>
		/// Constructor 
		/// </summary>
		/// <param name="gm">Objeto al que pertenece</param>
		Model_Component(GameObject& gm);
	};

}