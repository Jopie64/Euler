#include "stdafx.h"
#include <fstream>
#include <vector>

namespace problem59
{
using JStd::CmdLine::CmdLine;
using namespace std;

void problem(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"59", problem);

const int keysize = 3;

void problem(CmdLine& cmdLine)
{
	bool charused[256];
	memset(charused,0,sizeof(charused));
	for(int i=1; i < 256; ++i)
		//if(isalpha(i) || isdigit(i) || strchr(",. ;:<>!@#$%^&*()[]{}'\"<>/?\\|~`=+\t\r\n", i)) charused[i] = true;
		if(isalpha(i) || isdigit(i) || strchr(",. ;:<>!@#$%^&*()[]'\"<>/?\\|~=+\t\r\n", i)) charused[i] = true;

	ifstream fcipher("res\\Problem59_cipher1.txt");
	string cur;
	vector<char> orig;
	while(getline(fcipher, cur, ','))
	{
		orig.push_back(atoi(cur.c_str()));
		//cout << cur << "-";
		//cout << orig.back();
	}


	cout << "Determining key..." << endl;
	char key[keysize+1] = { 0,0,0,0 };
	for(int keypos = 0; keypos < keysize; ++keypos)
	{
		bool found = false;
		int keychar = 'a';
		for(; keychar < 'z'; ++keychar)
		{
			found = true;
			const char* pend = &*orig.begin() + orig.size();
			for(const char* i = &*orig.begin() + keypos; i < pend; i += keysize)
			{
				if(!charused[*i ^ keychar])
				{
					found = false;
					//cout << "Bad: char " << (int)*i << " xor " << (int)keychar << " = " << (int)(*i ^ keychar) << endl;
					break;
				}
				//cout << "char " << (int)*i << " xor " << (int)keychar << " = " << (char)(*i ^ keychar) << endl;
			}
			if(found)
				break;
		}
		if(!found)
			throw runtime_error(JStd::String::Format("Key pos %d not found.", keypos));
		key[keypos] = keychar;
	}

	cout << "key=" << key << endl;

	int pkey = 0;
	for(vector<char>::iterator i = orig.begin(); i != orig.end(); ++i)
	{
		cout << (char)(*i ^ key[pkey]);
		++pkey;
		if(pkey == keysize)
			pkey = 0;
	}




	cout << endl << "Message end. Size is: " << orig.size() << endl;

	//cout << endl << "Answer=" << 42 << endl;
}

}