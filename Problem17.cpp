#include "stdafx.h"
#include <vector>
#include <cmath>
#include <sstream>

namespace problem17
{
using namespace std;
using namespace JStd;
using JStd::CmdLine::CmdLine;

void problem(CmdLine& cmdLine);
static bool registered = JStd::CmdLine::Register(L"17", problem);

const char* getnumber(long long number)
{
	switch(number)
	{
	case 0: return "zero";
	case 1: return "one";
	case 2: return "two";
	case 3: return "three";
	case 4: return "four";
	case 5: return "five";
	case 6: return "six";
	case 7: return "seven";
	case 8: return "eight";
	case 9: return "nine";
	case 10: return "ten";
	case 11: return "eleven";
	case 12: return "twelve";
	case 13: return "thirteen";
	case 14: return "fourteen";
	case 15: return "fifteen";
	case 16: return "sixteen";
	case 17: return "seventeen";
	case 18: return "eighteen";
	case 19: return "nineteen";
	case 20: return "twenty";
	case 30: return "thirty";
	case 40: return "fourty";
	case 50: return "fifty";
	case 60: return "sixty";
	case 70: return "seventy";
	case 80: return "eighty";
	case 90: return "ninety";
	case 100: return "hundred";
	case 1000: return "thousand";
	case 1000000: return "million";
	case 1000000000: return "billion";
	case 1000000000000ll: return "trillion";
	case 1000000000000000ll: return "quadrillion";
	case 1000000000000000000ll: return "quintillion";
	}
	throw std::logic_error("getnumber() not a valid number.");
	//return NULL;
}

void writeBelowThousand(ostream& os, long long number)
{
	if(number >= 1000) throw std::logic_error("Number greater than (or equal to) 1000");
	if(number >= 200)
		os << getnumber(number / 100);
	if(number >= 100)
		os << getnumber(100);
	number %= 100;
	if(number == 0)
		return;
	if(number < 20)
	{
		os << getnumber(number);
		return;
	}
	os << getnumber((number / 10) * 10);
	number %= 10;
	if(number > 0)
		os << getnumber(number);
}

void writeout(ostream& os, long long number)
{
	if(number == 0)
	{
		os << getnumber(0);
		return;
	}
	int thousand = (int)(log((double)number) / log(1000.));
	for(;thousand >= 0; --thousand)
	{
		long long thousandCalc = (long long)pow(1000., thousand);
		long long part = (number / thousandCalc) % 1000;
		if(part == 0)
			continue;
		if(part > 1 || thousand == 0)
			writeBelowThousand(os, part);
		if(thousandCalc > 1)
			os << getnumber(thousandCalc);
	}
}

void problem(CmdLine& cmdLine)
{
	std::wstring numberStr = cmdLine.next();
	wchar_t* dummy;
	if(numberStr == L"ask")
	{
		long long num;
		do
		{
			cout << "Number: ";
			num = 0;
			cin >> num;
			if(num > 0)
			{
				writeout(cout, num);
				cout << endl;
			}
		}while(num > 0);
		return;
	}
	if(numberStr == L"say")
	{
		long long nr = wcstol(cmdLine.next().c_str(), &dummy, 10);
		writeout(cout, nr);
		cout << endl;
		return;
	}
	

	bool verbose = cmdLine.hasOption(L'v');

	long long nr = wcstol(numberStr.c_str(), &dummy, 10);
	if(nr == 0)
		nr = 1000;

	size_t count =0;

	for(int i=0; i<nr; ++i)
	{
		ostringstream os;
		writeout(os, i+1);
		if(verbose)
			cout << i+1 << "=" << os.str() << endl;
		count += os.str().size();
	}
	cout << "And the number is..... " << count << endl;
}

}
