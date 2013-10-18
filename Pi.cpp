#include "stdafx.h"
#include <vector>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <sstream>

namespace pi
{
	using JStd::CmdLine::CmdLine;
	using namespace std;

	void calcPi(CmdLine& cmdLine);

	static bool registered = JStd::CmdLine::Register(L"pi", calcPi);

	void calcPi(CmdLine& cmdLine)
	{
		double qpi = 1;
		long long denom = 3;
		double state = -1;
		int steps = 1;
		wistringstream(cmdLine.next()) >> steps;
		if (steps <= 1)
			steps = 1;
		while (_getch() != 'q')
		{
			for (int i = 0; i < steps; ++i)
			{
				qpi += state / denom;
				state = -state;
				denom += 2;
			}
			cout << "denom: " << denom << " pi=(somewhat)" << setprecision(30) << qpi * 4 << endl;
		}
		cout << "end of pi :)" << endl;
	}

}