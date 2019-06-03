#pragma once

#ifndef __DATE_H__
#define __DATE_H__

class CDate {//日期类
private://私有成员
	int year;	//年
	int month;	//月
	int day;	//日
	int week;	//星期（0,1,2,3,4,5,6 ="日","一","二","三","四","五","六"）

	//计算计算某年某月某日是星期几；构造对象，重新设置年，月，日会被调用
	int CalculationWeek(int year, int month, int day)const;
	//将月数转化为蔡勒月
	int ZellerMonth(int month)const;

public://外部接口
	CDate(int year = 1, int month = 1, int day = 1);//用年月日构造日期

	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }
	int getWeek()const { return week; }
	int getMaxDay()const;//获得当月有多少天
	
	//设置年，月，日
	void resetYear(int year);
	void resetMonth(int month);
	void resetDay(int day);
	//判断当年是否为闰年
	bool isLeapYear()const {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
};

#endif __DATE_H__