#include "stdafx.h"
#include <vector>
#include <cmath>
#include <cstdio>

namespace pi
{
	using JStd::CmdLine::CmdLine;
	using namespace std;

	void calcPi(CmdLine& cmdLine);

	static bool registered = JStd::CmdLine::Register(L"pi", calcPi);

	void calcPi(CmdLine& cmdLine)
	{
		double qpi = 1;
		int denom = 3;
		double state = -1;
		while (_getch() != 'q')
		{
			qpi += state / denom;
			state = -state;
			denom += 2;
			cout << "denom: " << denom << " pi=(somewhat)" << qpi * 4 << endl;
		}
		cout << "end of pi :)" << endl;
	}

}