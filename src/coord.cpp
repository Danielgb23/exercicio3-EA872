#include "coord.hpp"
using namespace std;

coord::coord(){
	pos=make_shared<float>();
	vel=make_shared<float>();

	// Carregando texturas
	// personagem
	// fundo
}




void coord::new_data(float new_pos, float new_vel, float n_k, float n_b, float n_m) {
	(*pos)=new_pos;
	(*vel)=new_vel;
	k=n_k;
	m=n_m;
	b=n_b;
}

void coord::get_const(float * ck, float * cb, float * cm){
	(*ck)=k;
	(*cb)=b;
	(*cm)=m;
}

void coord::new_pos(float new_pos, float new_vel) {
	(*pos)=new_pos;
	(*vel)=new_vel;
}

void coord::get_pos(float * x, float * v){
	(*x)=*pos;
	(*v)=*vel;
}
void coord::coord_print(){
	cout << "pos="<< *pos << ", vel=" << *vel << endl;
}



