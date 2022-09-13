#ifndef INPUTTEST_H
#define INPUTTEST_H


class InputTest
{
public:
	static int getNumberOfPointsOrArchery();
	static std::string* GettingParams(int max, bool canBeZero);
	static void CheckIfNumberInBorder(int num, int max, bool hasBorder);
};


#endif
