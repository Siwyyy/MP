#pragma once
#include<string>

class DzieleniePrzez0
{
	std::string komunikat;

public:
	DzieleniePrzez0(std::string komunikat): komunikat(komunikat) {}

	std::string co()
	{
		return "Dzielenie przez 0. " + komunikat;
	}
};
