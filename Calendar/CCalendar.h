#include<iostream>
#include"CConsole.h"
#include"CDate.h"

using namespace std;
#define WEEK 7

//������������
class CCalendar: public CConsole,public CDate
{
protected:
	const char *week[WEEK] = { "��","һ","��","��","��","��","��" };
	//���ƿ���̨��������ơ���ɫ���ߴ�ȵ�
	void settingCConsole();
public:
	//����1����������������������µ����� ,����������date
	void GetDate(int week, int date[][WEEK], int MaxDay);
	//����ѡ�����
	virtual void Menu() = 0;	//���麯��
	//��ѯ
	virtual void SearchFor() = 0;//���麯��
};

//����������
class CYear:public CCalendar
{
private:
	int date1[6][WEEK];
	int date2[6][WEEK];
	int date3[6][WEEK];
	//����ʽ��ӡ�·�
	void Print(const char*week[], int date1[][WEEK], int date2[][WEEK], int date3[][WEEK], int month)const;
	//�ж�date����Ԫ��ֵ����ӡ��Ӧ��Ԫ��
	void Judge(const int date[][WEEK], int raw)const;
public:
	//����ѡ�����
	virtual void Menu();				//����CCalendar�麯��
	//��ѯ
	virtual void SearchFor();			//����CCalendar�麯��
};

//����������
class CMonth:public CCalendar
{
private:
	int date4[6][WEEK] = { 0 };
	//����ʽ��ӡ�·�
	void Print(const char*week[], int date[][WEEK], int month)const;
	//�ж�date����Ԫ��ֵ����ӡ��Ӧ��Ԫ��
	void Judge(const int date[][WEEK], int raw)const;
public:
	//����ѡ�����
	virtual void Menu();				//����CCalendar�麯��
	//��ѯ
	virtual void SearchFor();			//����CCalendar�麯��
};

//����������
class CDay :public CCalendar
{
public:
	//����ѡ�����
	virtual void Menu();				//����CCalendar�麯��
	//��ѯ
	virtual void SearchFor();			//����CCalendar�麯��
};
