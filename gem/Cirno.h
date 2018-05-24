#ifndef CIRNO_H
#define CIRNO_H

class Cirno
{
	public:
		Cirno(int Color);
		~Cirno();
		void draw(int x, int y);
		
		void move_left();
		void move_right();
		void move_up();
		void move_down();
		
		void shoot();
		void die();
		void take_damage();
		bool is_dead();
		
		void set_hp(int hp);

	private:
		int x_pos;
		int y_pos;
		
		int hitbox_x1;
		int hitbox_y1;
		int hitbox_x2;
		int hitbox_y2;
		
		int hp;
		int speed;
		
	protected:
};

#endif
