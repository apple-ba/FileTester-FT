#include<iostream>
#include<cstdio>
#include<fstream> 
#include<ctime>
#include<string>
using namespace std;
int main() {
	cout << "����ϵͳ�ѱ�����..." << endl;
	cout << "��������Կ�ʼ�����ļ�����..." << endl;
	system("pause");
	system("cls");
	cout << "���ڲ��������ļ�(test.in)..." << endl;
	ifstream fin("test.in");
	string ch;
	while (getline(fin, ch))cout << ch << endl;
	cout << endl; 
	cout << "������ļ��������(test.in)..." << endl;
	cout << "��������Կ�ʼ�����ļ����..." << endl;
	system("pause");
	system("cls");
	cout << "��ʼ�������(test.out)..." << endl;
	ofstream fout("test.out");
	cout<<"������������ݣ���Ctrl+z��β��"<<endl;
	string ss;
	while(getline(cin,ss))fout<<ss<<endl; 
	cout << "���ڲ��Գ����������test����Ƿ����������ݡ������..." << endl;
	cout << "�����ѽ���" << endl;
	cout << "���ڴ˳����������i/o�ļ��Ƿ�ɾ��!" << endl;
	system("pause");
	return 0;

}
