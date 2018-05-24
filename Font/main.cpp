#include <iostream>
#include "fontcontroller.h"
#include "belgiancurve.h"
#include <graphics.h>
#include <conio.h>
using namespace std;

int main() {
	fontcontroller k;
	k.createwindow();
	k.drawY(50, 50);
	k.drawA(250, 50);
	k.drawR(450, 100);
	k.closewindow();
	
	return 0;
}
