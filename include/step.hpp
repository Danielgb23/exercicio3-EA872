
#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include "view.hpp"
#include "coord.hpp"
using namespace std;

//controler
class step{
	public:
		//coord class with data and the size of time step
		void update(shared_ptr<coord>  data, float T);
		step();
	private:
		
  const Uint8* state = SDL_GetKeyboardState(nullptr); // estado do teclado 
		view Viewer;
};


