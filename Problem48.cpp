#include "stdafx.h"

namespace problem48
{
using JStd::CmdLine::CmdLine;
using namespace std;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"48", problem);

const __int64 modulo = 10000000000;
__int64 findPower(int nr)
{
	__int64 answer = 1;
	for(int i=0; i<nr; ++i)
		answer = (answer * nr) % modulo;
	return answer;
}

void problem(CmdLine& cmdLine)
{
	__int64 answer = 0;
	for(int i=1; i<=1000; ++i)
		answer = (answer + findPower(i)) % modulo;

	cout << "Answer=" << answer << endl;
}

}