
#include "step.hpp"
using namespace std;
#define F_TECLADO 10

#define NORM 14

void step::update(shared_ptr<coord>  data, float T){
	float b, k, m;
	float x, v;
	float newx, newv;
	float forca;
	int xp,yp;


	//pega dados do data
	data->get_const(&k, &b, &m);
	data->get_pos(&x, &v);

	// Quadrado onde a textura sera desenhada
	SDL_Rect target;
	target.x = SCREEN_WIDTH/2;
	target.y = SCREEN_HEIGHT/2;
	SDL_QueryTexture(Viewer.get_textura(), nullptr, nullptr, &target.w, &target.h);



	// Polling de eventos
	SDL_PumpEvents(); // atualiza estado do teclado
	if (state[SDL_SCANCODE_UP]) forca = -F_TECLADO;
	if (state[SDL_SCANCODE_DOWN]) forca = F_TECLADO;


	//calcula nova posicao
	newx= x + v*T - k*x*T*T/2/m - b*v*T*T/2/m + forca*T*T/2/m;
	newv= v - k*x*T/m - b*v*T/m+ forca*T/m;

	data->new_pos(newx, newv);

	cout << newx<<endl;
	//calcula posicao na tela
	target.x=SCREEN_WIDTH/2-target.w/2;
	target.y=SCREEN_HEIGHT/2+newx*NORM-target.h/2;

	Viewer.render(target);

}
step::step(){
	state = SDL_GetKeyboardState(nullptr); // estado do teclado
} 
