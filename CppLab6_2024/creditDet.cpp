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
	: credit(value, percent, years, payments_in_year, info)
{
	//uzupelnij
	//wywo³aj init_projection oraz payoff
	init_projection(payments_in_year * years, nullptr);
	payoff();
}

//-----------------------------------------------------------
void creditDet::payoff() const	// ile creditu jeszcze do sp³acenia po wplaceniu "i" rat
{
	//uzupelnij
	for (int i = 0; i < years * payments_in_year; ++i) {
		double w{ value };
		for (int j = 0; j <= i; ++j) {
			double odsetki{ w * percent / 100 / payments_in_year };
			w -= payment() - odsetki;
		}
		projection[i] = w;
	}
}
//-----------------------------------------------------------
void creditDet::write(ostream& out) const
{
	//uzupelnij
	out << "\t" << info << "\tcredit:\t" << setw(9) << std::fixed << setprecision(2) << value << " (" << setw(5) << percent << "%)\tyears: " << years << "\tr/r: " << payments_in_year << "\t\tpayment: " << setw(8) << payment() << "\n\t" << "projection: [ ";

	for (int i = 0; i < payments_in_year * years; ++i) {
		out << projection[i] << " ";
	}

	out << "]" << endl;

}
//-------------------------------------------------------------

creditDet::creditDet(const creditDet& k)
	: credit(k)
{
	init_projection(years * payments_in_year, k.projection);
}

creditDet::~creditDet() {
	delete[] projection;
}

creditDet& creditDet::operator=(const creditDet& k) {
	if (this != &k) {
		delete[] projection;
		static_cast<credit&>(*this) = credit{ k };
		init_projection(years * payments_in_year, k.projection);
	}
	return *this;
}