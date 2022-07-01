
/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */
#include "Controller_Component.hpp"

 

Engine::Controller_Component::Controller_Component(Controller* c, GameObject* gm) :Component(gm)
{
	controller = c;
}
