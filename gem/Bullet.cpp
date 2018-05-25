#include "Bullet.h"
#include <graphics.h>
#include <conio.h>
Bullet::Bullet(){
	speed = 3;
}

Bullet::~Bullet(){
}

void Bullet::logic(){
	if(is_active()){
		move_up();
	}
}

void Bullet::draw(){
	setcolor(CYAN);
	moveto(x, y);
	linerel(5, 20);
	linerel(-10, 0);
	linerel(5, -20);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(x, y + 3, CYAN);
}

bool Bullet::is_active(){
	return active;
}

void Bullet::set_x(int new_x){
	x = new_x;
}
void Bullet::set_y(int new_y){
	y = new_y;
}
void Bullet::set_pos(int x, int y){
	set_x(x);
	set_y(y);
}

void Bullet::move_up(){
	y -= speed;
}
 
void Bullet::shoot(int start_x, int start_y){
	set_pos(start_x, start_y);
	activate();
}
 
void Bullet::deactivate() {
	active = false;
	set_pos(-500, -500);
}
 
void Bullet::activate() {
	active = true;
}
 
