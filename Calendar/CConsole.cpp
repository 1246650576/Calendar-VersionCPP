#include "CConsole.h"
//���캯��
CConsole::CConsole()
{
	HConsole = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��׼����豸�ľ��
}
//��������
CConsole::~CConsole()
{

}
//���������λ��
void CConsole::SetCoord(int x, int y)
{
	// ��λ��ԭʼ�����Ͻ�λ��
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(HConsole, coord);
	// �����Ͻ�λ��Ϊ���������µ�λ��
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(HConsole, coord);
}
//��꿪����ر�
void CConsole::HideCursor(bool hide)
{
	// ���ؿ���̨��꣬CONSOLE_CURSOR_INFO�ṹ��ڶ�����Ա��Ϊ0�Ͳ��ɼ�
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	if (hide == true) cursor_info.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//���ñ�������
void CConsole::SetTitle(const char* title)
{
	SetConsoleTitleA(title);
}
//���ÿ���̨��С
void CConsole::SetSize(int width, int height)
{
	char str[256];
	sprintf_s(str, "mode con: cols=%d lines=%d", width, height);
	system(str); //���ڿ�ȸ߶�
}


/*
COLOR [attr]

attr ָ������̨�������ɫ����

��ɫ����������ʮ����������ָ��:	��һ��Ϊ�������ڶ�����Ϊǰ����
ÿ�����ֿ���Ϊ�����κ�ֵ֮һ:

0 = ��ɫ       8 = ��ɫ
1 = ��ɫ       9 = ����ɫ
2 = ��ɫ       A = ����ɫ
3 = ǳ��ɫ     B = ��ǳ��ɫ
4 = ��ɫ       C = ����ɫ
5 = ��ɫ       D = ����ɫ
6 = ��ɫ       E = ����ɫ
7 = ��ɫ       F = ����ɫ

���û�и����κβ�����������Ὣ��ɫ��ԭ�� CMD.EXE ����ʱ����ɫ��
���ֵ���Ե�ǰ����̨���ڡ�/T �����п��ػ�DefaultColor ע���ֵ��

*/
//������ɫ
void CConsole::SetColor(const char* cl)
{
	char str[256];
	sprintf_s(str, "color %s", cl);
	system(str);		//������ɫ
}

//����
void CConsole::CleanScreen(void){
	system("CLS");		//����
}

//������Ļ
void CConsole::PauseScreen(void) {
	system("pause");	//������Ļ
}
