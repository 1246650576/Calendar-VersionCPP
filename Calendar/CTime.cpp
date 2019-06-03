#include "CTime.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//获取当前时间
void CTime::getTime()
{
	SYSTEMTIME CurrentTime;
	GetLocalTime(&CurrentTime);

	this->hour = CurrentTime.wHour;
	this->minute = CurrentTime.wMinute;
	this->second = CurrentTime.wSecond;
	resetYear(CurrentTime.wYear);
	resetMonth(CurrentTime.wMonth);
	resetDay(CurrentTime.wDay);
}
//显示当前时间
void CTime::showTime() {
	const char* WEEK[7] = { "星期日" ,"星期一","星期二","星期三","星期四","星期五","星期六"};
	getTime();
	int ssecond = second;
	do {
		getTime();
		cout << setw(2) << hour << ":" 
			 << setw(2) << minute << ":" 
			<< setw(2) << second << endl;
		cout << getYear() << "年" << getMonth() << "月" << getDay() << "日" << "   " << WEEK[getWeek()] << endl;
		cout << endl << endl << endl << endl << "       欢迎使用万年历查询系统" << endl<<endl
			<< "              启动中..." << endl;
		
		//延迟
		for (unsigned int i = 0; i < 333911402; i++) {

		}
		CleanScreen(); //清屏

		//设置启动时间为10秒
	} while ((abs(second - ssecond) <= 10 || abs(second - ssecond) >= 50));
}

//定制控制台界面的名称、颜色、尺寸等等
void CTime::settingCConsole() {
	CConsole::HideCursor(true);
	CConsole::SetTitle("万年历查询系统");
	CConsole::SetColor("5f");
	CConsole::SetSize(35, 25);
}