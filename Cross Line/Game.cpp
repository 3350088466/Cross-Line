#include "Game_Class.h"



extern MOUSEMSG msg;	// �����Ϣ



//***** ��ʼ�������Ա����ʵ�� *****//

CGame::CGame() {}	// ���캯��
CGame::~CGame() {}	// ��������



// ���Ʊ���
void CGame::clear_Board()
{
	setbkcolor(BKCOLOR);
	cleardevice();
}
// ���Ʊ���



// ��ȡ�����Ϣ
void CGame::get_Msg()
{
	while (MouseHit())
		msg = GetMouseMsg();
}
// ��ȡ�����Ϣ

//***** ��ʼ�������Ա����ʵ�� *****//
