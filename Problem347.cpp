#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem347
{
using JStd::CmdLine::CmdLine;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"347", problem);

using namespace std;
using namespace JStd;

typedef int divider_type;

struct Dividers
{
	Dividers():div1(0), div2(0){}

	void addDiv(divider_type div)
	{
		if(div1 < 0)
			return;
		if(div1 > 0)
		{
			if(div2 > 0)
			{
				div1 = -1;
				return;
			}
			div2 = div;
			return;
		}
		div1 = div;
	}

	bool isPrime() const { return div1 == 0; }

	divider_type div1;
	divider_type div2;
};

struct Ctxt
{
	Ctxt(int numMax){ init(numMax); }

	void init(int numMax)
	{
		cout << "Initializing up to " << numMax << "..." << endl;
		m_vectDiv.clear();
		++numMax; //do 1 higher, because vector is zero based.
		m_vectDiv.resize(numMax);
		for(int i = 2; i < numMax; ++i)
		{
			if(!m_vectDiv[i].isPrime())
				continue;
			for(int j = i + i; j < numMax; j += i)
				m_vectDiv[j].addDiv(i);
		}

		cout << "Done." << endl;
	}

	vector<Dividers> m_vectDiv;

	int M(int p, int q, int N)
	{
		if(q < p) swap(p,q);
		int start = N - N % q;

		for(int i = start; i > q; i -= q)
			if(m_vectDiv[i].div1 == p)
				return i;
		return 0;
	}

	__int64 S(int numMax)
	{
		__int64 result = 0;
		for(int i = 2; i < numMax; ++i)
		{
			if(!m_vectDiv[i].isPrime())
				continue;
			int jmax = numMax / i;
			for(int j = i + 1; j <= jmax; ++j)
			{
				if(!m_vectDiv[j].isPrime())
					continue;
				result += M(i,j,numMax);
			}
		}
		return result;
	}
};

#define SIEVE 10000000

int D[SIEVE+1];
int P[SIEVE+1][2];
bool O[SIEVE+1];

void sieve(){
	D[0] = D[1] = 1;
	for(int i=2;i<=SIEVE/2;i++)
		if(D[i]==0)
			for(int j=2*i;j<=SIEVE;j+=i){
				if(D[j]==0)P[j][0]=i;
				if(D[j]==1)P[j][1]=i;
				D[j]++;
			}
}

int doit(){
	sieve();
	long long sum = 0;
	for(int i=SIEVE;i>0;i--)
		if(D[i]==2)
			if(!O[P[i][0]*P[i][1]]){
				sum+=i;
				O[P[i][0]*P[i][1]]=true;
			}
	printf("%lld\n",sum);
	return 0;
}

void problem(CmdLine& cmdLine)
{
	//doit();
	//return;

	std::wstring s = cmdLine.next(L's');
	std::wstring hoi = cmdLine.next(L"hoi");
	std::wstring dag = cmdLine.next(L'd', L"dag");
	bool hasA = cmdLine.hasOption(L'a');
	bool hasB = cmdLine.hasOption(L'b', L"bla");

	std::wstring number = cmdLine.next();
	if(!number.empty())
	{
		int N = _wtoi(number.c_str());
		Ctxt ctxt(N);
		cout << "S(" << N << ") = " << ctxt.S(N) << endl;
		return;
	}

	Ctxt ctxt(1000000);

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
		cout << "M: " << ctxt.M(p,q,N) << endl;
	}while(true);

}

}