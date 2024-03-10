#pragma once
#include<string>

class ZaDuzaWartosc
{
	std::string komunikat;

public:
	ZaDuzaWartosc(std::string komunikat): komunikat(komunikat) {}

	std::string co()
	{
		return "Za duza wartosc. " + komunikat;
	}
};
