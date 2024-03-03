// ReSharper disable StringLiteralTypo
// ReSharper disable IdentifierTypo
// ReSharper disable CppClangTidyClangDiagnosticInvalidUtf8
// ReSharper disable CppInconsistentNaming
// ReSharper disable CppUninitializedNonStaticDataMember
// ReSharper disable CppTooWideScope

// Siwek Miko³aj Z203

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

//• Dodaæ do ksi¹¿ki (klasy Ksiazka) nowe atrybuty: identyfikator, rok wydania, liczbê 
//	stron, stan (tzn. stan ksi¹¿ki mo¿e byæ bardzo dobry, dobry itd.) oraz zmodyfikowaæ 
//	metody wpisz() i pokaz() tak, aby uwzglêdniæ dodane atrybuty.
//• Dodaæ trzy funkcjonalnoœci, np.:
//	a) Wyœwietlanie ksi¹¿ek spe³niaj¹cych wskazane kryterium, np. napisanych przez 
//		danego autora, wydanych we wskazanym roku itp. (uwaga: porównanie 
//		zmiennych typu string mo¿na wykonaæ za pomoc¹ operatora ==).
//	b) Sortowanie ksi¹¿ek wed³ug autora, tytu³u, ceny itp. (uwaga: do porównania 
//		dwóch zmiennych typu string mo¿na u¿yæ operatorów <, >, <=, >=).
//	c) Usuwanie informacji o wybranej ksi¹¿ce, np. o wskazanym id., wszystkich ksi¹¿ek
//		danego autora itp. (wskazówka: usuniêcie informacji o ksi¹¿ce z elementu i-tego
//		tablicy wymaga przesuniêcia wartoœci ze z elementów tablicy od i+1 o jedn¹ 
//		pozycjê w lewo)

class Ksiazka
{
public:
	Ksiazka() = default;

	void wpisz(int new_id);

	inline void pokaz() const
	{
		std::cout << id << ". \"" << tytul << "\" | " << autor <<
			" | " << rok_wydania << " | Liczba stron: " << liczba_stron <<
			" | Stan: " << stan << " | Cena: " << cena << " zl.\n";
	}

	inline int dajID() const { return id; }
	inline std::string dajTytul() const { return tytul; }
	inline std::string dajAutora() const { return autor; }
	inline short dajRok() const { return rok_wydania; }
	inline short dajLiczbeStron() const { return liczba_stron; }
	inline float daj_cene() const { return cena; }

private:
	int id;
	std::string tytul;
	std::string autor;
	short rok_wydania;
	short liczba_stron;
	std::string stan;
	float cena;
};

void Ksiazka::wpisz(const int new_id)
{
	id = new_id;

	std::cout << "Podaj informacje o ksiazce\n";

	std::cout << "tytul: ";
	std::cin >> tytul;

	std::cout << "autor: ";
	std::cin >> autor;

	std::cout << "rok wydania: ";
	std::cin >> rok_wydania;

	std::cout << "liczba stron: ";
	std::cin >> liczba_stron;

	std::cout << "stan: ";
	std::cin >> stan;

	std::cout << "cena: ";
	std::cin >> cena;

	std::cout << "\nDodano Ksiazke:\n";
	pokaz();
}


void dodawanieKsiazek(int& n, Ksiazka ksiazki[], int& id)
{
	std::cout << "\n== == Dodawanie ksiazek == ==\n\n";
	for (char opcja = ' '; opcja == ' ';)
	{
		id++;
		ksiazki[n].wpisz(id);
		n++;
		std::cout << "\n[Space] Dodaj kolejna ksiazke\n";
		std::cout << "[Backspace] wroc\n\n";
		do
			opcja = _getch();
		while (opcja != ' ' && opcja != '\b');
	}
}

void usuwanieKsiazek(int& n, Ksiazka ksiazki[])
{
	std::cout << "\n== == Usuwanie ksiazek == ==\n";
	std::cout << "[1] Po ID\n";
	std::cout << "[2] Po autorze\n";
	std::cout << "[3] Po roku wydania\n";
	std::cout << "[Backspace] Anuluj\n\n";

	char opcja;
	do
		opcja = _getch();
	while (opcja != '1' && opcja != '2' && opcja != '3' && opcja != '\b');

	int id;
	std::string autor;
	short rok;

	switch (opcja)
	{
	case'1':
		std::cout << "Podaj ID: ";
		std::cin >> id;
		for (int i = 0; i < n; i++)
			if (ksiazki[i].dajID() == id)
			{
				for (int j = i; j < n - 1; j++)
					ksiazki[j] = ksiazki[j + 1];
				n--;
			}
		break;
	case'2':
		std::cout << "Podaj autora: ";
		std::cin >> autor;
		for (int i = 0; i < n; i++)
			if (ksiazki[i].dajAutora() == autor)
			{
				for (int j = i; j < n - 1; j++)
					ksiazki[j] = ksiazki[j + 1];
				n--;
			}
		break;
	case'3':
		std::cout << "Podaj rok wydania: ";
		std::cin >> rok;
		for (int i = 0; i < n; i++)
			if (ksiazki[i].dajRok() == rok)
			{
				for (int j = i; j < n - 1; j++)
					ksiazki[j] = ksiazki[j + 1];
				n--;
			}
		break;
	case '\b':
	default:
		break;
	}
}

