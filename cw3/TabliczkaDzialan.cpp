#include "TabliczkaDzialan.h"
#include "DzieleniePrzez0.h"
#include "UjemnaWartosc.h"
#include "ZaDuzaWartosc.h"

TabliczkaDzialan::TabliczkaDzialan(int a, int b)
	: a(a), b(b)
{
	if (a < 0 || b < 0) throw UjemnaWartosc("Wyjatek rzucony w konstruktorze klasy TabliczkaDzalan");
}

int TabliczkaDzialan::dodaj()
{
	if (a > INT_MAX - b)
		throw ZaDuzaWartosc("Wyjatek rzucony w metodzie dodaj() klasy TabliczkaDzalan");
	return a + b;
}

int TabliczkaDzialan::odejmij()
{
	if (a < b)
		throw UjemnaWartosc("Wyjatek rzucony w metodzie odejmij() klasy TabliczkaDzalan");
	return a - b;
}

int TabliczkaDzialan::pomnoz()
{
	//wyjatek zostanie zgłoszony, gdy wynik mnozenia przekroczy górny zakres wartości zmiennej typu calkowitego INT_MAX
	//czyli, jezeli a*b > INT_MAX
	if (b == 0) return 0;
	if (a > INT_MAX / float(b))
	{
		//sprawdzenie, czy a*b > INT_MAX 
		throw ZaDuzaWartosc("Wyjatek rzucony w metodzie pomnoz() klasy TabliczkaDzalan");
	}
	return a * b;
}

int TabliczkaDzialan::podziel()
{
	if (b == 0)
	{
		throw DzieleniePrzez0("Wyjatek rzucony w metodzie podziel() klasy TabliczkaDzialan");
	}
	return a / b;
}

int TabliczkaDzialan::obl_reszte()
{
	if (b == 0)
		throw DzieleniePrzez0("Wyjatek rzucony w metodzie obl_reszte() klasy TabliczkaDzialan");
	return a % b;
}
