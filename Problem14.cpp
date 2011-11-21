#include "stdafx.h"

namespace problem14
{

void problem(int argc, wchar_t* argv[]);

static bool registered = JStd::CmdLine::Register(L"14", problem);

using namespace std;
using namespace JStd;

int determineNbStepsWithOutput(int num)
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

void problem(int argc, wchar_t* argv[])
{
	if(argc > 2)
	{
		determineNbStepsWithOutput(_wtoi(argv[2]));
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