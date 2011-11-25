#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem2
{
using JStd::CmdLine::CmdLine;
using namespace std;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"2", problem);

const int nbFibs = 2;
void problem(CmdLine& cmdLine)
{
	long long sum = 0;
	int fib[nbFibs] = {0,1};
	int fibIx = 0;
	while(fib[fibIx] < 4000000)
	{
		int newFib = 0;
		for(int i=0; i<nbFibs; ++i)
			newFib += fib[i];
		if(newFib%2 == 0) sum += newFib;
		++fibIx; if(fibIx >= nbFibs) fibIx = 0;
		fib[fibIx] = newFib;
	}
	cout << "Answer=" << sum << endl;
}

}