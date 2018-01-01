#pragma once
class Gra
{
private:
	int pause_state;
	int end_state;
	int num_GraBox_int;
	ABox* GraBox;
	APlayer* GraPlayer;
	Wall* GraWall;
public:
	Gra(int num_box_int);
	~Gra();
	int update();
	void render();
	void mainloop();
	void onkey(int key);
};

