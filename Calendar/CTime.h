#ifndef __MYTIME_H__
#define __MYTIME_H__

#include"CDate.h"
#include "CConsole.h"
using namespace std;

//定义时间类
class CTime:public CDate,public CConsole
{
public://外部接口
	//显示当前时间
	void showTime();
	//定制控制台界面的名称、颜色、尺寸等等
	void settingCConsole();

protected://保护成员
	int hour;	//时
	int minute;	//分
	int second;	//秒

private://私有成员
	//获取当前时间
	void getTime();
};
#endif __MYTIME_H__