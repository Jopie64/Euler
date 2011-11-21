#include "stdafx.h"

namespace problem14
{

void problem(int argc, wchar_t* argv[]);

static bool registered = JStd::CmdLine::Register(L"14", problem);

using namespace std;
using namespace JStd;

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

int determineNbSteps(calc_int_type num)
{
	int steps = 0;
	while(num != 1)
	{
		++steps;
		if(num & 1)
			num = 3 * num + 1;
		else
			num /= 2;
	}
	return steps;
}

int determineNumberWithMostSteps(int numMax)
{
	int numMostSteps = 1;
	int nbSteps = 0;
	for(int num = numMax; num > 1; --num)
	{
		int currSteps = determineNbSteps(num);
		if(currSteps > nbSteps)
		{
			nbSteps = currSteps;
			numMostSteps = num;
			cout << "Number " << numMostSteps << " in " << nbSteps << endl;
		}
		if(num % 100 == 0)
			cout << num << "...\r" << flush;
	}
	determineNbStepsWithOutput(numMostSteps);
	cout << "Done." << endl;
	return numMostSteps;
}

void problem(int argc, wchar_t* argv[])
{
	if(argc > 2)
	{
		determineNumberWithMostSteps(_wtoi(argv[2]));
		return;
	}

	int num;
	do
	{
		cout << "Number: ";
		cin >> num;
		if(num > 0)
			determineNbStepsWithOutput(num);
	}while(num > 0);
}

}