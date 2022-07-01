/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Player_Controller.hpp"

void Game::Player_Controller::handle(const Engine::Message& m)
{
    //Setteamos la accion que le pasa el mensaje
    action = m.info_int;


    if (m.info_bool == true)
    {
        //Comunicamos al controller que  los muros ya no son visibles
        no_walls = true;
        //Cambiamos el sonido  y lo reproducimos
        dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->change_chunk("../assets/CGM3_Quest_Complete_02.wav");
        dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->play_chunk();
    }



}

void Game::Player_Controller::update(float a)
{
    //Switch movemos el jugador

    switch (action)
    {
        case 0: //Arriba
        {
            //Comprueba si hay muro y si el jugador colisiona con el
            if (no_walls == false && entity->get_position().y >= 2.5f)
            {
                dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->play_chunk();
                return;
            }
            

            entity->set_position(entity->get_position()+= glm::vec3{ 0,speed*a,0 });

            action = 10;
            

            break;
        }
        case 1: // Abajo
        {
            //Comprueba si hay muro y si el jugador colisiona con el
            if (no_walls == false && entity->get_position().y <= -2.5f)
            {
                dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->play_chunk();
                return;
            }

            entity->set_position(entity->get_position() += glm::vec3{ 0,-speed * a,0 });

            action = 10;
            break;
        }
        case 2: //Izquierda
        {
            //Comprueba si hay muro y si el jugador colisiona con el
            if (no_walls == false && entity->get_position().x <= -3.75f)
            {
                dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->play_chunk();
                return;
            }

            entity->set_position(entity->get_position() += glm::vec3{ -speed * a,0,0 });

            action = 10;
            break;
        }
        case 3: //Derecha
        {
            //Comprueba si hay muro y si el jugador colisiona con el
            if (no_walls == false && entity->get_position().x >= 3.75f)
            {
                dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->play_chunk();
                return;
            }

            entity->set_position(entity->get_position() += glm::vec3{ speed * a,0,0 });

            action = 10;
            break;
        }
        case 8: //Choque con una pared
        {
            dynamic_cast<Engine::Audio_Component*> (entity->get_component("audio_component"))->play_chunk();

            action = 10;
            break;
        }
    }

    //Check collisions 

    //Number 1
    if (entity->get_position().y >= 1.75f && entity->get_position().x <= -3.25f)
    {
        Engine::Message m;
        m.id = "Number_Observer";
        m.info_int = 1;
        scene->get_message_controller().send(m);

      
    }
    //Number 2
    else if (entity->get_position().y >= 1.75f && entity->get_position().x >= 3.25f)
    {
        Engine::Message m;
        m.id = "Number_Observer";
        m.info_int = 2;
        scene->get_message_controller().send(m);
    }
    //Number 3
    else if (entity->get_position().y <= -1.75f && entity->get_position().x <= -3.25f)
    {
        Engine::Message m;
        m.id = "Number_Observer";
        m.info_int = 3;
        scene->get_message_controller().send(m);
    }
    //Number 4
    else if (entity->get_position().y <= -1.75f && entity->get_position().x >= 3.25f)
    {
        Engine::Message m;
        m.id = "Number_Observer";
        m.info_int = 4;
        scene->get_message_controller().send(m);
    }
    //Number 5
    else if (entity->get_position().y >= 1.75f && entity->get_position().x <= 0.5f && entity->get_position().x >= -0.5f)
    {
        Engine::Message m;
        m.id = "Number_Observer";
        m.info_int = 5;
        scene->get_message_controller().send(m);
    }



}
