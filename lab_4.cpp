#include <iostream>
#include <cstring>
using namespace std;

class adres{
	string ulica, miasto, kod;
	int numer;
	
public: 
	adres(): miasto(""), kod(""), ulica(""), numer(0){}
	
	adres(string miasto, string kod, string ulica, int numer): ulica(ulica), miasto(miasto), kod(kod), numer(numer){}

	//konstruktor kopiujacy
	adres(const adres& inny_adres): miasto(inny_adres.miasto), kod(inny_adres.kod), ulica(inny_adres.ulica), numer(inny_adres.numer) {}
	
	//operator przypisania
	adres& operator=(const adres& inny_adres){
		if(this != &inny_adres){
			miasto = inny_adres.miasto;
			kod = inny_adres.kod;
			ulica = inny_adres.ulica;
			numer = inny_adres.numer;
			}
		return *this;
		}
		
	//operator strumienia (na standardowe wyjscie osteram)
	friend ostream& operator<<(ostream& output, const adres& adr){ // friend umozliwia operatorowi << dostep do prywatnych danych klasy adres
		output << "Adres: " << adr.miasto << " " << adr.kod << " " <<adr.ulica << " " << adr.numer;
		return output;
	}
	
 };

class osoba{
	string imie, nazwisko;
	int wiek;
	adres* _adres;
	
public:
	osoba(): imie(""), nazwisko(""),wiek(0), _adres(nullptr) {}
	
	osoba(string imie, string nazwisko, int wiek, const adres& adr): imie(imie), nazwisko(nazwisko), wiek(wiek){
		_adres = new adres(adr);
	}
	
	osoba(const osoba& inna): imie(inna.imie), nazwisko(inna.nazwisko), wiek(inna.wiek){
		_adres = new adres(*inna._adres);
	}
	
	osoba& operator=(const osoba& inna){
		if(this != &inna){
			imie = inna.imie;
			nazwisko = inna.nazwisko;
			wiek = inna.wiek;
			if(_adres != nullptr){
				delete _adres;
			}
			_adres = new adres(*inna._adres);
		}
		return *this;
	}
	
	//destruktor
	~osoba() {
		delete _adres;
	}
	
	friend ostream& operator<<(ostream& output, const osoba& o){
		output <<"Osoba: " << o.imie << " " << o.nazwisko << ", wiek: " << o.wiek;
		if(o._adres != nullptr){
			output << *o._adres;
		}
		return output;
	}
	
};
int main()
{
	adres* wsk = new adres("Czestochowa", "42-200", "Dabrowskiego", 73);
	cout << *wsk << '\n';
	adres a1(*wsk);
	delete wsk;

	const adres* wsk1 = new adres("Warszawa", "00-950", "Mysliwiecka", 357);
	cout << a1 << '\n';
	cout << *wsk1 << '\n';

	adres a2;
	cout << a2 << '\n';
	a2 = a1;
	cout << a2 << '\n';


	osoba o("Jan", "Kos", 25, *wsk1);
	cout << o << '\n';
	osoba o1(o);
	cout << o1 << '\n';

	osoba o2;
	cout << o2 << '\n';
	o2 = o1;
	cout << o2 << '\n';
	delete wsk1;

	return 0;
}
