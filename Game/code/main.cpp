
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
#include <Scene.hpp>
#include <Player_Controller.hpp>

#include <GameObject.hpp>
#include <Model_Component.hpp>
#include <ModelObj_Component.hpp>
#include <Camera_Component.hpp>
#include <Light_Component.hpp>
#include <Controller_Component.hpp>
#include <Audio_Component.hpp>
#include "Numbers_Observer.h"
#include "Walls_Observer.h"


bool _Aexit;

int main()
{

	//Creamos la ventana y la escena
	Engine::Window win("Game", 1024, 720);
	win.enable_vsync();
	
	Engine::Scene scene(win);

	//Vectores que almacenan los numeros de la escena y las paredes
	std::vector<Engine::GameObject* > scene_numbers;
	std::vector<Engine::GameObject* > scene_walls;


	//Gameobject camara
	Engine::GameObject camera_gameobject(&scene, glm::vec3(0, 0, 5), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	scene.add_gameobject("camera_gameobject", camera_gameobject);

	//Component Camara
	Engine::Camera_Component camera_component(20.f, 1.f, 10.f, 1.f, scene.get_gameobject_by_id("camera_gameobject").get());
	scene.get_gameobject_by_id("camera_gameobject")->add("camera", &camera_component);

	//Actualizamos la posicion de la camara(component) con la del gameobject
	camera_component.camera->translate(camera_gameobject.get_transform()->position);


	//GameObject Luz
	Engine::GameObject light_gameobject(&scene, glm::vec3(10, 50, 10), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
	scene.add_gameobject("light_gameobject", light_gameobject);

	//Component Luz
	Engine::Light_Component light_component(*scene.get_gameobject_by_id("light_gameobject"));
	scene.get_gameobject_by_id("light_gameobject")->add("light", &light_component);

	//Actualizamos la posicion de la luz(component) con la del gameobject
	light_component.light->translate(light_gameobject.get_transform()->position);

	#pragma region Player

	// Creamos el GameObject del jugador y lo añadimos a la escena
	Engine::GameObject player(&scene,  glm::vec3(0.1f,0, 0), glm::vec3(0.01f, 0, 0), glm::vec3(0.25f, 0.25f, 0.25f));
	scene.add_gameobject("player_gameobject", player);

	//Creamos el componente ModeloObj para que se vea al jugador y lo añadimos al jugador
	Engine::ModelObj_Component player_model("../assets/stanford-bunny.obj", *scene.get_gameobject_by_id("player_gameobject"));
	scene.get_gameobject_by_id("player_gameobject")->add("modelo", &player_model);

	//Se crea el controlador y observador del personaje
	Game::Player_Controller player_controller(&player, &scene,4.f);

	//Añadimos el observador a la escena
	scene.add_observer("PlayerController", player_controller);

	//Creamos el componente Controller para controlar al jugador y lo añadimos al jugador
	Engine::Controller* aux = static_cast<Engine::Controller*>(&player_controller);

	Engine::Controller_Component controller(aux, &player);

	scene.get_gameobject_by_id("player_gameobject")->add("controller_component", &controller);

	//Creamos el componente Audio para que el jugador reproduzca sonidos y lo añadimos al jugador
	Engine::Audio_Component player_audio(&player, "../assets/CGM3_Error_Button_05_2.wav",4);
	scene.get_gameobject_by_id("player_gameobject")->add("audio_component", &player_audio);


	//Actualizamos la posicion del modelo (component) con la del jugador (gameobject)
	player_model.model_obj->translate(player.get_transform()->position);

#pragma endregion

	#pragma region Numbers

	//				Numero 1
	Engine::GameObject number1(&scene, glm::vec3(-3.75, 2.f, 0), glm::vec3(-1.5f, 0, 0), glm::vec3(0.05f, 0.05f, 0.05f));
	scene.add_gameobject("number1_gameobject", number1);

	//Component ModeloObj
	Engine::ModelObj_Component number1_model("../assets/Number_1.obj", *scene.get_gameobject_by_id("number1_gameobject"));
	scene.get_gameobject_by_id("number1_gameobject")->add("modelo", &number1_model);

	//Audio Component
	Engine::Audio_Component number1_audio(&number1, "../assets/FA_Special_Item_2_2.wav", 10);
	scene.get_gameobject_by_id("number1_gameobject")->add("audio_component", &number1_audio);

	//Actualizamos la posicion y rotacion del modelo (component) con la del gameobject
	number1_model.model_obj->translate(number1.get_transform()->position);
	number1_model.model_obj->rotate_around_x(number1.get_transform()->rotation.x);

	//Lo añadimos a la lista de numeros de la escena
	scene_numbers.push_back(&number1);

	//				Numero 2
	Engine::GameObject number2(&scene, glm::vec3(3.75, 2.f, 0), glm::vec3(-1.5f, 0, 0), glm::vec3(0.05f, 0.05f, 0.05f));
	scene.add_gameobject("number2_gameobject", number2);

	//Component ModeloObj
	Engine::ModelObj_Component number2_model("../assets/Number_2.obj", *scene.get_gameobject_by_id("number2_gameobject"));
	scene.get_gameobject_by_id("number2_gameobject")->add("modelo", &number2_model);

	//Audio Component
	Engine::Audio_Component number2_audio(&number2, "../assets/FA_Special_Item_2_2.wav", 10);
	scene.get_gameobject_by_id("number2_gameobject")->add("audio_component", &number2_audio);

	//Actualizamos la posicion y rotacion del modelo (component) con la del gameobject
	number2_model.model_obj->translate(number2.get_transform()->position);
	number2_model.model_obj->rotate_around_x(number2.get_transform()->rotation.x);

	//Lo añadimos a la lista de numeros de la escena
	scene_numbers.push_back(&number2);

	//				Numero 3
	Engine::GameObject number3(&scene, glm::vec3(-3.75, -2.5f, 0), glm::vec3(-1.5f, 0, 0), glm::vec3(0.05f, 0.05f, 0.05f));
	scene.add_gameobject("number3_gameobject", number3);

	//Component ModeloObj
	Engine::ModelObj_Component number3_model("../assets/Number_3.obj", *scene.get_gameobject_by_id("number3_gameobject"));
	scene.get_gameobject_by_id("number3_gameobject")->add("modelo", &number3_model);

	//Audio Component
	Engine::Audio_Component number3_audio(&number3, "../assets/FA_Special_Item_2_2.wav", 10);
	scene.get_gameobject_by_id("number3_gameobject")->add("audio_component", &number3_audio);

	//Actualizamos la posicion y rotacion del modelo (component) con la del gameobject
	number3_model.model_obj->translate(number3.get_transform()->position);
	number3_model.model_obj->rotate_around_x(number3.get_transform()->rotation.x);

	//Lo añadimos a la lista de numeros de la escena
	scene_numbers.push_back(&number3);

	//				Numero 4
	Engine::GameObject number4(&scene, glm::vec3(3.75, -2.5f, 0), glm::vec3(-1.5f, 0, 0), glm::vec3(0.05f, 0.05f, 0.05f));
	scene.add_gameobject("number4_gameobject", number4);

	//Component ModeloObj
	Engine::ModelObj_Component number4_model("../assets/Number_4.obj", *scene.get_gameobject_by_id("number4_gameobject"));
	scene.get_gameobject_by_id("number4_gameobject")->add("modelo", &number4_model);

	//Audio Component
	Engine::Audio_Component number4_audio(&number4, "../assets/FA_Special_Item_2_2.wav", 10);
	scene.get_gameobject_by_id("number4_gameobject")->add("audio_component", &number4_audio);

	//Actualizamos la posicion y rotacion del modelo (component) con la del gameobject
	number4_model.model_obj->translate(number4.get_transform()->position);
	number4_model.model_obj->rotate_around_x(number4.get_transform()->rotation.x);

	//Lo añadimos a la lista de numeros de la escena
	scene_numbers.push_back(&number4);

	//				Numero 5
	Engine::GameObject number5(&scene, glm::vec3(0, 2.f, 0), glm::vec3(-1.5f, 0, 0), glm::vec3(0.05f, 0.05f, 0.05f));
	scene.add_gameobject("number5_gameobject", number5);

	//Component ModeloObj
	Engine::ModelObj_Component number5_model("../assets/Number_5.obj", *scene.get_gameobject_by_id("number5_gameobject"));
	scene.get_gameobject_by_id("number5_gameobject")->add("modelo", &number5_model);

	//Audio Component
	Engine::Audio_Component number5_audio(&number5, "../assets/FA_Special_Item_2_2.wav", 10);
	scene.get_gameobject_by_id("number5_gameobject")->add("audio_component", &number5_audio);

	//Actualizamos la posicion y rotacion del modelo (component) con la del gameobject
	number5_model.model_obj->translate(number5.get_transform()->position);
	number5_model.model_obj->rotate_around_x(number5.get_transform()->rotation.x);

	//Lo añadimos a la lista de numeros de la escena
	scene_numbers.push_back(&number5);
  

	//Creamos el observador que vigilara los numeros y lo añadimos a la escena
	Game::Number_Observer number_observer(scene_numbers,&scene);
	scene.add_observer("Number_Observer", number_observer);
  
#pragma endregion

	#pragma region Paredes

   //		Pared1
   Engine::GameObject pared1(&scene, glm::vec3(0,3, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
   scene.add_gameobject("pared1", pared1);

   //Model Component
   Engine::Model_Component pared1_model(pared1);
   scene.get_gameobject_by_id("pared1")->add("modelo", &pared1_model);

   //Actualizamos el modelo con la posicion del gameobject
   pared1_model.model->translate(pared1.get_transform()->position);
   pared1_model.model->scale(5,0.25f,0.25f);

   //Lo añadimos a las paredes de la escena
   scene_walls.push_back(&pared1);

   //		Pared2
   Engine::GameObject pared2(&scene, glm::vec3(0, -3, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
   scene.add_gameobject("pared2", pared2);

   //Model Component
   Engine::Model_Component pared2_model(pared2);
   scene.get_gameobject_by_id("pared2")->add("modelo", &pared2_model);

   //Actualizamos el modelo con la posicion del gameobject
   pared2_model.model->translate(pared2.get_transform()->position);
   pared2_model.model->scale(5, 0.25f, 0.25f);

   //Lo añadimos a las paredes de la escena
   scene_walls.push_back(&pared2);

   //		Pared3

   Engine::GameObject pared3(&scene, glm::vec3(4.5f, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
   scene.add_gameobject("pared3", pared3);

   //Model Component
   Engine::Model_Component pared3_model(pared3);
   scene.get_gameobject_by_id("pared3")->add("modelo", &pared3_model);

   //Actualizamos el modelo con la posicion del gameobject
   pared3_model.model->translate(pared3.get_transform()->position);
   pared3_model.model->scale(0.25f, 5 , 0.25f);

   //Lo añadimos a las paredes de la escena
   scene_walls.push_back(&pared3);

   //		Pared4

   Engine::GameObject pared4(&scene, glm::vec3(-4.5f, 0, 0), glm::vec3(0, 0, 0), glm::vec3(1, 1, 1));
   scene.add_gameobject("pared4", pared4);

   //Model Component
   Engine::Model_Component pared4_model(pared4);
   scene.get_gameobject_by_id("pared4")->add("modelo", &pared4_model);

   //Actualizamos el modelo con la posicion del gameobject
   pared4_model.model->translate(pared4.get_transform()->position);
   pared4_model.model->scale(0.25f, 5, 0.25f);

   //Lo añadimos a las paredes de la escena
   scene_walls.push_back(&pared4);

   //Creamos el observador que vigilara las paredes y lo añadimos
   Game::Walls_Observer walls_observer(scene_walls,&scene);
   scene.add_observer("Walls_Observer", walls_observer);
   
#pragma endregion
   
	#pragma region Render

   //Camara y luz
   scene.add_to_render("camera_component", camera_component.camera);
   scene.add_to_render("light_component", light_component.light);
   //Jugador
   scene.add_to_render("player_model", player_model.model_obj);
   //Paredes
   scene.add_to_render("pared1_model", pared1_model.model);
   scene.add_to_render("pared2_model", pared2_model.model);
   scene.add_to_render("pared3_model", pared3_model.model);
   scene.add_to_render("pared4_model", pared4_model.model);
   //Numeros
   scene.add_to_render("number1_model", number1_model.model_obj);
   scene.add_to_render("number2_model", number2_model.model_obj);
   scene.add_to_render("number3_model", number3_model.model_obj);
   scene.add_to_render("number4_model", number4_model.model_obj);
   scene.add_to_render("number5_model", number5_model.model_obj);

#pragma endregion

   scene.run();


	return 0;
}