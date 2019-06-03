#include "CConsole.h"
//构造函数
CConsole::CConsole()
{
	HConsole = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出设备的句柄
}
//析构函数
CConsole::~CConsole()
{

}
//设置输出的位置
void CConsole::SetCoord(int x, int y)
{
	// 复位到原始的左上角位置
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(HConsole, coord);
	// 以左上角位置为参照设置新的位置
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(HConsole, coord);
}
//光标开启与关闭
void CConsole::HideCursor(bool hide)
{
	// 隐藏控制台光标，CONSOLE_CURSOR_INFO结构体第二个成员设为0就不可见
	CONSOLE_CURSOR_INFO cursor_info = { 1, 1 };
	if (hide == true) cursor_info.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
//设置标题名称
void CConsole::SetTitle(const char* title)
{
	SetConsoleTitleA(title);
}
//设置控制台大小
void CConsole::SetSize(int width, int height)
{
	char str[256];
	sprintf_s(str, "mode con: cols=%d lines=%d", width, height);
	system(str); //窗口宽度高度
}


/*
COLOR [attr]

attr 指定控制台输出的颜色属性

颜色属性由两个十六进制数字指定:	第一个为背景，第二个则为前景。
每个数字可以为以下任何值之一:

0 = 黑色       8 = 灰色
1 = 蓝色       9 = 淡蓝色
2 = 绿色       A = 淡绿色
3 = 浅绿色     B = 淡浅绿色
4 = 红色       C = 淡红色
5 = 紫色       D = 淡紫色
6 = 黄色       E = 淡黄色
7 = 白色       F = 亮白色

如果没有给定任何参数，该命令会将颜色还原到 CMD.EXE 启动时的颜色。
这个值来自当前控制台窗口、/T 命令行开关或DefaultColor 注册表值。

*/
//设置颜色
void CConsole::SetColor(const char* cl)
{
	char str[256];
	sprintf_s(str, "color %s", cl);
	system(str);		//设置颜色
}

//清屏
void CConsole::CleanScreen(void){
	system("CLS");		//清屏
}

//冻结屏幕
void CConsole::PauseScreen(void) {
	system("pause");	//冻结屏幕
}
