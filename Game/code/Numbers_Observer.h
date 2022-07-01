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
#include <Observer.hpp>
#include <ModelObj_Component.hpp>
#include <vector>

namespace Game
{

    class Number_Observer : public Engine::Observer
    {
        /// <summary>
        /// Escena a la que pertenece
        /// </summary>
        Engine::Scene* scene;

        /// <summary>
        /// Vector de objetos a los que observa
        /// </summary>
        std::vector< Engine::GameObject* > numbers;

        /// <summary>
        /// Lleva la cuenta de la recogida de numeros
        /// </summary>
        int current_position = 0;
       
    public:
       
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="_numbers">Numeros a los que observa</param>
        /// <param name="_scene">Escena a la que pertence</param>
        Number_Observer(std::vector< Engine::GameObject* > _numbers,Engine::Scene* _scene):numbers(_numbers),scene (_scene) {};

        /// <summary>
        /// Funcion ejecutada al recibir un mensaje
        /// </summary>
        /// <param name="m">Mensaje recibido</param>
        void handle(const Engine::Message& m)
        {
            //Si ya se han recogido todos los numeros no sigue la funcion 
            if (current_position >= 5) return;

            //Si el numero colisionado es el siguiente en la lista a recoger 
            if (m.info_int == current_position + 1) 
            {
                //Sonido de acierto 
                dynamic_cast<Engine::Audio_Component*> (numbers[current_position]->get_component("audio_component"))->play_chunk();

                //Hacemos invisible el numero
                Engine::ModelObj_Component* component = dynamic_cast<Engine::ModelObj_Component*> (numbers[current_position]->get_component("modelo"));
                component->model_obj->set_visible(false);

                //actualizamos la variable
                current_position = m.info_int;


                
                //Si ya hemos cogido todos los números quitamos las paredes
                if (current_position == 5)
                {
                    Engine::Message wall_m;
                    wall_m.id = "Walls_Observer";
                    scene->get_message_controller().send(wall_m);
                }

            }
            //Comprueba si es mayor que el numero actual  recogido
            else if (m.info_int > current_position)
            {

                //Reseteamos el numero a tocar
                current_position = 0;

                //Devolvemos la visibilidad a cada numero
                for (int i = 0; i < numbers.size(); i++)
                {
                    dynamic_cast<Engine::ModelObj_Component*> (numbers[i]->get_component("modelo"))->model_obj->set_visible(true);
                }

                //Mandamos mensaje al jugador para que reproduzca el sonido
                Engine::Message player_m;
                player_m.id = "PlayerController";
                player_m.info_int = 8;
                scene->get_message_controller().send(player_m);

            }

            
        }


    };
}