#include <iostream>
#include <string>
using namespace std;

//metody dostepowe, pokaz() wyswietla wszytskie pola skladowe
class osoba{
private:
	string imie;
	int wiek;

public:	
        osoba(): imie(""), wiek(0) {}
        osoba(string imie, int wiek): imie(imie), wiek(wiek) {}
        osoba(const osoba& o): imie(o.imie), wiek(o.wiek){
          cout<<"konstruktor kopiujacy klasy osoba"<<endl;
        }
        
        string nazwisko()const{
          return imie;
        }
        int liczba_lat()const{
          return wiek;
        }
        
	void pokaz(){
	  cout<<"imie: "<<imie<<", wiek: "<<wiek<<endl;
	}
	osoba& operator=(const osoba& o){
	  if(this == &o){
	    return *this;
	  }
	  imie = o.imie;
	  wiek = o.wiek;
	  return *this;
	  
	}
	
	};
	
	
class pracownik : public osoba{
private:
	string _stanowisko;
	float _placa;
public:
        pracownik(): osoba(), _stanowisko(""), _placa(0.0) {}
        pracownik(string imie, int wiek, string stanowisko, float placa): osoba(imie,wiek),             _stanowisko(stanowisko), _placa(placa) {}
        
        pracownik(const pracownik& pr): osoba(pr), _stanowisko(pr._stanowisko), _placa(pr._placa) {
          cout<<"konstruktor kopiujacy"<<endl;
        }
        
        string stanowisko()const{
          return _stanowisko;
        }
        float placa()const{
          return _placa;
        }
        
        void pokaz(){
          osoba::pokaz();
          cout<< "stanowisko: " << _stanowisko << ", placa: " << _placa <<  endl;
        }
        
        pracownik& operator=(const pracownik& pr){
          if(this == &pr ){
            return *this;
          }
          osoba::operator=(pr);
          
          _stanowisko = pr._stanowisko;
          _placa = pr._placa;
          
          return *this;
        }
	};



int main()
{
	osoba os("Dolas", 26);
	os.pokaz();
	
	const pracownik pr1("Dyzma", 35, "mistrz", 1250.0);
	cout << pr1.nazwisko() << pr1.liczba_lat();
	cout << pr1.stanowisko() << pr1.placa();
	
	pracownik pr2(pr1);
	pr2.pokaz();
	
	pracownik pr3("Kos", 45, "kierownik", 2260.0);
	cout<< "pracownik 3"<<endl;
	pr3.pokaz();
	pr3 = pr2;
	cout<<"tu powinna sie pojawic pracownik 2"<< endl;
	pr3.pokaz();
	
	osoba* w = &os;
	w->pokaz();
	w = &pr3;
	w->pokaz();
	static_cast<pracownik*>(w)->pokaz();
	
	
	return 0;
}
