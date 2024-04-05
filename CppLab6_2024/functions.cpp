#include <iostream>
using namespace std;
#include "credit.h"



bool cmp_value(const credit& k1, const credit& k2)
{
	//kryterium sortowania po wartosciach kredytu
	//uzupelnij

	return true;	//popraw!
}

bool cmp_value_info(const credit& k1, const credit& k2)
{
	//kryterium sortowania po wartosciach kredytu, gdy s¹ takie same to po info
	//uzupelnij

	return false;
}

//-----------------------------------------------------------------
void write(credit** cr, int n, const char* description)	//GOTOWA
{
	cout << endl << description;
	for (int i = 0; i < n; i++) cout << *cr[i];
	cout << endl;
}

void sort(/*uzupe³nij parametry*/)
{
	//uzupe³nij (w³asna implementacja)



}