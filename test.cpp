#include<iostream>
#include<cstdio>
#include<fstream> 
#include<ctime>
#include<string>
using namespace std;
int main() {
	cout << "测试系统已被启动..." << endl;
	cout << "按任意键以开始测试文件读入..." << endl;
	system("pause");
	system("cls");
	cout << "正在测试输入文件(test.in)..." << endl;
	ifstream fin("test.in");
	string ch;
	while (getline(fin, ch))cout << ch << endl;
	cout << endl; 
	cout << "已完成文件输入测试(test.in)..." << endl;
	cout << "按任意键以开始测试文件输出..." << endl;
	system("pause");
	system("cls");
	cout << "开始测试输出(test.out)..." << endl;
	ofstream fout("test.out");
	cout<<"请输入测试数据，以Ctrl+z结尾："<<endl;
	string ss;
	while(getline(cin,ss))fout<<ss<<endl; 
	cout << "请在测试程序结束后检查test输出是否与以上数据。。相等..." << endl;
	cout << "测试已结束" << endl;
	cout << "请在此程序结束后检查i/o文件是否删除!" << endl;
	system("pause");
	return 0;

}
