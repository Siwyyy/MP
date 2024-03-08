// ReSharper disable CppClangTidyClangDiagnosticInvalidUtf8
// ReSharper disable IdentifierTypo
// ReSharper disable StringLiteralTypo

// Miko³aj Siwek, Z203, Metody Programowania - æw2_zad2, 2024

//	2. Napisaæ program wed³ug nastêpuj¹cych wymagañ:
//		• Zdefiniowaæ klasê Stozek, reprezentuj¹c¹ sto¿ek. 
//		Atrybuty: wysokoœæ, promieñ podstawy i tworz¹ca. 
//		Metody: 
//			o Konstruktor: przyjmuje 2 parametry: wysokoœæ i promieñ podstawy, nadaje 
//				wartoœci polom wysokoœæ i promieñ podstawy zgodnie z wartoœciami 
//				parametrów, nadaje wartoœæ tworz¹cej za pomoc¹ prywatnej metody 
//				obliczaj¹cej d³ugoœæ tworz¹cej ,
//			o Metoda obliczaj¹ca d³ugoœæ tworz¹cej – metoda prywatna wywo³ywana w 
//				konstruktorze,
//			o Metoda obliczaj¹ca i zwracaj¹ca wartoœæ pola powierzchni ca³kowitej,
//			o Metoda obliczaj¹ca i zwracaj¹ca wartoœæ objêtoœci.
//		• Utworzyæ obiekt klasy Stozek i wykonaæ dla niego obliczeni

#include <iostream>

#define M_PI 3.14159265358979323846

class Stozek
{
public:
	Stozek(const double& t_height, const double& t_radius);
	void calcSlantHeight();
	long double surfaceArea() const;
	long double volume() const;

private:
	long double m_height;
	long double m_radius;
	long double m_slant_height;
};

Stozek::Stozek(const double& t_height, const double& t_radius)
	: m_height(t_height),
	  m_radius(t_radius),
	  m_slant_height()
{
	calcSlantHeight();
}

void Stozek::calcSlantHeight()
{
	m_slant_height = sqrt(m_height * m_height + m_radius * m_radius);
}

long double Stozek::surfaceArea() const
{
	return M_PI * m_radius * (m_radius + m_slant_height);
}

long double Stozek::volume() const
{
	return M_PI * m_radius * m_radius * m_height / 3;
}

int main()
{
	long double height, radius;

	std::cout << "Podaj wysokosc stozka: ";
	std::cin >> height;
	std::cout << "Podaj promien podstawy stozka: ";
	std::cin >> radius;

	const Stozek s(height, radius);
	std::cout << "Pole calkowite stozka: " << s.surfaceArea() << '\n';
	std::cout << "Objetosc stozka: " << s.volume() << '\n';

	return 0;
}
