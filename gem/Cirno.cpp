#include "Cirno.h"
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include "belgiancurve.h"

using namespace std;

Cirno::Cirno(int ix, int iy, double iscale, int icolor) {
	color = icolor;
	x_pos = ix;
	y_pos = iy;
	scale = iscale;
	hitbox_x1 = ix;
	hitbox_y1 = iy + (7 * scale);
	hitbox_x2 = ix + (50 * scale);
	hitbox_y2 = hitbox_y1 + (120 * scale);
	hp = 3;
	speed = 3;
	
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
	x_pos-=speed;
	hitbox_x1-=speed;
	hitbox_x2-=speed;
}

void Cirno::move_right() {
	x_pos+=speed;
	hitbox_x1+=speed;
	hitbox_x2+=speed;
}

void Cirno::move_up() {
	y_pos-=speed;
	hitbox_y1-=speed;
	hitbox_y2-=speed;
}

void Cirno::move_down() {
	y_pos+=speed;
	hitbox_y1+=speed;
	hitbox_y2+=speed;
}

void Cirno::draw() {
	setcolor(color);
	belgiancurve bc;
	moveto(x_pos, y_pos);
	bc.beziercurveto(x_pos - (60 * scale), y_pos - (75 * scale), x_pos + (120 * scale), y_pos - (75 * scale), x_pos + (50 * scale), y_pos, color); // head shape circular part
	
	moveto(x_pos, y_pos);
	linerel(50 * scale, 0); // chin
	
	moveto(x_pos, y_pos); // hair strands
	linerel(-2 * scale, -25 * scale); // 1st hair strand
	linerel(5 * scale, -11 * scale); 
	linerel(5 * scale, 13 * scale); 
	linerel(5 * scale, -12 * scale);
	linerel(4 * scale, 16 * scale);
	linerel(13 * scale, -14 * scale);
	linerel(0, 15 * scale);
	linerel(24 * scale, -14 * scale);
	lineto(x_pos + (50 * scale), y_pos);
	moveto(x_pos, y_pos);
	moverel(18 * scale, -40 * scale);
	setfillstyle(SOLID_FILL, color);
	floodfill(getx(), gety(), color);
	
	//to align the neck
	int necklength = 7 * scale;
	
	moveto(x_pos + (50 * scale / 2) , y_pos);
	moverel(-5 * scale, 0);
	linerel(0, necklength);
	moverel(10 * scale, 0);
	linerel(0, -necklength);
	
	
	int rightsidebody = x_pos + (50 * scale);
	
	//drawing the body
	moveto(x_pos, y_pos);
	moverel(0, necklength); 
	linerel(50 * scale, 0);
	linerel(0, 80 * scale);
	linerel(25 * scale, 40 * scale);
	int x_lowerrightskirt = getx();
	int y_lowerskirt = gety();
	linerel(-100 * scale, 0);
	int x_lowerleftskirt = getx();
	linerel(25 * scale, -40 * scale);
	linerel(0, -80 * scale);
	
	//drawing the arms
	//rightarm
	int armlength = 45 * scale;
	linerel(-1 * armlength, 55 * scale);
	linerel(10*scale, 10*scale);
	linerel(35 * scale, -45 * scale);
	//left arm
	moveto(rightsidebody, y_pos + necklength);
	linerel(armlength, 55 * scale);
	linerel(-10 * scale, 10 * scale);
	linerel(-35 * scale, -45 * scale);
	
	//draw teh spiky thing sa skirt
	moveto(x_lowerleftskirt, y_lowerskirt);
	linerel(12 * scale, -20 * scale);
	linerel(10 * scale, 10 * scale);
	linerel(10 * scale, -10 * scale);
	linerel(10 * scale, 10 * scale);
	linerel(10 * scale, -10 * scale);
	linerel(10 * scale, 10 * scale);
	linerel(10 * scale, -10 * scale);
	linerel(10 * scale, 10 * scale);
	linerel(8 * scale, -9 * scale);
	setfillstyle(SOLID_FILL, WHITE);
	moverel(-7 * scale, 13 * scale);
	floodfill(getx(), gety(), color);
	
	//drawlegs
	//leftleg
	moveto(x_lowerleftskirt, y_lowerskirt);
	moverel(30 * scale, 0);
	linerel(0, 30 * scale);
	linerel(-10 * scale, 0);
	linerel(0, 8 * scale);
	linerel(20 * scale, 0);
	linerel(0, -38 * scale);
	
	//rightleg
	moverel(20 * scale, 0);
	linerel(0, 38 * scale);
	linerel(20 * scale, 0);
	linerel(0, -8 * scale);
	linerel(-10 * scale, 0);
	linerel(0, -30 * scale);
	
	//shirtdetails
	//sleves
	moveto(x_pos, y_pos + necklength);
	moverel(-18 * scale, 22 * scale);
	linerel(10 * scale, 10 * scale);
	floodfill(getx(), gety() - 5, color);
	moveto(rightsidebody, y_pos + necklength);
	moverel(18 * scale, 22 * scale);
	linerel(-10 * scale, 10 * scale);
	floodfill(getx(), gety() - 5 * scale, color);
	
	//neckopen
	moveto(x_pos, y_pos + necklength);
	moverel(15 * scale, 0);
	linerel(0, 15 * scale);
	linerel(20 * scale, 0);
	linerel(0, -15 * scale);
	floodfill(getx() - 2, gety() + 2, color);
	
	//draw mouth
	moveto(x_pos + (25 * scale), y_pos - (8 * scale));
	arc(getx(), gety(), 180, 0, 5 * scale);
	
	
}

int Cirno::get_speed() {
	return speed;
}

void Cirno::set_speed(int new_speed){
	speed = new_speed;
}

void Cirno::closewindow(){
	closegraph();
}

void Cirno::createwindow(){
	
	int grErrCode;
	
   	initwindow(900, 700, "LOLZER");
   	grErrCode = graphresult();
   
   	if( grErrCode != grOk){
   		cout << "lulError" << endl;
   		exit(1);
   	}
   	
}

int Cirno::get_hitbox_x1(){
	return hitbox_x1;
}

int Cirno::get_hitbox_y1(){
	return hitbox_y1;
}

int Cirno::get_hitbox_x2(){
	return hitbox_x2;
}

int Cirno::get_hitbox_y2(){
	return hitbox_y2;
}

void Cirno::handle_input()
{
    //If a key was pressed
  /**  if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: move_up(); break;
            case SDLK_DOWN: move_down(); break;
            case SDLK_LEFT: move_left(); break;
            case SDLK_RIGHT: move_right(); break;    
        }
    }*/
}
