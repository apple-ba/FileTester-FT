#include<iostream>
#include<cstdio>
#include<fstream> 
#include<ctime>
using namespace std;
int main() {
	cout << "����ϵͳ�ѱ�����..." << endl;
	cout << "��������Կ�ʼ�����ļ�����..." << endl;
	system("pause");
	system("cls");
	cout << "���ڲ��������ļ�(test.in)..." << endl;
	ifstream fin("test.in");
	char ch;
	while (fin >> ch)cout << ch;
	cout << endl; 
	cout << "������ļ��������(test.in)..." << endl;
	cout << "��������Կ�ʼ�����ļ����..." << endl;
	system("pause");
	system("cls");
	cout << "��ʼ�������(test.out)..." << endl;
	ofstream fout("test.out");
	int a = time(NULL);
	fout << a << endl;
	cout << "���ڲ��Գ����������test����Ƿ���������ֵ���..." << endl;
	cout << a << endl;
	cout << "�����ѽ���" << endl;
	cout << "���ڴ˳����������i/o�ļ��Ƿ�ɾ��!" << endl;
	system("pause");
	return 0;

}
