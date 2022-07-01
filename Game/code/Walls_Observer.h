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

#include <GameObject.hpp>
#include <Model_Component.hpp>
#include <Message.hpp>
#include <Observer.hpp>
#include <vector>

namespace Game
{

    class Walls_Observer : public Engine::Observer
    {
        /// <summary>
        /// Escena al que pertence
        /// </summary>
        Engine::Scene* scene;

        /// <summary>
        /// Vector de objetos a los que observa
        /// </summary>
        std::vector< Engine::GameObject* > walls;


    public:

        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="_walls">Vector de objetos </param>
        /// <param name="_scene">Escena a la que pertenece</param>
        Walls_Observer(std::vector< Engine::GameObject* > _walls, Engine::Scene* _scene):walls(_walls),scene(_scene) {};

        /// <summary>
        /// Funcion ejecutada cuando recive un mensaje
        /// </summary>
        /// <param name="m">Mensaje recibido</param>
        void handle(const Engine::Message& m)
        {
       
            //Devolvemos la visibilidad a cada numero
            for (int i = 0; i < walls.size(); i++)
            {
                dynamic_cast<Engine::Model_Component*> (walls[i]->get_component("modelo"))->model->set_visible(false);
            }
            
            //Mandamos un mensaje al jugador para que ejecute el sonido de error
            Engine::Message _m;
            _m.id = "PlayerController";
            _m.info_bool = true;

            scene->get_message_controller().send(_m);

        }


    };
}