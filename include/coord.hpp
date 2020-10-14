#pragma once
#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

//model
class coord{
	private:
		//posicao e velocidade
		shared_ptr<float> pos;
		shared_ptr<float> vel;

		//constantes do sistema
		float k;
		float m;
		float b;
		SDL_Texture *texture;
	
		// Quadrado onde a textura sera desenhada
		SDL_Rect target;



	public:
		coord();
		void new_data(float new_pos, float new_vel, float n_k, float n_b, float n_m );
		void new_pos(float new_pos, float new_vel);
		void get_pos(float * x, float * v);
		void get_const(float * ck, float * cb, float * cm);
		void coord_print();
		void new_target(SDL_Rect new_target);


};

