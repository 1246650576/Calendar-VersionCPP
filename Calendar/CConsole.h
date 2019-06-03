#pragma once
#ifndef CCONSOLE_H
#define CCONSOLE_H

#include "windows.h"	// HANDLE
#include <cstdio>		// sprintf

class CConsole
{
private://˽�г�Ա
	COORD coord;
	HANDLE HConsole;

public://�ⲿ�ӿ�
	CConsole();	//���캯��
	~CConsole();//��������

	void SetCoord(int x, int y);		//���������λ��
	void HideCursor(bool hide);			//��꿪����ر�
	void SetTitle(const char* title);	//���ñ�������
	void SetSize(int width, int height);//���ÿ���̨��С
	void SetColor(const char* cl);		//������ɫ
	void CleanScreen(void);				//����
	void PauseScreen(void);				//������Ļ
	
	//��Ԫ��������
	//friend void Introduction();			//������Ϣ����
};

#endif