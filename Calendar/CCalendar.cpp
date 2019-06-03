#include"CCalendar.h"
#include<iomanip>

//CCalendar��ľ���ʵ��

//����1����������������������µ����� ,����������date
void CCalendar::GetDate(int week, int date[][WEEK], int MaxDay){
	int d = 1;	//ÿ��1��
	for (int raw = 0; raw < 6; raw++) {
		int col;
		for (col = 0; col < WEEK; col++) {
			if ((raw == 0 && col >= week) || (raw > 0 && col >= 0)) {
				date[raw][col] = d;
				d++;
			}
			if (date[raw][col] >= MaxDay)
				break;
		}
		if (date[raw][col] >= MaxDay)
			break;
	}
}

//���ƿ���̨��������ơ���ɫ���ߴ�ȵ�
void CCalendar::settingCConsole() {
	CConsole::HideCursor(true);
	CConsole::SetTitle("��������ѯ");
	CConsole::SetColor("5f");
	CConsole::SetSize(35, 25);
}

//CYear��ľ���ʵ��

//����ѡ�����
void CYear::Menu() {
	int n = 1;
	while (n) {
		CleanScreen();	  //����
		settingCConsole();//���ÿ���̨
		cout <<endl
			 <<" �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
			 <<" �U-----------������-------------�U\n"
			 <<" �U------------------------------�U\n"
			 <<" �U------------------------------�U\n"
			 <<" �U--------����ߣ�����--------�U\n"
			 <<" �U------------------------------�U\n"
			 <<" �U------------------------------�U\n"
			 <<" �U------------------------------�U\n"
			 <<" �U-----��ӭʹ��������ѯϵͳ-----�U\n"
			 <<" �U-----�ɹ���ѯ������ ----------�U\n"
			 <<" �U-----1582�ꡪ��9999��---------�U\n"
			 <<" �U--------- ��1��ѯ��-----------�U\n"
			 <<" �U--------- ��0�˳�! -----------�U\n"
			 <<" �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n"
			 <<"��ѡ���ܼ���";
		cin >> n;

		//�Զ����������Ϸ��Լ��
		if (n > 1 || n < 0) {	
			cout <<"�������";
		}
		else {
			switch (n)
			{
			case 0: cout <<"\n ����������\n";
				n = 0;
				break;
			case 1: SearchFor();
				break;
			}
		}
	}
}

//��ѯ
void CYear::SearchFor()
{
	cout <<"������Ҫ��ѯ����ݣ�";
	int year; 
	cin >> year;
	resetYear(year);

	CleanScreen();  //����
	SetSize(85, 40);//���ÿ���̨��С
	cout<<"\n\t ==========================="<< getYear() <<"��Calendar===========================\n\n";

	//�� 4 x 3 �ĸ�ʽ��ӡ����
	for (int raw = 0; raw < 4; raw++)
	{
		//��ʼ������
		for (int raw = 0; raw < 6; raw++) {
			for (int col = 0; col < WEEK; col++) {

				date1[raw][col] =  0 ;
				date2[raw][col] =  0 ;
				date3[raw][col] =  0 ;
			}
		}
		
		GetDate(getWeek(), date1, getMaxDay());

		resetMonth(getMonth() + 1);//ʹ�·���һ
		GetDate(getWeek(), date2, getMaxDay());

		resetMonth(getMonth() + 1);//ʹ�·���һ
		GetDate(getWeek(), date3, getMaxDay());
		Print(CCalendar::week, date1, date2, date3, getMonth() - 2);

		resetMonth(getMonth() + 1);//ʹ�·���һ
	}
	resetMonth(1);
	PauseScreen();//������Ļ
}

//����ʽ��ӡ�·�
void CYear::Print(const char*week[], int date1[][WEEK], int date2[][WEEK], int date3[][WEEK], int month)const{
	//��ӡ�¡�1�¡�����2�¡�......
	cout <<"\t";
	for (int i = 0; i < 3; i++)
		cout <<" "<< month++ <<"��                 \t";
	cout << endl;


	//��ӡ���� "��","һ","��","��","��","��","��"
	cout << "\t";
	for (int j = 0; j < 3; j++) {
		for (int col = 0; col < WEEK; col++)
			cout <<" "<< week[col];

		cout << "\t";
	}
	cout << endl;

	/* ��ӡ��
		  1  2  3  4  5  6  7              1  2  3  4                       1
		  8  9 10 11 12 13 14     5  6  7  8  9 10 11     2  3  4  5  6  7  8
		 15 16 17 18 19 20 21    12 13 14 15 16 17 18     9 10 11 12 13 14 15
		 22 23 24 25 26 27 28    19 20 21 22 23 24 25    16 17 18 19 20 21 22
		 29 30 31                26 27 28 29 30 31       23 24 25 26 27 28 29
														 30*/
	for (int raw = 0; raw < 6; raw++) {
		cout << "\t";
		Judge(date1, raw);
		Judge(date2, raw);
		Judge(date3, raw);
		cout << endl;
	}
}

