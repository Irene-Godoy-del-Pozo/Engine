/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#include <Window.hpp>
#include <Message.hpp>
#include <Scene.hpp>
#include "Input_Task.hpp"
#include <string>

namespace Engine
{
    Input_Task::Input_Task(Scene * s):Task (s) {}


    void Input_Task::run(float)
	{
        Window::Event event;
        while (scene->get_window().poll(event))
        {
        
            switch (event.type)
            {
                case Window::Event::CLOSE:
                {
                     scene->get_kernel().exit= true;
                    break;
                   
                }
                
                case Window::Event::KEY_PRESSED:
                {
                    switch (event.data.keyboard.key_code)
                    {
                        case Keyboard::KEY_W:
                        {

                            Message m;
                            m.id = "PlayerController";
                            m.info_int = 0;
                            scene->get_message_controller().send(m);

                            break;
                        }
                        case Keyboard::KEY_S:
                        {

                            Message m;
                            m.id = "PlayerController";
                            m.info_int = 1;
                            scene->get_message_controller().send(m);
                            break;
                        }
                        case Keyboard::KEY_A:
                        {

                            Message m;
                            m.id = "PlayerController";
                            m.info_int = 2;
                            scene->get_message_controller().send(m);
                            break;
                        }
                        case Keyboard::KEY_D:
                        {

                            Message m;
                            m.id = "PlayerController";
                            m.info_int = 3;
                            scene->get_message_controller().send(m);
                            break;
                        }
                        case Keyboard::KEY_ESCAPE:
                        {
                            scene->get_kernel().exit = true;

                            break;
                        }
                    }

                    break;
                }
            }
        }
	}

}