#include<iostream>
#include"CCalendar.h"
#include"CTime.h"
using namespace std;

void Introduction();
int main() {
	//������Ķ���
	CTime time;
	CYear year;
	CMonth month;
	CDay day;

	//����ָ��������Ļ���ָ��
	CCalendar *CCalendar_Year = &year;
	CCalendar *CCalendar_Month = &month;
	CCalendar *CCalendar_Day= &day;
	
	//���ÿ���̨
	time.settingCConsole();
	time.showTime();
	
	//���˵���
	int n = 1;
	while (n)
	{
		cout << endl;
		cout<< " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
			<< " �U-----------������-------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U-------����ߣ����� --------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U-------------����------------1�U\n"
			<< " �U-----------������ѯ----------2�U\n"
			<< " �U-----------������ѯ----------3�U\n"
			<< " �U-----------������ѯ----------4�U\n"
			<< " �U---------- ��0�˳�! ---------0�U\n"
			<< " �U------------------------------�U\n"
			<< " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n"
			<< "��ѡ���ܼ���";
		cin >> n;
		if (n > 4 || n < 0) {
			cout << "�������" << endl;
		}
		else {
			switch (n)
			{
			case 0: cout << "\n ����������\n";
				n = 0;
				break;
			case 1: Introduction();
				break;
			case 2:	CCalendar_Year->Menu();
				break;
			case 3: CCalendar_Month->Menu();
				break;
			case 4: CCalendar_Day->Menu();
				break;
			}
		}
		system("CLS");
	}
	return 0;
}
//������Ϣ������
void Introduction() {
	system("CLS");		//����
	cout << endl
		<< " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
		<< " �U-------- Indroduction --------�U\n"
		<< " �U----Program name: Calendar----�U\n"
		<< " �U---------Version: 2.0---------�U\n"
		<< " �U-------Date: 2019.5.25--------�U\n"
		<< " �U--------Author:����---------�U\n"
		<< " �U---------Class:1807-----------�U\n"
		<< " �U------Number:8002118184-------�U\n"
		<< " �U----Copyright: 2019-2020------�U\n"
		<< " �U------------------------------�U\n"
		<< " �U-Description:�˳����ļ�����Ҫ-�U\n"
		<< " �U-ʵ��������ѯ,������ѯ,������-�U\n"
		<< " �U---ѯ����,�Լ�ʱ����ʾ����----�U\n"
		<< " �U------------------------------�U\n"
		<< " �U-History: 2019.5.26��ԭ������-�U\n"
		<< " �U-��ѯ������,�����˳�����������U\n"
		<< " �U------------------------------�U\n"
		<< " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n";
	system("pause");
}