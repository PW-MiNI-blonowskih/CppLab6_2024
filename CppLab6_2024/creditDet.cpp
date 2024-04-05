#include <iostream>
using namespace std;
#include <iomanip>
#include "creditDet.h"


//-----------------------------------------------------------------
void creditDet::init_projection(int payments, double* projection)
{
	this->projection = nullptr;

	if (payments > 0)
	{
		this->projection = new (nothrow) double[payments];
		if (!this->projection)  return;

		for (int i = 0; i < payments; i++)
			this->projection[i] = projection ? projection[i] : 0;
	}
}
//-------------------------------------------------------------------
creditDet::creditDet(double value, double percent, int years, int payments_in_year, const char* info)
{
	//uzupelnij
	//wywo³aj init_projection oraz payoff
}

//-----------------------------------------------------------
void creditDet::payoff() const	// ile creditu jeszcze do sp³acenia po wplaceniu "i" rat
								//wypelnia tablicê projection			
{
	//uzupelnij


}
//-----------------------------------------------------------
void creditDet::write(ostream& out) const
{
	//uzupelnij


}
//-------------------------------------------------------------
