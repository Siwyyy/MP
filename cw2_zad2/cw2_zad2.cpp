// ReSharper disable CppClangTidyClangDiagnosticInvalidUtf8
// ReSharper disable IdentifierTypo
// ReSharper disable StringLiteralTypo

// Miko�aj Siwek, Z203, Metody Programowania - �w2_zad2, 2024

//	2. Napisa� program wed�ug nast�puj�cych wymaga�:
//		� Zdefiniowa� klas� Stozek, reprezentuj�c� sto�ek. 
//		Atrybuty: wysoko��, promie� podstawy i tworz�ca. 
//		Metody: 
//			o Konstruktor: przyjmuje 2 parametry: wysoko�� i promie� podstawy, nadaje 
//				warto�ci polom wysoko�� i promie� podstawy zgodnie z warto�ciami 
//				parametr�w, nadaje warto�� tworz�cej za pomoc� prywatnej metody 
//				obliczaj�cej d�ugo�� tworz�cej ,
//			o Metoda obliczaj�ca d�ugo�� tworz�cej � metoda prywatna wywo�ywana w 
//				konstruktorze,
//			o Metoda obliczaj�ca i zwracaj�ca warto�� pola powierzchni ca�kowitej,
//			o Metoda obliczaj�ca i zwracaj�ca warto�� obj�to�ci.
//		� Utworzy� obiekt klasy Stozek i wykona� dla niego obliczeni

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
