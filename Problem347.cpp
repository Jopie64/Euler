#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem347
{

void problem(int argc, wchar_t* argv[]);

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
};

void problem(int argc, wchar_t* argv[])
{
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