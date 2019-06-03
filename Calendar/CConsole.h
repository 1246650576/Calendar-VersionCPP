#pragma once
#ifndef CCONSOLE_H
#define CCONSOLE_H

#include "windows.h"	// HANDLE
#include <cstdio>		// sprintf

class CConsole
{
private://私有成员
	COORD coord;
	HANDLE HConsole;

public://外部接口
	CConsole();	//构造函数
	~CConsole();//析构函数

	void SetCoord(int x, int y);		//设置输出的位置
	void HideCursor(bool hide);			//光标开启与关闭
	void SetTitle(const char* title);	//设置标题名称
	void SetSize(int width, int height);//设置控制台大小
	void SetColor(const char* cl);		//设置颜色
	void CleanScreen(void);				//清屏
	void PauseScreen(void);				//冻结屏幕
	
	//友元函数声明
	//friend void Introduction();			//程序信息关于
};

#endif