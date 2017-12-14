#include <graphics.h>

int main()
{
	//初始化窗口大小
	initgraph(1280, 600);
	setbkcolor(EGERGB(0x0, 0x40, 0x0));

	//设置颜色
	setcolor(EGERGB(0xff,0x0,0x0));
	setfillcolor(EGERGB(0xff, 0xff, 0x80));

	//画圆
	circle(80, 80, 160);

	//填充椭圆
	fillellipse(200, 200, 150, 100);

	setfillcolor(EGERGB(0x80, 0x0, 0xFF));
	floodfill(80, 80, EGERGB(0xFF, 0x0, 0x0));
	//画线
	line(10, 10, 20, 20);

	//画矩形
	bar(400, 400, 600, 600);

	getch();

	//关闭图形界面
	closegraph();
	return 0;
}