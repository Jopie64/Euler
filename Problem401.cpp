#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem401
{
using JStd::CmdLine::CmdLine;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"401", problem);

using namespace std;
using namespace JStd;

__int64 SIGMA2(__int64 n)
{
//	__int64 count = (__int64)sqrt((long double)n);
	__int64 count = n / 2;
	__int64 result = 0;
	__int64 i=1;
	for(; i <= count; ++i)
	{
		result += i * i * (n / i);
	}
	for(; i <= n; ++i)
		result += i * i;
	return result;
}

void problem(CmdLine& cmdLine)
{
	cout << "Solving..." << endl;

	__int64 n = 6;
	for(n=1; n <= 6; ++n)
		cout << "SIGMA(" << n << ") = " << SIGMA2(n) << endl;
}

}
