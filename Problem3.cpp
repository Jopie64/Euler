#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem3
{
using JStd::CmdLine::CmdLine;
using namespace std;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"3", problem);

long long findLargestPrime(long long number)
{
	long long answer = (long long)sqrt((double)number);
	if(!(answer & 0x1)) ++answer;
	while(answer > 0)
	{
		answer -= 2;
		if(number % answer == 0 && findLargestPrime(answer) == 1)
			break;
	}
	if(answer < 1)
		return 1;
	return answer;
}

void problem(CmdLine& cmdLine)
{
	cout << "Answer=" << findLargestPrime(600851475143) << endl;
}

}