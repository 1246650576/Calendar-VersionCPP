//date.cpp
#include"CDate.h"
#include<iostream>
#include<cstdlib>
using namespace std;

namespace {//namespace是下面的定义只在当前文件中有效
			
	//存储平年中某个月1日之前有多少天，为了便于getMaxDay函数实现，该数组多出一项
	const int DAYS_BEFORE_MONTH[] = { 0, 31,59,90,120,151,181,212,243,273,304,334,365 };
}

//计算某年某月某日是星期几
int CDate::CalculationWeek(int year, int month, int day)const{
	int  LastTwoYear = year % 100;	//年数的后两位
	int c = year / 100;				//世纪数的后两位
	if (month <= 2 && LastTwoYear == 0)	//查询年如果是世纪年，世纪数要减一
		c = c - 1;

	int week;						//星期数

	int ZallerYear;
	if (LastTwoYear == 0)//查询年为世纪年
		ZallerYear = (month <= 2 ? (year - 1) % 100 : LastTwoYear); //所查询年为世纪年，蔡勒年= （年数先-1）%100
	else //查询年为非世纪年
		ZallerYear = (month <= 2 ? LastTwoYear - 1 : LastTwoYear);

	//用蔡勒公式计算星期
	week = ZallerYear + (ZallerYear / 4) + (c / 4) - 2 * c + (26 * (ZellerMonth(month - 1) + 1) / 10) + day - 1;
	if (week < 0) {
		week = week - (week / 7 - 1) * 7;
	}
	else {
		week = week % 7;
	}
	return week;
}

//将月数转化为蔡勒月
int CDate::ZellerMonth(int month)const{
	return (month < 2 ? month + 13 : month + 1);
}

//构造函数
CDate::CDate(int year, int month, int day) :year(year), month(month), day(day) {
	this->week = CalculationWeek(year, month, day);
}

//获得当月有多少天
int CDate::getMaxDay()const {
	if (isLeapYear() && month == 2)
		return 29;
	else
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

//设置年，月，日
void CDate::resetYear(int year) {
	this->year = year;
	this->week = CalculationWeek(year, month, day);//更新星期
}
void CDate::resetMonth(int month) {
	this->month = month;
	this->week = CalculationWeek(year, month, day);//更新星期
}
void CDate::resetDay(int day) {
	this->day = day;
	this->week = CalculationWeek(year, month, day);//更新星期
}

