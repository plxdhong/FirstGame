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
	// 非暂停状态才更新
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
	if (key == 'P' || key == 'p') //按下P键就在播放与暂停之间转换
	{
		pause_state = !pause_state;
	}
	if (key == VK_ESCAPE) //如果是ESC键，就标记为退出场景，VK_ESCAPE是SDK定义的宏
	{
		end_state = 1;
	}
}

void Gra::mainloop()
{
	ege::setinitmode(ege::INIT_ANIMATION);
	// 图形初始化，窗口尺寸640x480
	ege::initgraph(640, 480);
	// 随机数初始化，如果需要使用随机数的话
	for (; ege::is_run(); ege::delay_fps(60))
	{
		while (ege::kbhit())
		{
			int key = ege::getch();
			onkey(key); //所有按键消息发送给scene
		}
		if (update()) //如果update返回非0表示场景结束，这时退出主循环
		{
			break;
		}
		ege::cleardevice();
		render();
	}
}
