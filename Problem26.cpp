#include "stdafx.h"
#include <vector>

namespace problem26
{

void problem(int argc, wchar_t* argv[]);

static bool registered = JStd::CmdLine::Register(L"26", problem);

using namespace std;
using namespace JStd;

void determineRepeatingDecimals(int div)
{
	cout << "0.";
	int top = 10;
	while(top < div)
	{
		top *= 10;
		cout << '0';
	}

	vector<bool> vectDone;//(10,false);

	int decCount = 0;
	for(; top != 0;)
	{
		if(vectDone.size() <= top)
			vectDone.resize(top + 1);
		if(vectDone[top])
			break;
		vectDone[top] = true;
		int result = top / div;

		cout << result;
		top -= result * div;
		++decCount;
		top *= 10;
		if(top == 0)
			break;
		while(top < div)
		{
			++decCount;
			top *= 10;
			cout << '0';
		}
	}
	if(top > 0)
		cout << "... " << decCount << " repeating decimals.";
	cout << endl;
}

void problem(int argc, wchar_t* argv[])
{
	if(argc > 2)
	{
		determineRepeatingDecimals(_wtoi(argv[2]));
		return;
	}

	int num;
	do
	{
		cout << "Number: ";
		num = 0;
		cin >> num;
		if(num > 0)
			determineRepeatingDecimals(num);
	}while(num > 0);
}

}