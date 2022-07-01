/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Transform_Component.hpp"


namespace Engine
{
    Transform_Component::Transform_Component(GameObject* gm, glm::vec3 t, glm::vec3 r, glm::vec3 s):Component(gm)
    {
        position = t;
        rotation = r;
        scale    = s;
    }
    Transform_Component::Transform_Component(GameObject* gm):Component(gm)
    {
    }
    Transform_Component& Transform_Component::operator=(const Transform_Component& other)
    {
        this->position = other.position;
        this->rotation = other.rotation;
        this->scale = other.scale;

        return *this;
    }
    Transform_Component::~Transform_Component()
    {
    }
    glm::mat4 Transform_Component::get_transform() const
    {
        //http://www.opengl-tutorial.org/es/beginners-tutorials/tutorial-3-matrices/
        glm::mat4 matrix_position = glm::translate(glm::mat4(),position);
        glm::mat4 matrix_rotation = glm:: rotate (glm::mat4(),0.f, rotation);
        glm::mat4 matrix_scale = glm::scale(glm::mat4(), scale);
        glm::mat4 matrix_transformation = matrix_position * matrix_rotation * matrix_scale;
        return matrix_transformation;
    }
}