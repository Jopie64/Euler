#include "stdafx.h"
#include <fstream>
#include <vector>

namespace problem59
{
using JStd::CmdLine::CmdLine;
using namespace std;

void problem(CmdLine& cmdLine);
void problem_encode(CmdLine& cmdLine);
void problem_all(CmdLine& cmdLine);

static bool registered = JStd::CmdLine::Register(L"59", problem) &&
						 JStd::CmdLine::Register(L"59_encode", problem_encode) &&
						 JStd::CmdLine::Register(L"59_all", problem_all);

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
	int answer = 0;
	for(vector<char>::iterator i = orig.begin(); i != orig.end(); ++i)
	{
		char decoded = (char)(*i ^ key[pkey]);
		cout << decoded;
		answer += decoded;
		++pkey;
		if(pkey == keysize)
			pkey = 0;
	}




	cout << endl << "Message end. Size is: " << orig.size() << " and the answer is: " << answer << endl;

	//cout << endl << "Answer=" << 42 << endl;
}

void problem_encode(CmdLine& cmdLine)
{
	ifstream fnormal("res\\Problem59_toEncode.txt");
	ofstream fcipher("res\\Problem59_cipher1.txt");
	const char* key = "god";
	const char* keyend = key + strlen(key);

	cout << "Encoding using key: '" << key << "'..." << endl;
	const char* pkey = key;
	char c;
	bool isAtBegin = true;
	while(fnormal.get(c))
	{
		if(isAtBegin)
			isAtBegin = false;
		else
			fcipher << ',';
		fcipher << (int)(c ^ *pkey);
		++pkey;
		if(pkey == keyend)
			pkey = key;
	}
	cout << "Done.";
}

void problem_all(CmdLine& cmdLine)
{
	problem_encode(cmdLine);
	problem(cmdLine);
}

}