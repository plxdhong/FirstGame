#include <graphics.h>

int main()
{
	//��ʼ�����ڴ�С
	initgraph(1280, 600);
	setbkcolor(EGERGB(0x0, 0x40, 0x0));

	//������ɫ
	setcolor(EGERGB(0xff,0x0,0x0));
	setfillcolor(EGERGB(0xff, 0xff, 0x80));

	//��Բ
	circle(80, 80, 160);

	//�����Բ
	fillellipse(200, 200, 150, 100);

	setfillcolor(EGERGB(0x80, 0x0, 0xFF));
	floodfill(80, 80, EGERGB(0xFF, 0x0, 0x0));
	//����
	line(10, 10, 20, 20);

	//������
	bar(400, 400, 600, 600);

	getch();

	//�ر�ͼ�ν���
	closegraph();
	return 0;
}