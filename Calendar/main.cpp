#include<iostream>
#include"CCalendar.h"
#include"CTime.h"
using namespace std;

void Introduction();
int main() {
	//定义类的对象
	CTime time;
	CYear year;
	CMonth month;
	CDay day;

	//定义指向派生类的基类指针
	CCalendar *CCalendar_Year = &year;
	CCalendar *CCalendar_Month = &month;
	CCalendar *CCalendar_Day= &day;
	
	//设置控制台
	time.settingCConsole();
	time.showTime();
	
	//主菜单项
	int n = 1;
	while (n)
	{
		cout << endl;
		cout<< " ╔══════════════════════════════╗\n"
			<< " ║-----------万年历-------------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║-------设计者：翟翊君 --------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║-------------关于------------1║\n"
			<< " ║-----------年历查询----------2║\n"
			<< " ║-----------月历查询----------3║\n"
			<< " ║-----------日历查询----------4║\n"
			<< " ║---------- 按0退出! ---------0║\n"
			<< " ║------------------------------║\n"
			<< " ╚══════════════════════════════╝\n\n"
			<< "请选择功能键：";
		cin >> n;
		if (n > 4 || n < 0) {
			cout << "输入错误" << endl;
		}
		else {
			switch (n)
			{
			case 0: cout << "\n 返回主界面\n";
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
//程序信息关于项
void Introduction() {
	system("CLS");		//清屏
	cout << endl
		<< " ╔══════════════════════════════╗\n"
		<< " ║-------- Indroduction --------║\n"
		<< " ║----Program name: Calendar----║\n"
		<< " ║---------Version: 2.0---------║\n"
		<< " ║-------Date: 2019.5.25--------║\n"
		<< " ║--------Author:翟翊君---------║\n"
		<< " ║---------Class:1807-----------║\n"
		<< " ║------Number:8002118184-------║\n"
		<< " ║----Copyright: 2019-2020------║\n"
		<< " ║------------------------------║\n"
		<< " ║-Description:此程序文件完主要-║\n"
		<< " ║-实现年历查询,月历查询,日历查-║\n"
		<< " ║---询功能,以及时间显示功能----║\n"
		<< " ║------------------------------║\n"
		<< " ║-History: 2019.5.26在原来年历-║\n"
		<< " ║-查询基础上,增加了程序启动界面║\n"
		<< " ║------------------------------║\n"
		<< " ╚══════════════════════════════╝\n\n";
	system("pause");
}