#include<iostream>
#include"CConsole.h"
#include"CDate.h"

using namespace std;
#define WEEK 7

//定义万年历类
class CCalendar: public CConsole,public CDate
{
protected:
	const char *week[WEEK] = { "日","一","二","三","四","五","六" };
	//定制控制台界面的名称、颜色、尺寸等等
	void settingCConsole();
public:
	//根据1日所在星期数，生成这个月的日期 ,并存于数组date
	void GetDate(int week, int date[][WEEK], int MaxDay);
	//功能选择界面
	virtual void Menu() = 0;	//纯虚函数
	//查询
	virtual void SearchFor() = 0;//纯虚函数
};

//定义年历类
class CYear:public CCalendar
{
private:
	int date1[6][WEEK];
	int date2[6][WEEK];
	int date3[6][WEEK];
	//按格式打印月份
	void Print(const char*week[], int date1[][WEEK], int date2[][WEEK], int date3[][WEEK], int month)const;
	//判断date数组元素值，打印相应的元素
	void Judge(const int date[][WEEK], int raw)const;
public:
	//功能选择界面
	virtual void Menu();				//覆盖CCalendar虚函数
	//查询
	virtual void SearchFor();			//覆盖CCalendar虚函数
};

//定义月历类
class CMonth:public CCalendar
{
private:
	int date4[6][WEEK] = { 0 };
	//按格式打印月份
	void Print(const char*week[], int date[][WEEK], int month)const;
	//判断date数组元素值，打印相应的元素
	void Judge(const int date[][WEEK], int raw)const;
public:
	//功能选择界面
	virtual void Menu();				//覆盖CCalendar虚函数
	//查询
	virtual void SearchFor();			//覆盖CCalendar虚函数
};

//定义日历类
class CDay :public CCalendar
{
public:
	//功能选择界面
	virtual void Menu();				//覆盖CCalendar虚函数
	//查询
	virtual void SearchFor();			//覆盖CCalendar虚函数
};
