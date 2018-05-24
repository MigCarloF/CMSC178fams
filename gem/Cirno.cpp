#include "Cirno.h"

Cirno::Cirno(int Color) {
	hp = 3;
}

Cirno::~Cirno() {
}

void Cirno::die() {
	hp = 0;
}

bool Cirno::is_dead() {
	return hp == 0 ? true : false;
}

void Cirno::take_damage() {
	hp--;
	if(hp <= 0) {
		die();
	}
}

void Cirno::move_left() {
	x_pos--;
	hitbox_x1--;
	hitbox_x2--;
}

void Cirno::move_right() {
	x_pos++;
	hitbox_x1++;
	hitbox_x2++;
}

void Cirno::move_up() {
	y_pos--;
	hitbox_y1--;
	hitbox_y2--;
}

void Cirno::move_down() {
	y_pos++;
	hitbox_y1++;
	hitbox_y2++;
}

void Cirno::draw(int x, int y) {
	
}
