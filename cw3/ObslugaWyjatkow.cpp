//Obsluga sytuacji wyjątkowych
//MP EFigielska
#include<iostream>
#include "TabliczkaDzialan.h"
#include "DzieleniePrzez0.h"
#include "UjemnaWartosc.h"
#include "ZaDuzaWartosc.h"
using namespace std;

int main()
{
	int a, b;
	cout << "Podaj dwie liczby calkowite nieujemne: ";
	cin >> a >> b;
	TabliczkaDzialan* t;
	try { t = new TabliczkaDzialan(a, b); }
	catch (UjemnaWartosc& blad)
	{
		cout << endl << blad.co();
		return 0;
	}

	try { cout << endl <<  "Wynik dodawania " << a << " i " << b << " = " << t->dodaj(); }
	catch (ZaDuzaWartosc& blad) { cout << endl << blad.co(); }

	try { cout << endl <<  "Wynik odejmowania " << a << " i " << b << " = " << t->odejmij(); }
	catch (UjemnaWartosc& blad) { cout << endl << blad.co(); }

	try { cout << endl <<  "Wynik mnozenia " << a << " przez " << b << " = " << t->pomnoz(); }
	catch (ZaDuzaWartosc& blad) { cout << endl << blad.co(); }

	try { cout << endl <<  "Wynik dzielenia calkowitego " << a << " przez " << b << " = " << t->podziel(); }
	catch (DzieleniePrzez0& blad) { cout << endl << blad.co(); }

	try { cout << endl <<  "Reszta z dzielenia calkowitego " << a << " przez " << b << " = " << t->obl_reszte(); }
	catch (DzieleniePrzez0& blad) { cout << endl << blad.co(); }
}