//�ж�date����Ԫ��ֵ����ӡ��Ӧ��Ԫ��
void CYear::Judge(const int date[][WEEK], int raw)const {
	for (int col = 0; col < WEEK; col++) {
		if (date[raw][col] == 0)
			cout << "   ";
		else
			cout << setw(3) << date[raw][col];
	}
	cout << "\t";
}

//CMonth��ľ���ʵ��
//����ѡ�����
void CMonth::Menu() {
	int n = 1;
	while (n) {
		CleanScreen();		//����
		settingCConsole();  //���ÿ���̨
		cout<<endl
			<< " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
			<< " �U-----------������-------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U--------����ߣ�����--------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U-----��ӭʹ��������ѯϵͳ-----�U\n"
			<< " �U-------�ɹ���ѯ������ --------�U\n"
			<< " �U--------1�¡���12��-----------�U\n"
			<< " �U--------- ��1��ѯ��-----------�U\n"
			<< " �U--------- ��0�˳�! -----------�U\n"
			<< " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n"
			<< "��ѡ���ܼ���";
		cin >> n;

		//�Զ����������Ϸ��Լ��
		if (n > 1 || n < 0) {
			cout << "�������";
		}
		else {
			switch (n)
			{
			case 0: cout << "\n ����������\n";
				n = 0;
				break;
			case 1: SearchFor();
				break;
			}
		}
	}
}
//����
void CMonth::SearchFor() {

	cout << "������Ҫ��ѯ����ݺ��·ݣ�(��ʽ�磺2019 2)\n";
	int year, month;
	cin >> year >> month;
	resetYear(year);
	resetMonth(month);

	GetDate(getWeek(), date4, getMaxDay());
	CleanScreen();//����
	cout<<"\n\n--------------"<<getYear()<<" ��--------------\n";
	Print(CCalendar::week, date4, getMonth());
	cout << endl;
	PauseScreen();//������Ļ
}

//����ʽ��ӡ�·�
void CMonth::Print(const char*week[], int date[][WEEK], int month) const{
	cout << endl<<endl;
	cout << "       ";
	cout << getMonth() << "  ��\n";

	cout << "      ";
	for (int col = 0; col < WEEK; col++)
		cout << " " << week[col];
	cout << endl;

	for (int raw = 0; raw < 6; raw++){
		cout << "      ";
		Judge(date4, raw);
		cout << endl;
	}
}
//�ж�date����Ԫ��ֵ����ӡ��Ӧ��Ԫ��
void CMonth::Judge(const int date[][WEEK], int raw) const{
	for (int col = 0; col < WEEK; col++) {
		if (date[raw][col] == 0)
			cout << "   ";
		else
			cout << setw(3) << date[raw][col];
	}
	cout << "\t";
}
//CDay��ľ���ʵ��
//����ѡ�����
void CDay::Menu() {
	int n = 1;
	while (n) {
		CleanScreen();	  //����
		settingCConsole();//���ÿ���̨
		cout<<endl
			<< " �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n"
			<< " �U-----------������-------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U--------����ߣ�����--------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U------------------------------�U\n"
			<< " �U-----��ӭʹ��������ѯϵͳ-----�U\n"
			<< " �U-----�ɹ���ѯ������ ----------�U\n"
			<< " �U------1�ա���28/29/30/31��----�U\n"
			<< " �U--------- ��1��ѯ��-----------�U\n"
			<< " �U--------- ��0�˳�! -----------�U\n"
			<< " �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n"
			<< "��ѡ���ܼ���";
		cin >> n;

		//�Զ����������Ϸ��Լ��
		if (n > 1 || n < 0) {
			cout << "�������";
		}
		else {
			switch (n)
			{
			case 0: cout << "\n ����������\n";
				n = 0;
				break;
			case 1: SearchFor();
				break;
			}
		}
	}
}

//����
void CDay::SearchFor()
{
	cout <<"������Ҫ��ѯ����ݺ��·��Լ��գ�(��ʽ�磺2019 2 1)\n";
	int year, month, day;
	cin >> year >> month >> day;
	resetYear(year);
	resetMonth(month);
	resetDay(day);

	cout << endl;
	cout << getYear() << "��" << getMonth() << "��" << getDay() << "��   ";
	switch (getWeek())
	{
	case 0: cout <<"������"; break;
	case 1: cout <<"����һ"; break;
	case 2: cout <<"���ڶ�"; break;
	case 3: cout <<"������"; break;
	case 4: cout <<"������"; break;
	case 5: cout <<"������"; break;
	case 6: cout <<"������"; break;
	}
	cout << endl;
	PauseScreen();//������Ļ
}

