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

__int64 SIGMA2_Working(__int64 n)
{
//	__int64 count1 = (__int64)sqrt((long double)n);
	__int64 count2 = n / 2;
	__int64 result = 0;
	__int64 i=1;
	for(; i <= count2; ++i)
	{
		result += i * i * (n / i);
	}
//	for(; i <= count2; ++i)
//	{
//		result += i * i * 2;
//	}
	for(; i <= n; ++i)
		result += i * i;
	return result;
}

__int64 JSigma(__int64 begin, __int64 end, __int64 factor)
{
	return (1 + end - begin) * (end + begin) / 2;
}

__int64 SIGMA2(__int64 n)
{
	__int64 count2 = n / 2;
	__int64 i = 1;
	__int64 divResult = n / i;
	for(__int64 i = 1; i <= count2; i += divResult);
	return 0;
/*
	__int64 count1 = (__int64)sqrt((long double)n);
	__int64 result = 0;
	for(; i <= count2; ++i)
	{
		int u1 = i*n;
		int u2 = i*i*(n/i);
		if(u1 != u2)
			cout << "i=" << i << ", n=" << n << " " << u1 << " " << u2 << endl;
		result += i * n;
//		result += i * i * (n / i);
	}
	for(; i <= count2; ++i)
	{
		result += i * i * 2;
	}
	for(; i <= n; ++i)
		result += i * i;
	return result;
*/
}

void problem(CmdLine& cmdLine)
{
	JSigma(10, 21, 1);

	cout << "Solving..." << endl;

	__int64 n = 10;
	//for(n=1; n <= 60; ++n)
		cout << "SIGMA(" << n << ") = " << SIGMA2(n) << " - Should be: " << SIGMA2_Working(n) << endl;
}

}
