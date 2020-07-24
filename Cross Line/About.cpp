#include "Game_Class.h"



extern MOUSEMSG msg;	// �����Ϣ



//***** ��ʼ�������Ա����ʵ�� *****//

CAbout::CAbout() {}		// ���캯��
CAbout::~CAbout() {}	// ��������



// ���ڽ���
void CAbout::inter_Face_Running()
{
	// ���úͳ�ʼ��
	CButton_Image image;
	CButton return_button;
	return_button.set_Image(image.return_Button(RGB(224, 197, 150)));
	return_button.set_X_Y(25, 25);

	// ������Ϸ
	while (1)
	{
		this->clear_Board();
		this->draw_Text();

		this->get_Msg();
		
		// ���ذ�ť
		if (return_button.if_Mouse_On(msg))
		{
			return_button.set_Image(image.return_Button(RGB(224 + 15, 197 + 15, 150 + 15)));
			return_button.draw_Button();

			if (msg.uMsg == WM_LBUTTONUP)
			{
				msg.uMsg = WM_MOUSEMOVE;
				return;
			}
		}
		else
		{
			return_button.set_Image(image.return_Button(RGB(224, 197, 150)));
			return_button.draw_Button();
		}

		FlushBatchDraw();
		Sleep(1);
	}
}
// ���ڽ���



// ���Ʊ���
void CAbout::draw_Text()
{
	// ��ʼ����
	setbkmode(TRANSPARENT);
	LOGFONT font;
	gettextstyle(&font);
	font.lfQuality	= ANTIALIASED_QUALITY;
	wcscpy_s(font.lfFaceName, TEXT("΢���ź� Light"));

	// ���Ʊ���
	font.lfHeight = 75;
	settextstyle(&font);
	settextcolor(TEXT_COLOR);
	outtextxy(	(WIN_WIDTH		- textwidth(TEXT("����")))	/ 2,
				 WIN_HEIGHT / 5 - textheight(TEXT("����")), TEXT("����"));

	// ���Ʊ߿�
	setlinecolor(TEXT_COLOR);
	setlinestyle(PS_SOLID, 5);
	rectangle(50, 170, 430, 565);

	// ��Ϣ���
	font.lfHeight = 25;
	settextstyle(&font);
	settextcolor(TEXT_COLOR);
	outtextxy(70, 190, TEXT("���ƣ�������"));
	outtextxy(70, 220, TEXT("�汾��V1.0"));
	outtextxy(70, 250, TEXT("���ߣ�Lost(QQ:2931404870)"));
	outtextxy(70, 280, TEXT("ʱ�䣺2020-7-23"));
	outtextxy(70, 310, TEXT("��飺��������С��Ϸ"));
	outtextxy(70, 340, TEXT("�淨���ܼ򵥣�������϶����Ƶ㣬ʹ��"));
	outtextxy(70, 370, TEXT("�����߶θ������棬��Ϊ���أ������в�"));
	outtextxy(70, 400, TEXT("ͬ���ĵ㣬�����ƣ�С��̶�����һ"));
	outtextxy(70, 430, TEXT("�߶β��������߶ν��棬���԰�ɫ������"));
	outtextxy(70, 460, TEXT("ƫ��ɫ����һ���Ƶ������߶ζ���������"));
	outtextxy(70, 490, TEXT("�߶ν��棬��õ��԰�ɫ������ƫ��ɫ��"));
	outtextxy(70, 520, TEXT("�̶���ʼ��ƫ��ɫ��"));
}
// ���Ʊ���

//***** ��ʼ�������Ա����ʵ�� *****//