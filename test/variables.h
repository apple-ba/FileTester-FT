//variables.h: 变量的头文件

#pragma once

#include "pch.h"
using namespace std;

char* UnicodeToAnsi(CString);
CString AnsiToUnicode(const char*);

extern string sPath;
extern string sExename;
extern string sIoname;
extern string sInput;
extern string sOutput;
extern string sFrom;
extern string sTo;
extern string sNumberChoose;
extern string sInputFileName;
extern string sOutputFileName;
extern string sAnswerFileName;

void save(char*);

void read(char*);

#define _save() save("%APPDATA%\\FileTester\\temp.ftconfig")
#define _read() read("%APPDATA%\\FileTester\\temp.ftconfig")
