#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include "belgiancurve.h"

belgiancurve::belgiancurve(void){
}

void belgiancurve::beziercurveto(int x1, int y1, int x2, int y2, int xTo, int yTo, int color){
	
	int i;
	double t,xt,yt;
	
	int x[4]={200,200,200,300};
	int y[4]={200,50,75,300};
	x[0] = getx();
	x[1] = x1;
	x[2] = x2;
	x[3] = xTo;
	y[0] = gety();
	y[1] = y1;
	y[2] = y2;
	y[3] = yTo;
	
	for(t = 0.0; t < 1.0; t += 0.0005){
		xt = pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
		yt = pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];
		putpixel (xt, yt,color);
	}

	for(i=0; i<4; i++) {
		putpixel (x[i], y[i], color);
	}
}
 
