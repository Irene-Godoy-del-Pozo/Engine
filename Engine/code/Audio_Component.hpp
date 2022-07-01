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



#include <Component.hpp>
#include<string>


struct Mix_Chunk;

namespace Engine
{
	/// <summary>
	/// Clase que engloba los componente de audio que pueden ser añadidos a un gameobject. Es utilizado para sonidos puntuales
	/// </summary>
	class Audio_Component : public Component
	{
	private :

		/// <summary>
		/// Puntero al sonido 
		/// </summary>
		Mix_Chunk* sample;

		/// <summary>
		/// Volumen
		/// </summary>
		int volume = 1;
	public:



		/// <summary>
		/// Constructor 
		/// </summary>
		/// <param name="s"> Puntero al gameobject al que es añadido</param>
		/// <param name="rute">Ruta al archivo de musica</param>
		/// <param name="_volume">Volume deseado</param>
		Audio_Component(GameObject* s, std::string rute, int _volume);

		/// <summary>
		/// Cambia el archivo musical del componente
		/// </summary>
		/// <param name="rute">Ruta al nuevo archivo</param>
		void change_chunk(std::string rute);

		/// <summary>
		/// Reproduce el sonido
		/// </summary>
		void play_chunk();

		/// <summary>
		/// Cambia el volumen
		/// </summary>
		/// <param name="_volume">Volumen deseado</param>
		void change_volume(int _volume);


	};

}