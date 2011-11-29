#include "stdafx.h"
#include <vector>
#include <cmath>

namespace problem317
{
using JStd::CmdLine::CmdLine;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"317", problem);

using namespace std;
using namespace JStd;

/*
s = vt + .5at^2 
100 = v0*t + .5*9.81*t^2
.5*9.81*t^2 + v0*t - 100 = 0
a = .5 * 9.81;
b = v0
c = -100
*/
pair<double, double> abc(double a, double b, double c)
{
	double inter = sqrt(b*b - 4 * a * c);
	return make_pair((-b + inter) / (2 * a), (-b - inter) / (2 * a));
}

double findR(double ang)
{
	cout << "angle=" << ang << endl;
	double pi = asin(1.)*2;
	double rad = pi * 2. * ang / 360.;
	double hSpeedStart = 20. * cos(rad);
	double vSpeedStart = 20. * sin(rad);

	double a = .5 * 9.81;
	double b = -vSpeedStart;
	//double b = 0;
	double c = -100;

	pair<double, double> t2 = abc(a,b,c);

	cout << "t=" << t2.first << " or " << t2.second << endl;
	double t = max(t2.first, t2.second);
	
	double r = t * hSpeedStart;
	//double r = t * 20.;

	cout << "r=" << r << endl;
	return r;
}

double findMaxR(double angStart, double angInc)
{
	double rPrev;

	double rCurr  = findR(angStart);
	do
	{
		rPrev = rCurr;
		angStart += angInc;
		rCurr = findR(angStart);
	}while(rPrev < rCurr);

	return angStart - angInc*2;
}

void problem(CmdLine& cmdLine)
{
	cout.precision(20);
	double angle=0;
	for(double angInc = 1; angInc > 0.000000001; angInc *= 0.1)
		angle = findMaxR(angle, angInc);

	cout << "answer=" << 2*asin(1.) * findR(angle) * findR(angle) << endl;

	cout << "answer2=" << (asin(1.)*pow(20., 2)/9.81) * pow(100. + 20.*20./(9.81*2.), 2) << endl;


	return;

	int num;
	do
	{
		cout << "Angle: ";
		num = 0;
		cin >> num;
		if(num >= 0)
			findR(num);
	}while(num >= 0);

//	cout << "r=" << findR(0) << endl;
//	cout << "Answer=" << endl;
}

}
