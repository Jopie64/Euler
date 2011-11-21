// Euler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	JStd::CmdLine::CallDefaultWithCatch(wcerr, argc, argv);
//#ifdef _DEBUG
	cin.get();
//#endif
	return 0;
}

