#include <iostream>
#include "fontcontroller.h"
#include "belgiancurve.h"
#include <graphics.h>
#include <conio.h>

using namespace std;

fontcontroller::fontcontroller(void){
}

void fontcontroller::createwindow(){
	
	int grErrCode;
	
   	initwindow(900, 700, "LOLZER");
   	grErrCode = graphresult();
   
   	if( grErrCode != grOk){
   		cout << "lulError" << endl;
   		exit(1);
   	}
   	
   	
}

void fontcontroller::closewindow(){
	getch();
	closegraph();
}

void fontcontroller::drawR(int x, int y) {
	setcolor(RED);
	belgiancurve bc;
	moveto(x, y);
	linerel(0, 87);
	linerel(50, 0);
	bc.beziercurveto(x, y - 67, x + 100, y - 67, x + 100, y - 37, RED);
	moveto(x + 100, y - 37);
	linerel(20, 0);
	bc.beziercurveto(x + 123, y - 100, x, y - 100, x, y, RED);
	setfillstyle(LINE_FILL, RED);
	floodfill(x+1, y+1, RED);
}

void fontcontroller::drawA(int x, int y) {
	setcolor(CYAN);
	moveto(x, y);
   	linerel(-50,175);
   	linerel(50, 0);
   	
   	
   	linerel(18, -63);
   	linerel(12, 0);			//underside of the A
   	linerel(18, 63);
   	
   	linerel(50, 0);
   	linerel(-50, -175);
   	linerel(-50, 0);
   	
   	moveto(x, y);
   	moverel(23, 40);
   	linerel(2, 0);
   	linerel(7, 40);
   	linerel(-16, 0);
   	linerel(7, -40);
	setfillstyle(SOLID_FILL, CYAN);
	floodfill(x+1, y+1, CYAN);
}

void fontcontroller::drawY(int x, int y) {
	setcolor(YELLOW);
	moveto(x, y);
   	linerel(50, 0);
   	linerel(25, 50);
   	linerel(25, -50);
   	linerel(50, 0);
   	linerel(-50, 100);
   	linerel(0, 75);
   	linerel(-50, 0);
   	linerel(0, -75);
   	linerel(-50, -100);
	setfillstyle(WIDE_DOT_FILL, YELLOW);
	floodfill(x+1, y+1, YELLOW);


}

void fontcontroller::drawBc(int x, int y) {
	belgiancurve b;
	moveto(150, 267);
	int color = WHITE;
	b.beziercurveto(125, 45, 434, 383, 490, 240, color);
}
