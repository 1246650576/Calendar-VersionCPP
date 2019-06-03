#include"CCalendar.h"
#include<iomanip>

//CCalendar类的具体实现

//根据1日所在星期数，生成这个月的日期 ,并存于数组date
void CCalendar::GetDate(int week, int date[][WEEK], int MaxDay){
	int d = 1;	//每月1日
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

//定制控制台界面的名称、颜色、尺寸等等
void CCalendar::settingCConsole() {
	CConsole::HideCursor(true);
	CConsole::SetTitle("万年历查询");
	CConsole::SetColor("5f");
	CConsole::SetSize(35, 25);
}

//CYear类的具体实现

//功能选择界面
void CYear::Menu() {
	int n = 1;
	while (n) {
		CleanScreen();	  //清屏
		settingCConsole();//设置控制台
		cout <<endl
			 <<" ╔══════════════════════════════╗\n"
			 <<" ║-----------万年历-------------║\n"
			 <<" ║------------------------------║\n"
			 <<" ║------------------------------║\n"
			 <<" ║--------设计者：翟翊君--------║\n"
			 <<" ║------------------------------║\n"
			 <<" ║------------------------------║\n"
			 <<" ║------------------------------║\n"
			 <<" ║-----欢迎使用年历查询系统-----║\n"
			 <<" ║-----可供查询的年历 ----------║\n"
			 <<" ║-----1582年——9999年---------║\n"
			 <<" ║--------- 按1查询！-----------║\n"
			 <<" ║--------- 按0退出! -----------║\n"
			 <<" ╚══════════════════════════════╝\n\n"
			 <<"请选择功能键：";
		cin >> n;

		//对读入数据做合法性检查
		if (n > 1 || n < 0) {	
			cout <<"输入错误";
		}
		else {
			switch (n)
			{
			case 0: cout <<"\n 返回主界面\n";
				n = 0;
				break;
			case 1: SearchFor();
				break;
			}
		}
	}
}

//查询
void CYear::SearchFor()
{
	cout <<"请输入要查询的年份：";
	int year; 
	cin >> year;
	resetYear(year);

	CleanScreen();  //清屏
	SetSize(85, 40);//设置控制台大小
	cout<<"\n\t ==========================="<< getYear() <<"年Calendar===========================\n\n";

	//以 4 x 3 的格式打印日历
	for (int raw = 0; raw < 4; raw++)
	{
		//初始化数组
		for (int raw = 0; raw < 6; raw++) {
			for (int col = 0; col < WEEK; col++) {

				date1[raw][col] =  0 ;
				date2[raw][col] =  0 ;
				date3[raw][col] =  0 ;
			}
		}
		
		GetDate(getWeek(), date1, getMaxDay());

		resetMonth(getMonth() + 1);//使月份增一
		GetDate(getWeek(), date2, getMaxDay());

		resetMonth(getMonth() + 1);//使月份增一
		GetDate(getWeek(), date3, getMaxDay());
		Print(CCalendar::week, date1, date2, date3, getMonth() - 2);

		resetMonth(getMonth() + 1);//使月份增一
	}
	resetMonth(1);
	PauseScreen();//冻结屏幕
}

//按格式打印月份
void CYear::Print(const char*week[], int date1[][WEEK], int date2[][WEEK], int date3[][WEEK], int month)const{
	//打印月“1月”，“2月”......
	cout <<"\t";
	for (int i = 0; i < 3; i++)
		cout <<" "<< month++ <<"月                 \t";
	cout << endl;


	//打印星期 "日","一","二","三","四","五","六"
	cout << "\t";
	for (int j = 0; j < 3; j++) {
		for (int col = 0; col < WEEK; col++)
			cout <<" "<< week[col];

		cout << "\t";
	}
	cout << endl;

	/* 打印日
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

//判断date数组元素值，打印相应的元素
void CYear::Judge(const int date[][WEEK], int raw)const {
	for (int col = 0; col < WEEK; col++) {
		if (date[raw][col] == 0)
			cout << "   ";
		else
			cout << setw(3) << date[raw][col];
	}
	cout << "\t";
}

//CMonth类的具体实现
//功能选择界面
void CMonth::Menu() {
	int n = 1;
	while (n) {
		CleanScreen();		//清屏
		settingCConsole();  //设置控制台
		cout<<endl
			<< " ╔══════════════════════════════╗\n"
			<< " ║-----------万年历-------------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║--------设计者：翟翊君--------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║-----欢迎使用年历查询系统-----║\n"
			<< " ║-------可供查询的月历 --------║\n"
			<< " ║--------1月——12月-----------║\n"
			<< " ║--------- 按1查询！-----------║\n"
			<< " ║--------- 按0退出! -----------║\n"
			<< " ╚══════════════════════════════╝\n\n"
			<< "请选择功能键：";
		cin >> n;

		//对读入数据做合法性检查
		if (n > 1 || n < 0) {
			cout << "输入错误";
		}
		else {
			switch (n)
			{
			case 0: cout << "\n 返回主界面\n";
				n = 0;
				break;
			case 1: SearchFor();
				break;
			}
		}
	}
}
//查找
void CMonth::SearchFor() {

	cout << "请输入要查询的年份和月份：(格式如：2019 2)\n";
	int year, month;
	cin >> year >> month;
	resetYear(year);
	resetMonth(month);

	GetDate(getWeek(), date4, getMaxDay());
	CleanScreen();//清屏
	cout<<"\n\n--------------"<<getYear()<<" 年--------------\n";
	Print(CCalendar::week, date4, getMonth());
	cout << endl;
	PauseScreen();//冻结屏幕
}

//按格式打印月份
void CMonth::Print(const char*week[], int date[][WEEK], int month) const{
	cout << endl<<endl;
	cout << "       ";
	cout << getMonth() << "  月\n";

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
//判断date数组元素值，打印相应的元素
void CMonth::Judge(const int date[][WEEK], int raw) const{
	for (int col = 0; col < WEEK; col++) {
		if (date[raw][col] == 0)
			cout << "   ";
		else
			cout << setw(3) << date[raw][col];
	}
	cout << "\t";
}
//CDay类的具体实现
//功能选择界面
void CDay::Menu() {
	int n = 1;
	while (n) {
		CleanScreen();	  //清屏
		settingCConsole();//设置控制台
		cout<<endl
			<< " ╔══════════════════════════════╗\n"
			<< " ║-----------万年历-------------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║--------设计者：翟翊君--------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║------------------------------║\n"
			<< " ║-----欢迎使用年历查询系统-----║\n"
			<< " ║-----可供查询的日历 ----------║\n"
			<< " ║------1日——28/29/30/31日----║\n"
			<< " ║--------- 按1查询！-----------║\n"
			<< " ║--------- 按0退出! -----------║\n"
			<< " ╚══════════════════════════════╝\n\n"
			<< "请选择功能键：";
		cin >> n;

		//对读入数据做合法性检查
		if (n > 1 || n < 0) {
			cout << "输入错误";
		}
		else {
			switch (n)
			{
			case 0: cout << "\n 返回主界面\n";
				n = 0;
				break;
			case 1: SearchFor();
				break;
			}
		}
	}
}

//查找
void CDay::SearchFor()
{
	cout <<"请输入要查询的年份和月份以及日：(格式如：2019 2 1)\n";
	int year, month, day;
	cin >> year >> month >> day;
	resetYear(year);
	resetMonth(month);
	resetDay(day);

	cout << endl;
	cout << getYear() << "年" << getMonth() << "月" << getDay() << "日   ";
	switch (getWeek())
	{
	case 0: cout <<"星期日"; break;
	case 1: cout <<"星期一"; break;
	case 2: cout <<"星期二"; break;
	case 3: cout <<"星期三"; break;
	case 4: cout <<"星期四"; break;
	case 5: cout <<"星期五"; break;
	case 6: cout <<"星期六"; break;
	}
	cout << endl;
	PauseScreen();//冻结屏幕
}

