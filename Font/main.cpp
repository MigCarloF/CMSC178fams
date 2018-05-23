#include <iostream>
#include "fontcontroller.h"
using namespace std;

int main() {
	fontcontroller k;
	k.createwindow();
	k.drawY(50, 50);
	k.drawA(250, 50);
	k.closewindow();
	return 0;
}
