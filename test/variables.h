//¥¢¥Ê±‰¡ø

#pragma once

#include "pch.h"
#include <string>
using namespace std;

char* UnicodeToAnsi(CString);
CString AnsiToUnicode(const char*);

extern string sPath;
extern string sExename;
extern string sIoname;
extern string sInput;
extern string sOutput;
extern int iFrom;
extern int iTo;

