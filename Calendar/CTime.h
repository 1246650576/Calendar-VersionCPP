#ifndef __MYTIME_H__
#define __MYTIME_H__

#include"CDate.h"
#include "CConsole.h"
using namespace std;

//����ʱ����
class CTime:public CDate,public CConsole
{
public://�ⲿ�ӿ�
	//��ʾ��ǰʱ��
	void showTime();
	//���ƿ���̨��������ơ���ɫ���ߴ�ȵ�
	void settingCConsole();

protected://������Ա
	int hour;	//ʱ
	int minute;	//��
	int second;	//��

private://˽�г�Ա
	//��ȡ��ǰʱ��
	void getTime();
};
#endif __MYTIME_H__