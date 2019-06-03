//date.cpp
#include"CDate.h"
#include<iostream>
#include<cstdlib>
using namespace std;

namespace {//namespace������Ķ���ֻ�ڵ�ǰ�ļ�����Ч
			
	//�洢ƽ����ĳ����1��֮ǰ�ж����죬Ϊ�˱���getMaxDay����ʵ�֣���������һ��
	const int DAYS_BEFORE_MONTH[] = { 0, 31,59,90,120,151,181,212,243,273,304,334,365 };
}

//����ĳ��ĳ��ĳ�������ڼ�
int CDate::CalculationWeek(int year, int month, int day)const{
	int  LastTwoYear = year % 100;	//�����ĺ���λ
	int c = year / 100;				//�������ĺ���λ
	if (month <= 2 && LastTwoYear == 0)	//��ѯ������������꣬������Ҫ��һ
		c = c - 1;

	int week;						//������

	int ZallerYear;
	if (LastTwoYear == 0)//��ѯ��Ϊ������
		ZallerYear = (month <= 2 ? (year - 1) % 100 : LastTwoYear); //����ѯ��Ϊ�����꣬������= ��������-1��%100
	else //��ѯ��Ϊ��������
		ZallerYear = (month <= 2 ? LastTwoYear - 1 : LastTwoYear);

	//�ò��չ�ʽ��������
	week = ZallerYear + (ZallerYear / 4) + (c / 4) - 2 * c + (26 * (ZellerMonth(month - 1) + 1) / 10) + day - 1;
	if (week < 0) {
		week = week - (week / 7 - 1) * 7;
	}
	else {
		week = week % 7;
	}
	return week;
}

//������ת��Ϊ������
int CDate::ZellerMonth(int month)const{
	return (month < 2 ? month + 13 : month + 1);
}

//���캯��
CDate::CDate(int year, int month, int day) :year(year), month(month), day(day) {
	this->week = CalculationWeek(year, month, day);
}

//��õ����ж�����
int CDate::getMaxDay()const {
	if (isLeapYear() && month == 2)
		return 29;
	else
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
}

//�����꣬�£���
void CDate::resetYear(int year) {
	this->year = year;
	this->week = CalculationWeek(year, month, day);//��������
}
void CDate::resetMonth(int month) {
	this->month = month;
	this->week = CalculationWeek(year, month, day);//��������
}
void CDate::resetDay(int day) {
	this->day = day;
	this->week = CalculationWeek(year, month, day);//��������
}

