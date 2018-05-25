#include<iostream>
#include"Cirno.h"
#include<graphics.h>
#include"Bullet.h"
#include<conio.h>
#include<vector>
#include<algorithm>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_X 120

using namespace std;

void dodis(Cirno& cirno){
	cirno.draw();
}

void dodis2(Bullet& cirno){
	cout << "lul" << endl;
}

int main() {
	Cirno cirno(400, 200, 2, CYAN);
	Cirno cirno2(60, 200, 1.0, GREEN);
	bool game = true;
	
	cirno.createwindow();
	
	vector<Bullet> bullets;
	vector<Cirno> enemies;
	
	for(int i = 0; i < 10; i++){
		Bullet bullet;
		bullets.push_back(bullet);
	}
	int curr = 20;
	for(int i = 0; i < 30; i++){
		Cirno enemy(curr, 100, 0.9, GREEN);
		curr+=100;
		enemies.push_back(enemy);
	}
	
	for_each(enemies.begin(), enemies.end(), dodis);
	cout << bullets.size() << endl;
	cout << enemies.size();
	
	getch();
	return 0;
		int page = 0;
		
	while (1){
		setactivepage(page);
		setvisualpage(1 - page);
		cleardevice();
		
	    if ( kbhit() ){
	        int b = getch();
	        switch(b) {
	        	case KEY_UP:
	        		cirno.move_up();
	        		break;
	        	case KEY_DOWN:
	        		cirno.move_down();
	        		break;
	        	case KEY_LEFT:
	        		cirno.move_left();
	        		break;
	        	case KEY_RIGHT:
	        		cirno.move_right();
	        		break;
	        		case KEY_X:
	        			game = false;
	        			break;
	        			
			}
	    }
	    
		cirno.draw();
		cirno2.draw();
		
		cirno.draw();
		cirno2.draw();
		page = 1 - page;
		delay(5);
	}
	cirno.closewindow();
	return 0;
}
