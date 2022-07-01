/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Component.hpp"



namespace Engine
{
    
    Component::Component(GameObject* gm)
    {
        this->parent_gameObject = gm;
    }
}