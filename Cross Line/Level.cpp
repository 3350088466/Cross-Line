#include "Game_Class.h"



extern int pasin;				// ��ǰ�ؿ�
extern MOUSEMSG msg;			// �����Ϣ
extern wchar_t best_time[100];	// ���ʱ��
extern int pass_num;			// �ؿ���



//***** ��ʼ�������Ա����ʵ�� *****//

CLevel::CLevel() {}		// ���캯��
CLevel::~CLevel() {}	// ��������



// �ؿ�����
void CLevel::inter_Face_Running()
{
	// ���úͳ�ʼ��
	CGame *in;
	pass_num = stat();
	static int wheel = 0;
	CButton_Image image;
	int buffer_len = 50 * 2 + pass_num * image.level_Button(TEXT("0"),
					TEXT("--:--"), RGB(0, 0, 0)).getheight() + (pass_num - 1) * 15;
	int bar_len = WIN_HEIGHT * WIN_HEIGHT / buffer_len;
	CButton close_button, level_button[100];
	close_button.set_Image(image.close_Button(BASE_COLOR));
	close_button.set_X_Y(25, 25);

	// ������Ϸ
	while (1)
	{
		this->clear_Board();

		this->get_Msg();

		// ���������Ϣ
		wheel -= msg.wheel / 5 * 2;
		msg.wheel = 0;

		if (wheel > buffer_len - WIN_HEIGHT)
			wheel = buffer_len - WIN_HEIGHT;

		if (wheel < 0)
			wheel = 0;

		// ����������
		setfillcolor(BASE_COLOR);
		solidrectangle(	WIN_WIDTH - 5, wheel * WIN_HEIGHT / buffer_len, 
						WIN_WIDTH,		wheel * WIN_HEIGHT / buffer_len + bar_len);

		// �رհ�ť
		if (close_button.if_Mouse_On(msg))
		{
			close_button.set_Image(image.close_Button(RGB(125, 125, 125)));
			close_button.draw_Button();

			if (msg.uMsg == WM_LBUTTONUP)
			{
				msg.uMsg = WM_MOUSEMOVE;
				return;
			}
		}
		else
		{
			close_button.set_Image(image.close_Button(TEXT_COLOR));
			close_button.draw_Button();
		}

		// �ؿ���ť
		for (int i = 1; i <= pass_num; i++)
		{
			wchar_t num[100];
			swprintf_s(num, TEXT("%d"), i);

			wchar_t file_name[100] = TEXT("Level\\");
			swprintf_s(file_name, TEXT("Level\\%s.txt"), num);	// ����ؿ����

			std::wfstream file;
			file.open(file_name, std::ios::in | std::ios::out);

			wchar_t time_info[100];
			file >> best_time;
			swprintf_s(time_info, TEXT("��ѣ�%s"), best_time);	// �������ʱ��

			if (i % 2 == 1)
				level_button[i].set_Image(image.level_Button(num, time_info, RGB(206, 207, 141)));
			else
				level_button[i].set_Image(image.level_Button(num, time_info, RGB(223, 195, 123)));
			level_button[i].set_X_Y(WIN_WIDTH / 2 - level_button[i].get_Image().getwidth() / 2,
				50 - wheel + (level_button[i].get_Image().getheight() + 15) * (i - 1));	// ���ð�ť

			// ���ƹؿ���ť
			if (level_button[i].if_Mouse_On(msg))
			{
				if (i % 2 == 1)
					level_button[i].set_Image(image.level_Button(num, time_info, RGB(206 + 15, 207 + 15, 141 + 15)));
				else
					level_button[i].set_Image(image.level_Button(num, time_info, RGB(223 + 15, 195 + 15, 123 + 15)));
				level_button[i].set_X_Y(WIN_WIDTH / 2 - level_button[i].get_Image().getwidth() / 2,
					50 - wheel + (level_button[i].get_Image().getheight() + 15) * (i - 1));
				level_button[i].draw_Button();

				if (msg.uMsg == WM_LBUTTONUP)
				{
					msg.uMsg = WM_MOUSEMOVE;
					pasin = i;
					in = new CPlay();
					in->inter_Face_Running();
					delete in;
					in = NULL;
				}
			}
			else
			{
				level_button[i].draw_Button();
			}

			file.close();
		}

		FlushBatchDraw();
		Sleep(1);
	}
}
// �ؿ�����



// ͳ�ƹؿ���
int CLevel::stat()
{
	int n = 0;
	wchar_t file_name[100];
	std::wfstream file;
	do
	{
		file.close();
		wcscpy_s(file_name, TEXT(""));
		swprintf_s(file_name, TEXT("Level\\%d.txt"), ++n);
		file.open(file_name, std::ios::in | std::ios::out);
	} while (file.is_open());
	file.close();
	return (n - 1);
}
// ͳ�ƹؿ���

//***** ��ʼ�������Ա����ʵ�� *****//