#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem347
{

void problem(int argc, wchar_t* argv[]);

static bool registered = JStd::CmdLine::Register(L"347", problem);

using namespace std;
using namespace JStd;

int calcMax(int p, int N)
{
	int ex = (int)(log((double)N) / log((double)p));
	return (int)pow((double)p, ex);
}

int M(int p, int q, int N)
{
	int ip = N - N % p;
	int iq = N - N % q;
	while(ip != iq && ip > 0 && iq > 0)
	{
		if(ip > iq)
			ip -= p;
		else
			iq -= q;
	}

	if(ip <= 0 || iq <= 0) return 0;
	return ip;
}

void problem(int argc, wchar_t* argv[])
{

	int p;
	do
	{
		p = 0;
		int q = 0;
		int N = 0;
		cout << "p: " << flush;
		cin >> p;
		if(p <= 0)
			break;
		cout << "q: " << flush;
		cin >> q;
		cout << "N: " << flush;
		cin >> N;
		cout << "M: " << M(p,q,N) << endl;
	}while(true);

}

}