#ifndef CIRNO_H
#define CIRNO_H

class Cirno
{
	public:
		Cirno(int x, int y, double scale, int color);
		~Cirno();
		void draw();
		
		void move_left();
		void move_right();
		void move_up();
		void move_down();
		
		void shoot();
		void die();
		void take_damage();
		bool is_dead();
		
		void set_hp(int hp);
		int get_speed();
		void set_speed(int speed);
		
		int get_hitbox_x1();
		int get_hitbox_y1();
		int get_hitbox_x2();
		int get_hitbox_y2();
		
		void handle_input();
		
		void closewindow();
		void createwindow();
	private:
		int x_pos;
		int y_pos;
		double scale;
		
		int hitbox_x1;
		int hitbox_y1;
		int hitbox_x2;
		int hitbox_y2;
		
		int hp;
		int speed;
		int color;
		
	protected:
};

#endif