void wyswietlWszystkieKsiazki(const int& n, const Ksiazka ksiazki[])
{
	system("cls");
	std::cout << "== == KSIAZKI == ==\n";
	for (int i = 0; i < n; i++)
	{
		ksiazki[i].pokaz();
	}
	std::cout << "== == == = == == ==\n";
}

void filtrujPoCenie(const int& n, const Ksiazka ksiazki[])
{
	float cena_max;
	std::cout << "Podaj cene maksymalna: ";
	std::cin >> cena_max;
	for (int i = 0; i < n; i++)
	{
		if (ksiazki[i].daj_cene() <= cena_max)
		{
			ksiazki[i].pokaz();
		}
	}
}

void filtrujPoAutorze(const int& n, const Ksiazka ksiazki[])
{
	std::string autor;
	std::cout << "Podaj autora: ";
	std::cin >> autor;
	for (int i = 0; i < n; i++)
		if (ksiazki[n].dajAutora() == autor)
			ksiazki[n].pokaz();
}

void filtrujPoRoku(const int& n, const Ksiazka ksiazki[])
{
	short rok;
	std::cout << "Podaj rok: ";
	std::cin >> rok;
	for (int i = 0; i < n; i++)
		if (ksiazki[n].dajRok() == rok)
			ksiazki[n].pokaz();
}

void filtrujPoStronach(const int& n, const Ksiazka ksiazki[])
{
	short min, max;
	std::cout << "Podaj minimalna liczbe stron: ";
	std::cin >> min;
	std::cout << "Podaj maksymalna liczbe stron: ";
	std::cin >> max;
	for (int i = 0; i < n; i++)
		if (ksiazki[n].dajLiczbeStron() >= min && ksiazki[n].dajLiczbeStron() <= max)
			ksiazki[n].pokaz();
}

void sortuj(int& n, Ksiazka ksiazki[])
{
	std::cout << "\n== == Sortowanie ksiazek == ==\n";
	std::cout << "[1] Po ID\n";
	std::cout << "[2] Po autorze\n";
	std::cout << "[3] Po roku wydania\n";
	std::cout << "[4] Po cenie\n";
	std::cout << "[Backspace] Anuluj\n\n";

	char opcja;
	do
		opcja = _getch();
	while (opcja != '1' && opcja != '2' && opcja != '3' && opcja != '4' && opcja != '\b');

	switch (opcja)
	{
	case'1':
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1; j++)
				if (ksiazki[j].dajID() > ksiazki[j + 1].dajID())
				{
					Ksiazka temp = ksiazki[j];
					ksiazki[j] = ksiazki[j + 1];
					ksiazki[j + 1] = temp;
				}
		break;
	case'2':
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1; j++)
				if (ksiazki[j].dajAutora() > ksiazki[j + 1].dajAutora())
				{
					Ksiazka temp = ksiazki[j];
					ksiazki[j] = ksiazki[j + 1];
					ksiazki[j + 1] = temp;
				}
		break;
	case'3':
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1; j++)
				if (ksiazki[j].dajRok() > ksiazki[j + 1].dajRok())
				{
					Ksiazka temp = ksiazki[j];
					ksiazki[j] = ksiazki[j + 1];
					ksiazki[j + 1] = temp;
				}
		break;
	case'4':
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1; j++)
				if (ksiazki[j].daj_cene() > ksiazki[j + 1].daj_cene())
				{
					Ksiazka temp = ksiazki[j];
					ksiazki[j] = ksiazki[j + 1];
					ksiazki[j + 1] = temp;
				}
		break;
	case '\b':
	default:
		break;
	}
}

int main()
{
	Ksiazka ksiazki[100];
	int lb_ksiazek = 0;
	int max_id = 0;
	bool quit = false;
	for (char opcja; !quit;)
	{
		system("cls");
		wyswietlWszystkieKsiazki(lb_ksiazek, ksiazki);

		std::cout << "\n== == MENU == ==\n";
		std::cout << "[1] Dodawanie ksiazek\n";
		std::cout << "[2] Usuwanie ksiazek\n";
		std::cout << "[3] Sortowanie ksiazek\n";
		std::cout << "[q] Zakoncz program\n";
		std::cout << "== == ==== == ==\n";

		do
			opcja = _getch();
		while (opcja != '1' && opcja != '2' && opcja != '3' && opcja != '4' && opcja != 'q');

		switch (opcja)
		{
		case '1':
			dodawanieKsiazek(lb_ksiazek, ksiazki, max_id);
			break;
		case '2':
			usuwanieKsiazek(lb_ksiazek, ksiazki);
			break;
		case '3':
			sortuj(lb_ksiazek, ksiazki);
			break;
		case 'q':
			quit = true;
			break;
		default:
			break;
		}
	}
}
