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

void fontcontroller::drawA(int x, int y) {
	moveto(x, y);
   	linerel(-50,175);
   	linerel(50, 0);
   	
   	
   	linerel(18, -63);
   	linerel(12, 0);			//underside of the A
   	linerel(18, 63);
   	
   	linerel(50, 0);
   	linerel(-50, -175);
   	linerel(-50, 0);
   	
   	moveto(250, 50);
   	moverel(23, 40);
   	linerel(2, 0);
   	linerel(7, 40);
   	linerel(-16, 0);
   	linerel(7, -40);
   	floodfill(x + 1, y + 1, WHITE);
}

void fontcontroller::drawY(int x, int y) {
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
   	floodfill(x+ 1, y + 1, WHITE);
}
