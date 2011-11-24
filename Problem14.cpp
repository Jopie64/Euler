#include "stdafx.h"
#include <vector>

namespace problem14
{
using namespace std;
using namespace JStd;
using JStd::CmdLine::CmdLine;

void problem(CmdLine& cmdLine);
static bool registered = JStd::CmdLine::Register(L"14", problem);


typedef __int64 calc_int_type;

int determineNbStepsWithOutput(calc_int_type num)
{
	cout << num;
	int steps = 0;
	while(num != 1)
	{
		++steps;
		if(num & 1)
			num = 3 * num + 1;
		else
			num /= 2;
		cout << "->" << num;
	}
	cout << endl << steps << " steps." << endl;
	return steps;
}

struct Ctxt
{
public:
	Ctxt(int numMax):m_numMax(numMax){ m_vectSteps.resize(numMax, 0); }

	int m_numMax;
	vector<int> m_vectSteps;

	int determineNbSteps(calc_int_type num)
	{
		if(num == 1)
			return 0;
	
		if(num < m_numMax && m_vectSteps[(int)num])
			return m_vectSteps[(int)num];

		calc_int_type newNum = num;
		if(newNum & 1)
			newNum = 3 * newNum + 1;
		else
			newNum /= 2;

		int steps = determineNbSteps(newNum) + 1;
		if(num < m_numMax)
			m_vectSteps[(int)num] = steps;
		return steps;
	}

	int determineNumberWithMostSteps()
	{
		int numMostSteps = 1;
		int nbSteps = 0;
		int clkShow = clock();
		for(int num = m_numMax; num > 1; --num)
		{
			int currSteps = determineNbSteps(num);
			if(currSteps >= nbSteps)
			{
				nbSteps = currSteps;
				numMostSteps = num;
				cout << "Number " << numMostSteps << " in " << nbSteps << endl;
			}
			if(clock() - clkShow > 500)
			{
				clkShow = clock();
				cout << num << "...\r" << flush;
			}
		}
		determineNbStepsWithOutput(numMostSteps);
		cout << "Done." << endl;
		return numMostSteps;
	}
};

void problem(CmdLine& cmdLine)
{
	std::wstring number = cmdLine.next();
	if(!number.empty())
	{
		Ctxt(_wtoi(number.c_str())).determineNumberWithMostSteps();
		return;
	}

	int num;
	do
	{
		cout << "Number: ";
		num = 0;
		cin >> num;
		if(num > 0)
			determineNbStepsWithOutput(num);
	}while(num > 0);
}

}