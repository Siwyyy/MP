#pragma once
#include<string>

class UjemnaWartosc
{
	std::string komunikat;

public:
	UjemnaWartosc(std::string komunikat): komunikat(komunikat) {}

	std::string co()
	{
		return "Ujemna wartosc. " + komunikat;
	}
};
