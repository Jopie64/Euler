#include "stdafx.h"
#include <vector>

namespace problem26
{

void problem(int argc, wchar_t* argv[]);

static bool registered = JStd::CmdLine::Register(L"26", problem);

using namespace std;
using namespace JStd;

int determineRepeatingDecimals(int div, bool output)
{
	if(output)
		cout << "1/" << div << " = 0.";
	int top = 10;
	while(top < div)
	{
		top *= 10;
		if(output)
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
		if(output)
			cout << top / div;
		top %= div;
		++decCount;
		top *= 10;
		if(top == 0)
			break;
		while(top < div)
		{
			++decCount;
			top *= 10;
			if(output)
				cout << '0';
		}
	}
	if(top > 0)
	{
		if(output)
			cout << "... " << decCount << " repeating decimals.";
	}
	else
		decCount = 0;
	if(output)
		cout << endl;

	return decCount;
}

int determineNumberWithMostRepeatingDecimals(int numMax)
{
	int mostDecimals = 0;
	int numWithMostDecimals = 1;
	for(int i=1; i < numMax; ++i)
	{
		int currDecimals = determineRepeatingDecimals(i, false);
		if(currDecimals > mostDecimals)
		{
			mostDecimals = currDecimals;
			numWithMostDecimals = i;
		}
	}

	determineRepeatingDecimals(numWithMostDecimals, true);
	cout << "Number with most decimals is " << numWithMostDecimals << ". Done." << endl;
	return numWithMostDecimals;
}

void problem(int argc, wchar_t* argv[])
{
	if(argc > 2)
	{
		determineNumberWithMostRepeatingDecimals(_wtoi(argv[2]));
		return;
	}

	int num;
	do
	{
		cout << "Number: ";
		num = 0;
		cin >> num;
		if(num > 0)
			determineRepeatingDecimals(num, true);
	}while(num > 0);
}

}