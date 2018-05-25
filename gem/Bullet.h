#ifndef BULLET_H
#define BULLET_H
class Bullet
{
	public:
		Bullet();
		~Bullet();
		bool is_active();
		void draw();
		void move_up();
		void set_x(int x);
		void set_y(int y);
		void set_pos(int x, int y);
		void shoot(int x, int y);
		bool has_collided(int x1, int y1, int x2, int y2);
		void deactivate();
		void logic();
	private:
		int x;
		int y;
		int speed;
		bool active;
		void activate();
		
	protected:
};

#endif
