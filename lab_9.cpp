#include <iostream>
#include <string>
#include <iostream>
using namespace std;

class Paczka{
	string adres;
	float f;
public:
	Paczka(): adres(""), f(0.0) {}
	Paczka(string adres, float f): adres(adres), f(f) {}

    float getF(){
        return f;
    }
	
	
	friend ostream& operator<<(ostream& out, Paczka p){
		out << p.adres << " " << p.f << endl;
		return out;
		}
	};


class Osoba{
	string imie, nazwisko;
public:
	Osoba(): imie(""), nazwisko("") {}
	Osoba(string imie, string nazwisko): imie(imie), nazwisko(nazwisko) {}
	
	bool operator==(const Osoba& o){
		if(imie == o.imie and nazwisko == o.nazwisko){
			return true;
			}
		else{
			return false;
			}
		}
    Osoba& operator=(const Osoba& o){
        if(this == &o){
            return *this;
        }
        imie = o.imie;
        nazwisko = o.nazwisko;
        return *this;

    }
	
	friend ostream& operator<<(ostream& out, Osoba o){
		out << o.imie << " " << o.nazwisko << endl;
		return out;
		}
	};

class Kurier: public Osoba{
    Paczka* paczki;
    int n;

public:
    Kurier(): Osoba(), paczki(nullptr), n(0) {}
  
    Kurier(Paczka* start, Paczka* end) {
    	cout<< "wywolano konstruktor parametryczny"<< endl;
    	n = end - start;
    	paczki = new Paczka[n];
    	for(int i = 0; i<n; i++){
    		paczki[i] = start[i];
    	}
    
    }
    
    Kurier(const Kurier& k): Osoba(k), n(k.n){ 
    cout<<"wywolano konstruktor kopiujacy"<< endl;
        paczki = new Paczka[n];
        for(int i = 0; i<n; i++){
            paczki[i] = k.paczki[i];
        }
    }

    float wartosc(){
        float suma = 0.0;
        for(int i = 0; i<n; i++){
            suma += paczki[i].getF();
        }
        return suma;
    }
    
    Kurier& operator=(Kurier& k){
    cout<< "wywolano operator przypisania" << endl;
    	if(this == &k)return * this;
    	
    	delete[]paczki;
    	
    	n = k.n;
    	paczki = new Paczka[n];
    	for(int i = n; i<n; i++){
    		paczki[i] = k.paczki[i];
    	}
    	return *this; 
    }
    
    Paczka& operator[](int index){
    	if(index>= n) throw out_of_range("Index out of range");
    	return paczki[index];
    }
    

	
	Kurier& operator+(Paczka& p){
	cout<<"dodano nowa paczke do "<< n << " elementow"<<endl;
		Paczka* nowe_paczki = new Paczka[n+1];
		
		for(int i = 0; i<n; i++){
			nowe_paczki[i] = paczki[i];
		}
		nowe_paczki[n] = p;
		delete[] paczki;
		n+= 1;
		paczki = nowe_paczki;
		return *this;
	}
	
	~Kurier(){
		delete[] paczki;
		paczki = nullptr;
	
	}

};


int main()
{
  Paczka p[] = {
    Paczka("Dabrowskiego 33", 123.00), 
    Paczka("NMP 12", 40.00),
    Paczka("Armii Krakowej 4", 30.00), 
    Paczka("Andersa 6", 51.00),
    Paczka("Kukuczki 13", 12.00), 
    Paczka("Skrzyneckiego 5", 40.00), 
  };

  Osoba o1("Jan", "Kowalski");
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;

  {
      Osoba o2(o1);
      cout << "---- 2 ----" << endl;
      cout << o2 << endl;
      
      cout << "---- 3 ----" << endl;
      cout << boolalpha << (o1 == o2) << endl;
      
      Osoba o3;
      cout << "---- 4 ----" << endl;
      cout << o3 << endl;

      o3 = o2;
      cout << "---- 5 ----" << endl;
      cout << o3 << endl;
      
  }   

  cout << "---- 6 ----" << endl;
  cout << o1 << endl;

  Kurier k1(p, p+3);
  cout << "---- 7 ----" << endl;
  cout << k1.wartosc() << endl;
 
  Kurier k2;
  cout << "---- 8 ----" << endl;
  cout << k2.wartosc() << endl;

  {
    Kurier k3(k1);
    cout << "---- 9 ----" << endl;
    cout << k3.wartosc() << endl;

    k2 = k3;
    cout << "---- 10 ----" << endl;
    cout << k2.wartosc() << endl;

    k1 = k1 + p[4]; 
    k1 = k1 + p[5];

    cout << "---- 11 ----" << endl;
    cout << k1.wartosc() << endl;

  }
  

  cout << "---- 12 ----" << endl;
  cout << k2.wartosc() << endl;

  try{
    Kurier k4(p, p+3);
    cout << "---- 13 ----" << endl;
    for(int i=0; i<10; ++i){
      cout << k4[i] << ",";
    }
    cout << endl;
  }
  catch(...){
    cout << "---- 14 ----" << endl;
    cout << "Wyjatek" << endl;
  }

  return 0;
}
