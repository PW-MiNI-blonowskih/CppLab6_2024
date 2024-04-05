#pragma once
#include "credit.h"



class creditDet: public credit
{
	double* projection;	//rozliczenie creditu: kolejne elementy dynamicznej tablicy to wartoœci
						//ile creditu jest jeszcze do sp³acenia po dokonaniu kolejnych rat
	
	void init_projection(int payments=0, double* projection=nullptr);
	
public:
	creditDet() : projection{ nullptr }{ }
	creditDet(double wartosc, double percent, int years , int payments_in_year, const char* info = "xxxxxxxxxx");
	

	//creditDet(const creditDet& k);				//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
	//creditDet& operator=(const creditDet& k);	//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
	//~creditDet();						//zdefiniuj, je¿eli uwa¿asz ¿e jest potrzebne
		
	void payoff() const;	//rozliczenie kredytu

	void write(ostream& out) const;
	
};
