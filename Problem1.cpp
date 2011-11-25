#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem1
{
using JStd::CmdLine::CmdLine;
using namespace std;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"1", problem);

void problem(CmdLine& cmdLine)
{
	int sum = 0;
	for(int i = 0; i < 1000; ++i)
		if(i%3 == 0 || i%5 == 0) sum += i;
	cout << "Answer=" << sum << endl;
}

}