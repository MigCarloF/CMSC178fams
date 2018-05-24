#include <iostream>
#include "fontcontroller.h"
#include "belgiancurve.h"
#include <graphics.h>
#include <conio.h>
using namespace std;

int main() {
	fontcontroller k;
	k.createwindow();
	/**k.drawA(50, 50);
	k.drawR(200, 137);
	k.drawR(350, 137);
	k.drawA(500, 50);
	k.drawY(600, 50);*/
	k.drawBc(1,1);
	k.closewindow();
	
	return 0;
}
