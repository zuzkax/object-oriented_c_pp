#include <iostream>

using namespace std;

class punkt {
	float _x,_y,_z; 
public:
	//konstruktor domyślny
    punkt() : _x(0), _y(0), _z(0) {}

    //konstruktor parametryczny
    punkt(float x, float y, float z) : _x(x), _y(y), _z(z) {}
    
	//
	float& x(){ // x to metoda zwracajaca nie wartosc a adres komorki
		return _x;
		}
	const float& x() const{ // funkcja przeciazona dla const 
		return _x;
		}
	//
	float& y() {
		return _y;
		}
	const float& y() const {
		return _y;
		}	
	//
	float& z(){
		return _z;
		}
	const float& z() const{
		return _z;
		}
	
	};
	
class prostokat{
	float _a,_b;
	punkt _p;
	
public:
	prostokat(): _p(0,0,0), _a(1), _b(1){}
	
	prostokat(float x, float y, float z, float a, float b): _p(x, y, z), _a(a), _b(b) {}
	
	prostokat(const punkt& p, float a, float b): _p(p), _a(a), _b(b) {}
	
	float& x(){
		return _p.x();
		}
	float& y(){
		return _p.y();
		}
	float& z(){
		return _p.z();
		}
	const float& x() const {
		return _p.x();
		}	
	const float& y() const {
		return _p.y();
		}
	const float& z() const {
		return _p.z();
		}
	
	
	float& a(){
		return _a;
		}
	float& b(){
		return _b;
		}
	const float& a() const{
		return _a;
		}
	const float& b() const{
		return _b;
		}
	
	float pole() const{
		return _a *_b;
		}
	};
	
class graniastoslup{
	float _h;
	prostokat _pr; //jako podstawa
public:
	graniastoslup(): _pr(0,0,0,1,1), _h(1){}
	graniastoslup(float x, float y, float z, float a, float b,float h): _pr(x,y,z,a,b), _h(h) {}
	graniastoslup(const punkt& p, float a, float b,float h): _pr(p,a,b), _h(h) {}
	graniastoslup(const prostokat& pr,float h): _pr(pr), _h(h) {}

	float& x() {
		return _pr.x();
		}
	float& y() {
		return _pr.y();
		}
	float& z() {
		return _pr.z();
		}
	const float& x() const{
		return _pr.x();
		}
	const float& y() const {
		return _pr.y();
		}
	const float& z() const{
		return _pr.z();
		}

	float& a(){
		return _pr.a();
		}
	float& b(){
		return _pr.b();
		}
	const float& a() const{
		return _pr.a();
		}
	const float& b() const{
		return _pr.b();
		}
	
	float& h(){
		return _h;
		}
	const float& h() const{
		return _h;
		}
	
	float objetosc()const{
		return _pr.pole() * _h;
	}
	
	};

int main()
{
    punkt p1, p2(1,2,3); // w klasie punkt konstruktor domyslny i parametryczny, przyjmuje float
    const punkt p3(1.1,2.2,3.3); 
    cout << p3.x() << '\t' << p3.y() << '\t' << p3.z() << endl; // po kropce metoda 
    
    p1.x()=1; p1.y()=10; p1.x()=100; 
    cout << p1.x() << '\t' << p1.y() << '\t' << p1.z() << endl; 

    prostokat pr1, pr2(1,2,3, 10.5, 20.5); 
    const prostokat pr3(p2,5,5); 
    
    cout << pr3.x() << '\t' << pr3.y() << '\t' << pr3.z() << '\n'  
     << pr3.a() << '\t' << pr3.b()<< '\n' 
     << pr3.pole() << endl; 

    pr1.x()=2; pr1.y()=20; pr1.z()=200; pr1.a()= 10; pr1.b()=10; 
    cout << pr1.x() << '\t' << pr1.y() << '\t' << pr1.z() << '\n'  
     << pr1.a() << '\t' << pr1.b()<< '\n' 
     << pr1.pole() << endl; 
          
    graniastoslup g1, g2(1,2,3,10.5,20.5,30.5), g3(p2,100,200,300); 
    const graniastoslup g4(pr3,5); 
   
    cout << g4.x() << '\t' << g4.y() << '\t' << g4.z() << '\n'  
     << g4.a() << '\t' << g4.b() << '\t' << g4.h() << '\n'
     << g4.objetosc() << endl; 
     
    g1.a()=10; g1.b()=10; g1.h()=10; 
    cout << g1.x() << '\t' << g1.y() << '\t' << g1.z() << '\n'  
     << g1.a() << '\t' << g1.b() << '\t' << g1.h() << '\n' 
     << g1.objetosc() << endl; 

     return 0;
}
