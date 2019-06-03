#include "CTime.h"
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//��ȡ��ǰʱ��
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
//��ʾ��ǰʱ��
void CTime::showTime() {
	const char* WEEK[7] = { "������" ,"����һ","���ڶ�","������","������","������","������"};
	getTime();
	int ssecond = second;
	do {
		getTime();
		cout << setw(2) << hour << ":" 
			 << setw(2) << minute << ":" 
			<< setw(2) << second << endl;
		cout << getYear() << "��" << getMonth() << "��" << getDay() << "��" << "   " << WEEK[getWeek()] << endl;
		cout << endl << endl << endl << endl << "       ��ӭʹ����������ѯϵͳ" << endl<<endl
			<< "              ������..." << endl;
		
		//�ӳ�
		for (unsigned int i = 0; i < 333911402; i++) {

		}
		CleanScreen(); //����

		//��������ʱ��Ϊ10��
	} while ((abs(second - ssecond) <= 10 || abs(second - ssecond) >= 50));
}

//���ƿ���̨��������ơ���ɫ���ߴ�ȵ�
void CTime::settingCConsole() {
	CConsole::HideCursor(true);
	CConsole::SetTitle("��������ѯϵͳ");
	CConsole::SetColor("5f");
	CConsole::SetSize(35, 25);
}