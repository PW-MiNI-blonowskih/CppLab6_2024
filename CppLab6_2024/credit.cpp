#include <iostream>
using namespace std;
#include <iomanip>
#include "credit.h"


credit::credit(double value, double percent, int years, int payments_in_year, const char* info)
	: value{ value }, percent{ percent }, years{ years }, payments_in_year{ payments_in_year }, info{ info } { }



double credit::payment() const	//rata kredytu
{
	double q{ 1 + (percent / 100 / payments_in_year) };
	double n{ static_cast<double>(payments_in_year * years) };

	double rata{ value * pow(q, n) * (q - 1) / (pow(q, n) - 1) };

	return rata;	//popraw

}


void credit::write(ostream& out) const
{
	out << "\t" << info << "\tcredit:\t" << setw(9) << std::fixed << setprecision(2) << value << " (" << setw(5) << percent << "%)\tyears: " << years << "\tr/r: " << payments_in_year << "\t\tpayment: " << setw(8) << payment() << endl;
}

ostream& operator<<(ostream& out, const credit& os)
{
	os.write(out);
	return out;
}




