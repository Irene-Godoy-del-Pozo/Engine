
/*
* Irene Godoy del Pozo
*
* 2021
*
* irenegdp@live.com
*
*
* */

#ifndef SCENE_HPP
#define SCENE_HPP

#include <map>
#include <memory>
#include <string>

#include <Message_Controller.hpp>
#include <Kernel.hpp>
#include <Input_Task.hpp>
#include <Controller_System.hpp>
#include <Render_System.hpp>



namespace glt
{
    class Node;
}


namespace Engine {

  
    class Window;
    class GameObject;
    class Message_Controller;
 
    class Scene
    {
    private:
        /// <summary>
        /// Puntero a la ventana
        /// </summary>
        Window * window;

        /// <summary>
        /// Kernel de la escena
        /// </summary>
        Kernel  kernel ;

        /// <summary>
        /// Lista de objetos de la escena etiquetados por un string
        /// </summary>
        std::map<std::string,std::shared_ptr< GameObject>> gameObjects;
 
        /// <summary>
        /// Tarea de input de esta escena
        /// </summary>
        /// <param name="w"></param>
        Input_Task input_task ;
        /// <summary>
        /// Tarea de los controladores
        /// </summary>
        Controller_System control_system ;
        /// <summary>
        /// Tarea  del renderizado de los modelos
        /// </summary>
        /// <param name="id"></param>
        /// <returns></returns>
        Render_System render_system ;
      
        /// <summary>
        /// Distribuidor de los mensajes de la escena
        /// </summary>
        Message_Controller message_controller ;

    public:
        /// <summary>
        /// Contructor
        /// </summary>
        Scene(Window & w);

        /// <summary>
        /// Llama a la funcion run del kernel
        /// </summary>
        void run();

        /// <summary>
        /// Devuelve la ventana
        /// </summary>
        Window& get_window();

        /// <summary>
        /// Devuelve el distribuidor de mensajes
        /// </summary>
        Message_Controller& get_message_controller(); 
 
        /// <summary>
        /// Devuelve el mapa de objetos
        /// </summary>
        std::map<std::string, std::shared_ptr< GameObject>> & get_gameObjects();

        /// <summary>
        /// Devuelve un puntero al objeto relacionado con el string dado
        /// </summary>
        std::shared_ptr< GameObject> get_gameobject_by_id(std::string id);

        /// <summary>
        /// Puntero al render system de la escena
        /// </summary>
        Render_System* get_render_system();

        /// <summary>
        /// Añade un observador a la escena
        /// </summary>
        void add_observer(const std::string& id, Observer& o);

        /// <summary>
        /// Añade un objeto a la escena
        /// </summary>
        void add_gameobject(const std::string& id, GameObject& o);

        /// <summary>
        /// Añade un model a la lista de renders de la escena
        /// </summary>
        void add_to_render(const std::string& id, std::shared_ptr< glt::Node > o);

        /// <summary>
        /// Devuelve el kernel de la escena
        /// </summary>
        Kernel& get_kernel();

    };
}
#endif
