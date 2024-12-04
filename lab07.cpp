#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Osoba{
	string imie, nazwisko;
	unsigned long long pesel;	
public:
	Osoba(): imie(""), nazwisko(""), pesel(0){}
	Osoba(string imie, string nazwisko, unsigned long long pesel): imie(imie), nazwisko(nazwisko), pesel(pesel){}
	
	bool operator==(const Osoba& inna){
		if(imie == inna.imie and nazwisko == inna.nazwisko and pesel == inna.pesel){
			return true;
		}
		else {return false;}	
	}
	
	friend ostream& operator<<(ostream& output,const Osoba& o){
		output << o.imie << " " << o.nazwisko << " " << o.pesel;
		return output;
	}
	
	friend istream& operator>>(istream& input,  Osoba& o){
		input >> o.imie >> o.nazwisko >> o.pesel;
		return input;
	}
	

	
};

class BazaDanych{
	Osoba* osoby;
	int n;
public:
	BazaDanych():osoby(nullptr), n(0) {}
	
	BazaDanych(const BazaDanych& inna){
		n = inna.n;
		osoby = new Osoba[n];
		
		for(int i =0; i<n; i++){
			osoby[i] = inna.osoby[i];
		}	
	}
	
	Osoba& operator[](int n){
		return osoby[n];
		
	}
	BazaDanych& operator=(const BazaDanych& inna){
		//cout<<"wywolano operator przypisania"<<endl;
		if(this==&inna){
			return *this;
		}
		//cout<<"obiekty sie roznia"<<endl;
		delete [] osoby;
		n = inna.n;
		if(n>0){
			osoby = new Osoba[n];
			for(int i = 0; i<n; i++){
				osoby[i] = inna.osoby[i];
				
			}
		}else{
			osoby = nullptr;
		}
		
		return *this;
	}
	//nowa baza n+1, skopiowanie starej, dodanie osoby, zwolnienie pamieci 
	BazaDanych operator+(const Osoba& o)const{
		//cout << "Operator +: Dodawanie osoby. Obecny rozmiar n=" << n << endl;
		BazaDanych nowa;
		nowa.n = n+1;
		//cout << " Obecny rozmiar n=" << nowa.n << endl;

		nowa.osoby = new Osoba[nowa.n];
			
		for(int i=0; i<n; i++){
			nowa.osoby[i] = osoby[i];		
		}
		nowa.osoby[n] = o;	
		//cout<<"osoba nr 1"<<nowa.osoby[0]<<endl;
		return nowa;		
	}
	BazaDanych operator+(const BazaDanych& b)const{
		BazaDanych nowa;
		nowa.n = n + b.n;
		nowa.osoby = new Osoba[nowa.n];
		
		for(int i = 0; i<n; i++){
			nowa.osoby[i] = osoby[i];
		}
		for(int i = 0; i<b.n; i++){
			nowa.osoby[n + i] = b.osoby[i];
		}
		return nowa;
		
	}
	BazaDanych operator-(const Osoba& o)const{
		int x = 0;
		
		for(int i = 0; i<n;i++){
			if(!(osoby[i] == o)){
				x += 1;
			}
		}
		if(x == n){
			return *this;
		}
		BazaDanych nowa;
		nowa.n = x;
		nowa.osoby = new Osoba[nowa.n];
		
		int j = 0;
		for(int i = 0; i<n;i++){
			if(!(osoby[i] == o)){
				nowa.osoby[j++] = osoby[i];
			}
		}
		return nowa; 
	}
	
	const Osoba& operator[](int i)const{
		return osoby[i];
	}
	
	friend ostream& operator<<(ostream& output, const BazaDanych& b){
		
		if(b.osoby == nullptr){
			output << "baza danych pusta" << endl;
		}
		else{
			for(int i = 0; i<b.n; i++){
				output << b.osoby[i]<< endl;
			}
		}
		return output;
	}
	
	~BazaDanych(){
		if(osoby != nullptr){
			delete [] osoby;
		}
	}
	
	int liczbaOsob(){
		return n;
	}
	
	
};

int main()
{
  Osoba o1;
  cout << "---- 1 ----" << endl;
  cout << o1 << endl;

  Osoba o2("Jan", "Kowalski", 11111111111);
  cout << "---- 2 ----" << endl;
  cout << o2 << endl;
      
  cout << "---- 3 ----" << endl;
  cout << boolalpha << (o1 == o2) << endl;

  BazaDanych db1;
  cout << "---- 4 ----" << endl;
  cout << db1;
  
  db1 = db1 + o1;
  cout << "---- 5 ----" << endl;
  cout << db1;
  
 
  ifstream plik_we("zadanie7.txt");
  if(!plik_we)
  {
    cout << "---- 6 ----" << endl;
    return 1;
  }
   
  while(plik_we >> o2)
  {
      db1 = db1 + o2;
  }
  cout << "---- 7 ----" << endl;
  cout << db1;
   
  {
      BazaDanych db2(db1); 
      cout << "---- 8 ----" << endl;
      cout << db2;
  }
  cout << "---- 9 ----" << endl;
  cout << db1;
 
  BazaDanych db3;
  db3 = db1 + db1;
  cout << "---- 10 ----" << endl;
  cout << db3;
   
  for(int i=0; i<db3.liczbaOsob(); ++i)
  {
      cout << db3[i] << endl; 
  }
 
  cout << "---- 11 ----" << endl;  
  
  db1 = db1 - o1;
  
  cout << "---- 12 ----" << endl;
  cout << db1;
  
  cout << "---- 13 ----" << endl;
  cout << db3;
  cout << "---- 14 ----" << endl;
  
  return 0;
}
