#pragma once

#ifndef __DATE_H__
#define __DATE_H__

class CDate {//������
private://˽�г�Ա
	int year;	//��
	int month;	//��
	int day;	//��
	int week;	//���ڣ�0,1,2,3,4,5,6 ="��","һ","��","��","��","��","��"��

	//�������ĳ��ĳ��ĳ�������ڼ�������������������꣬�£��ջᱻ����
	int CalculationWeek(int year, int month, int day)const;
	//������ת��Ϊ������
	int ZellerMonth(int month)const;

public://�ⲿ�ӿ�
	CDate(int year = 1, int month = 1, int day = 1);//�������չ�������

	int getYear()const { return year; }
	int getMonth()const { return month; }
	int getDay()const { return day; }
	int getWeek()const { return week; }
	int getMaxDay()const;//��õ����ж�����
	
	//�����꣬�£���
	void resetYear(int year);
	void resetMonth(int month);
	void resetDay(int day);
	//�жϵ����Ƿ�Ϊ����
	bool isLeapYear()const {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	}
};

#endif __DATE_H__