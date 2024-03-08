// Miko³aj Siwek, Metody programowania æw2_zad1

// ReSharper disable CppClangTidyClangDiagnosticInvalidUtf8
// ReSharper disable IdentifierTypo
// ReSharper disable StringLiteralTypo
// ReSharper disable CppInconsistentNaming

//	• Dodaæ do osoby (klasy Osoba) nowe atrybuty: nazwisko, numer telefonu, adres
//		zamieszkania oraz zmodyfikowaæ odpowiednio konstruktory i metodê wypisz().
//	• Zdefiniowaæ obiekt klasy Osoba i wykonaæ dla niego dzia³ania.

#include<iostream>
#include<string>

class Osoba
{
	std::string imie;
	std::string nazwisko;
	int wiek;
	std::string adres;
	int tel;

public:
	Osoba()
		: imie("-"),
		  nazwisko("-"),
		  wiek(0),
		  adres("-"),
		  tel(0)
	{
		std::cout << "Wartosc wskaznika this " << this << '\n';
	}

	Osoba(std::string t_imie,
	      std::string t_nazwisko,
	      const int& t_wiek,
	      std::string t_adres,
	      const int& t_tel)
		: imie(std::move(t_imie)),
		  nazwisko(std::move(t_nazwisko)),
		  wiek(t_wiek),
		  adres(std::move(t_adres)),
		  tel(t_tel)
	{
		std::cout << "Wartosc wskaznika this: " << this << '\n';
	}

	void wypisz() const
	{
		std::cout << imie << ' ' << nazwisko << ", lat " << wiek << ", " << adres << ", tel: " << tel << '\n';
	}
};

int main()
{
	const Osoba pierwsza;
	std::cout << "Adres obiektu \"pierwsza\": " << &pierwsza << '\n';
	pierwsza.wypisz();
	const Osoba druga("Janek", "Jankowski", 10, "ul. Prosta 111, Warszawa", 123456789);
	std::cout << "Adres obiektu \"druga\": " << &druga << '\n';
	druga.wypisz();
}
