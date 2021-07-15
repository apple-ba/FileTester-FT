//variables.cpp: 实现文件
//

#include "variables.h"
#include "pch.h"
using namespace std;


char* UnicodeToAnsi(CString unicode)
{
	wchar_t* srcStr = unicode.AllocSysString();
	int nLen = WideCharToMultiByte(CP_ACP, 0, srcStr, -1, NULL, 0, NULL, NULL);
	if (nLen)
	{
		char* p = new char[nLen];
		WideCharToMultiByte(CP_ACP, 0, srcStr, -1, p, nLen, NULL, NULL);
		return p;
	}
}


CString AnsiToUnicode(const char* srcStr)
{
	int nLen = MultiByteToWideChar(CP_ACP, 0, srcStr, -1, NULL, 0);
	if (nLen)
	{
		wchar_t* pUnicode = new wchar_t[nLen];
		MultiByteToWideChar(CP_ACP, 0, srcStr, -1, pUnicode, nLen);
		return CString(pUnicode);
	}
}


string sPath;
string sExename;
string sIoname;
string sInput;
string sOutput;
string sFrom = "0";
string sTo = "0";
string sNumberChoose = "0";
string sInputFileName = ".in";
string sOutputFileName = ".out";
string sAnswerFileName = ".ans";

void save(char* path)
{
	ofstream _fout(path,ios::out|ios::trunc);
	

	_fout << sPath << endl;
	_fout << sExename << endl;
	_fout << sIoname << endl;
	_fout << sInput << endl;
	_fout << sOutput << endl;
	_fout << sFrom << endl;
	_fout << sTo << endl;
	_fout << sNumberChoose << endl;
	_fout << sInputFileName << endl;
	_fout << sOutputFileName << endl;
	_fout << sAnswerFileName << endl;

	_fout.close();
}

void read(char* path)
{
	ifstream fin(path,ios::in);

	if (!fin.is_open())return;
	getline(fin, sPath);
	getline(fin, sExename);
	getline(fin, sIoname);
	getline(fin, sInput);
	getline(fin, sOutput);
	getline(fin, sFrom);
	getline(fin, sTo);
	getline(fin, sNumberChoose);
	getline(fin, sInputFileName);
	getline(fin, sOutputFileName);
	getline(fin, sAnswerFileName);

}
