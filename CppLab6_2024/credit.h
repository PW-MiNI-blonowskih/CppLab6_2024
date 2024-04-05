#pragma once
#include <iostream>


class credit
{
protected:
	double value;			//wartosc creditu
	double percent;			//w procentach - rocznie, np. 9%, 12%
	int years;				//na ile lat
	int payments_in_year;	//ile rat w roku

	string info;		// dodatkowa informacja o kredycie, opis

public:
	credit() : value{ 0 }, percent{ 0 }, years{ 0 }, payments_in_year{ 0 }, info{ "" } { }
	credit(double value, double percent, int years, int payments_in_year, const char* info = "xxxxxxxxxx");
	

	//credit(const credit& k);				//zdefiniuj, je�eli uwa�asz �e jest potrzebne
	//credit& operator = (const credit& k);	//zdefiniuj, je�eli uwa�asz �e jest potrzebne
	//~credit();							//zdefiniuj, je�eli uwa�asz �e jest potrzebne

	int payments() const { return years * payments_in_year; }	//liczba rat kredytu
	double payment() const;				//rata kredytu

	void write(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const credit& os);

	
};
