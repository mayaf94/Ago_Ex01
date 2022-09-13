#include <iostream>
#include <stdlib.h>
#include <string>
#include "InputTest.h"

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::isalpha;

int InputTest::getNumberOfPointsOrArchery()
{
	string ch;
	int num;

	getline(cin, ch);

	for (int i = 0; i < ch.size(); i++)
	{
		if (!(ch[i] >= '0' && ch[i] <= '9'))
		{
			cout << "invalid input";
			exit(1);
		}
	}
	num = atoi(ch.c_str());
	if (num == 0)
	{
		cout << "invalid input";
		exit(1);
	}
	return num;
}

int len(string str)
{
	int length = 0;
	for (int i = 0; str[i] != '\0'; i++)
	{
		length++;

	}
	return length;
}

// create custom split() function  
string* split(string str, char seperator, int max)
{
	string* strings = new string[max];
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;
	while (i <= len(str))
	{
		if (str[i] == seperator || i == len(str))
		{
			if (currIndex == max)
			{
				cout << "invalid input";
				exit(1);
			}
			else {
				endIndex = i;
				string subStr = "";
				subStr.append(str, startIndex, endIndex - startIndex);
				strings[currIndex] = subStr;
				currIndex += 1;
				startIndex = endIndex + 1;
			}
		}
		i++;
	}
	return strings;
}

string* InputTest::GettingParams(int max, bool canBeZero)
{
	string str;
	string* strings;
	getline(cin, str);
	char seperator = ' '; // space
	if (!str.empty() || canBeZero == false)
	{
		strings = split(str, seperator, max);
		return strings;
	}
	return NULL;
}