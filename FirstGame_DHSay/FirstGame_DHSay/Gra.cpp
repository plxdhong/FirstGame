#include "Gra.h"
#include <graphics.h>

Gra::Gra(int num_box_int)
{
	num_GraBox_int = num_box_int;
	pause_state = 0;
	end_state = 0;
	GraBox = new ABox[num_box_int];
	GraPlayer = new APlayer;
	GraWall = new GraWall;
}
Gra::~Gra()
{
	delete[] GraBox;
	delete GraPlayer;
	delete GraWall;
}
int Gra::update()
{
	// ����ͣ״̬�Ÿ���
	if (pause_state == 0)
	{
		for (int n = 0; n < num_GraBox_int; ++n)
		{
			GraBox[n].update();
		}
		GraPlayer.update();
		GraWall.update();
	}
	return end_state;
}
void Gra::render()
{
	for (int n = 0; n < num_GraBox_int; ++n)
	{
		GraBox[n].render();
	}
	GraPlayer.render();
	GraWall.render();
}
void Gra::onkey(int key)
{
	if (key == 'P' || key == 'p') //����P�����ڲ�������֮ͣ��ת��
	{
		pause_state = !pause_state;
	}
	if (key == VK_ESCAPE) //�����ESC�����ͱ��Ϊ�˳�������VK_ESCAPE��SDK����ĺ�
	{
		end_state = 1;
	}
}

void Gra::mainloop()
{
	ege::setinitmode(ege::INIT_ANIMATION);
	// ͼ�γ�ʼ�������ڳߴ�640x480
	ege::initgraph(640, 480);
	// �������ʼ���������Ҫʹ��������Ļ�
	for (; ege::is_run(); ege::delay_fps(60))
	{
		while (ege::kbhit())
		{
			int key = ege::getch();
			onkey(key); //���а�����Ϣ���͸�scene
		}
		if (update()) //���update���ط�0��ʾ������������ʱ�˳���ѭ��
		{
			break;
		}
		ege::cleardevice();
		render();
	}
}
