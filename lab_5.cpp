#include <iostream>
#include <cmath>

using namespace std;

class point{
	double wsp[3];

public:
	point(): wsp{0.0,0.0,0.0} {}
	
	point(double x, double y, double z): wsp{x,y,z} {}
	
	point(const double points[3]): wsp{points[0], points[1], points[2]} {}
	
	double distance(const point& p) const{
		return sqrt(pow(wsp[0] - p.wsp[0],2) + pow(wsp[1] - p.wsp[1],2) + pow(wsp[2] - p.wsp[2],2));
	}
	
	double operator[](int i) const{
		return wsp[i];
	}

	friend ostream& operator<<(ostream& output, const point& p){
		return output << "Point(" << p.wsp[0] << ", " << p.wsp[1] << ", " << p.wsp[2] << ")";  
	}
	
	friend istream& operator>>(istream& input, point& p){
		return input>> p.wsp[0] >> p.wsp[1] >> p.wsp[2];
	}
	
	point operator+(const point& p) {
    	return point(wsp[0] + p.wsp[0], wsp[1] + p.wsp[1], wsp[2] + p.wsp[2]);
	}
		
	point operator-(const point& p) {
    	return point(wsp[0] - p.wsp[0], wsp[1] - p.wsp[1], wsp[2] - p.wsp[2]);
	}
};


int main()
{
	double x[2][3] = {{1.0, 1.0, 1.0},{1.0, 2.0, 3.0}};
	point p1(x[0]), p2(x[1]);
	const point p3(0.4, 0.2, 0.1);

	cout << p1 << ", " << p2 << '\n';
	cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n';
	cout << p1.distance(point()) << ", "<< p3.distance(p1) << '\n';
	cout << p1 + p2 << ", " << p1 - p3 << '\n';
	
	/*
	cout << 3.14 * p2 << ", " << p2 * 3.14 << '\n';
	cout << (p1 < p3) << ", " << (p1 == point(1.0, 1.0, 1.0)) << '\n';
	cin >> p1;
	cout << p1 << '\n';
*/	
	return 0;
}
