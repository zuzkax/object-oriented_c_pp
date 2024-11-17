#include<iostream>
#include<cmath>
#include<cstring>
#include <fstream>

using namespace std;

class point{
	float x,y;
public:
	
	point(): x(0.0), y(0.0) {}
	point(float x, float y): x(x), y(y) {}
	
    void show() const {
        cout << "(" << x << ", " << y << ")";
    }
	
    float distance(const point& p) const {
        return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
    }
	
	float getx() const { return x; }
    float gety() const { return y; }
	
};

class polygon{
	point* nodes;
	int* count;
	int n;
public:
	polygon(): nodes(nullptr), n(0) {}
	
	polygon(int n): n(n) {
		nodes = new point[n];
		count = new int[n];
		}	
	
	~polygon(){
		delete[] nodes;
		delete[] count;
	}
	
	void add(float x, float y, int a){
		nodes[a-1] = point(x,y);
		}
	
	

	float perimeter(){
		float output = 0.0;
		for(int i = 0; i<n; i++){
			output += nodes[i].distance(nodes[(i + 1) % n]);
		}
		return output;	
	}
	float area() const {
		float area = 0.0;
		for(int i = 0; i<n; i++){
			area += nodes[i].getx() * nodes[(i+1)%n].gety() - nodes[i].gety() * nodes[(i+1)%n].getx();
			cout<<area<<endl;
		}
		return area;
		 
	}
	
    void show() const {
        for (int i = 0; i < n; i++) {
            cout << "Point " << i+1 << ": ";
            nodes[i].show();  
            cout << endl;
        }
    }
};
	
class reader{
public:
	static polygon read(const string& input){//static metoda nalezy do klasy nie do konkretnego obiektu , mozna ja wywolac bez koniecznosci tworzenia obiektu reader
		ifstream infile(input);
		if(!infile){
			cerr<<"blad otwarcia pliku"<<endl;
		}
		int n = 0;
		infile>>n;
		polygon p(n);
		
		for(int i = 0; i<n; i++){
			int a;
			float x,y;
			infile>>a>>x>>y;
			p.add(x,y,a);
		}
		
		return p;
	}
};
	
int main(int argc, char * argv[]){
	
	if(argc!=2){
		cerr<<"Zla liczba argumentow, podaj nazwe pliku txt";
		return -1;
	}
	polygon p = reader::read(argv[1]);
	
	p.show();
	cout<<"obwod "<< p.perimeter() << endl;
	cout<<"pole "<< p.area() << endl; //0?
	
	
	return 0;
}
