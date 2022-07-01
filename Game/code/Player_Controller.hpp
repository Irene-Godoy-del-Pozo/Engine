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


#include <Scene.hpp>
#include <GameObject.hpp>
#include <Audio_Component.hpp>
#include <Message.hpp>
#include <Controller.hpp>
#include <Observer.hpp>


namespace Game
{

    class Player_Controller : public Engine::Observer , public Engine::Controller
    {
        /// <summary>
        /// Escena a la que pertcnece el observador
        /// </summary>
        Engine::Scene* scene;

        /// <summary>
        /// Velocidad del personaje
        /// </summary>
        float speed;

        /// <summary>
        /// Accion realizando actualmente
        /// </summary>
        int action=10;

        /// <summary>
        /// Comprueba si hay paredes
        /// </summary>
        bool no_walls = false;
    public:
        
        /// <summary>
        /// Constructor
        /// </summary>
        /// <param name="gm">Objeto al que pertenece</param>
        /// <param name="_scene">Escena a la que pertence</param>
        /// <param name="_speed">Velocidad deseada</param>
        Player_Controller(Engine::GameObject* gm, Engine::Scene* _scene,float _speed):Engine::Controller(gm),scene(_scene),speed(_speed) {}

        /// <summary>
        /// Funcion ejecutada cuando recbe un mensaje
        /// </summary>
        /// <param name="m">mensaje recibido</param>
        void handle(const Engine::Message& m);

        /// <summary>
        /// Update del jugador. Actualiza la posicion y variables del objeto 
        /// </summary>
        /// <param name=""></param>
        void update(float);

        /// <summary>
        /// Establece la vewlocidad del jugador
        /// </summary>
        /// <param name="_speed"></param>
        void set_speed(float _speed) { speed = _speed; }



    };
}

