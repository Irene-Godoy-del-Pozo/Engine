/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include "Message_Controller.hpp"


namespace Engine
{
    Message_Controller::Message_Controller()
    {
    }
    void Message_Controller::add_observer(std::string id, Observer* observer)
    {
        message_observers[id].push_back(observer);
    }
    void Message_Controller::send(const Message& m)
    {
        //Comprueba si el id existe
        auto list = message_observers.find(m.id);

        //Si existe le manda el mensaje a ese observador
        if (list != message_observers.end())
        {
            for (auto& o : list->second) 
                o->handle(m);
        }

      
    }
    std::map<std::string, std::list<Observer*>>& Message_Controller::get_message_observers()
    {
        return message_observers;
    }
}