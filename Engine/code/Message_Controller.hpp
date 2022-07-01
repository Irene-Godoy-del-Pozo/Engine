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

#include <string>
#include <map>
#include <any>
#include <list>
#include <Observer.hpp>
#include <Message.hpp>

namespace Engine
{
    /// <summary>
    /// Clase encargada de almacenar los observadores y enviarles mensajes
    /// </summary>
    class Message_Controller
    {
        /// <summary>
        /// Mapa que relaciona los observadores con un string
        /// </summary>
        std::map< std::string, std::list< Observer* > > message_observers;

    public:

        Message_Controller();

        /// <summary>
        /// Añade un observador al mapa
        /// </summary>
        /// <param name="id">Nombre del observador</param>
        /// <param name="observer">Puntero al observador</param>
        void add_observer(std::string id, Observer* observer);

        /// <summary>
        /// Manda mensajes al observador correspondiente
        /// </summary>
        /// <param name="m">Mensaje</param>
        void send(const Message & m);
    
        /// <summary>
        /// Devuelve el mapa de observadores
        /// </summary>
        /// <returns></returns>
        std::map< std::string, std::list< Observer* > >& get_message_observers();

    };
}
