#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "step.hpp"
#include "view.hpp"
#include "coord.hpp"
using namespace std;

#define timeStep 0.1

int main() {
	shared_ptr<coord> data (new coord);
	step stepper;

	// Controlador:
	bool rodando = true;

  // Variaveis para verificar eventos
  SDL_Event evento; // eventos discretos

	//	      pos vel k   b  m
	data->new_data(0, 10, 10, 1, 1);
	while(rodando){

		stepper.update(data, timeStep);

		while (SDL_PollEvent(&evento)) {
			if (evento.type == SDL_QUIT) {
				rodando = false;
			}
		} 

    // Delay para diminuir o framerate
    SDL_Delay(timeStep*1000);

	}
	SDL_Quit();
	return 0;
}
