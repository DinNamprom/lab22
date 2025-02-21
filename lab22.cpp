#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {				
    public:
        double real;
        double imag;
        ComplexNumber(double, double);
        ComplexNumber operator+(const ComplexNumber &);
        ComplexNumber operator-(const ComplexNumber &);
        ComplexNumber operator*(const ComplexNumber &);
        ComplexNumber operator/(const ComplexNumber &);
        ComplexNumber operator+(double);
        ComplexNumber operator-(double);
        ComplexNumber operator*(double);
        ComplexNumber operator/(double);
        bool operator==(const ComplexNumber &);
        double abs();
        double angle();
};

ComplexNumber::ComplexNumber(double x = 0, double y = 0) {
    real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c) {
    return ComplexNumber(real + c.real, imag + c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c) {
    return ComplexNumber(real - c.real, imag - c.imag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &c) {
    return ComplexNumber(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &c) {
    double denominator = c.real * c.real + c.imag * c.imag;
    
    if (denominator == 0) {
        throw runtime_error("Division by zero!");
    }

    double realPart = (real * c.real + imag * c.imag) / denominator;
    double imagPart = (imag * c.real - real * c.imag) / denominator;

    return ComplexNumber(realPart, imagPart);
}

ComplexNumber ComplexNumber::operator+(double d) {
    return ComplexNumber(real + d, imag);
}

ComplexNumber ComplexNumber::operator-(double d) {
    return ComplexNumber(real - d, imag);
}

ComplexNumber ComplexNumber::operator*(double d) {
    return ComplexNumber(real * d, imag * d);
}

ComplexNumber ComplexNumber::operator/(double d) {
    if (d == 0) {
        throw runtime_error("Division by zero!");
    }
    return ComplexNumber(real / d, imag / d);
}

ComplexNumber operator+(double c, const ComplexNumber &r) {
    return ComplexNumber(c + r.real, r.imag); 
}

ComplexNumber operator-(double c, const ComplexNumber &r) {
    return ComplexNumber(c - r.real, -r.imag); 
}

ComplexNumber operator*(double c, const ComplexNumber &r) {
    return ComplexNumber(c * r.real, c * r.imag);
}

ComplexNumber operator/(double c, const ComplexNumber &r) {
    double denominator = r.real * r.real + r.imag * r.imag;
    
    if (denominator == 0) {
        throw runtime_error("Division by zero!");
    }

    double realPart = (c * r.real) / denominator;
    double imagPart = (-c * r.imag) / denominator;

    return ComplexNumber(realPart, imagPart);
}

bool ComplexNumber::operator==(const ComplexNumber &c) {
    return (real == c.real && imag == c.imag);
}

bool operator==(double c, const ComplexNumber &r) {
    return (c == r.real && 0 == r.imag);
}

double ComplexNumber::abs() {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::angle() {
    return atan2(imag, real) * 180 / M_PI;
}

ostream & operator<<(ostream &os, const ComplexNumber &c) {
    if (c.imag == 0) return os << c.real;
    if (c.imag != 0 && c.real == 0) return os << c.imag << "i";
    if (c.imag < 0) return os << c.real << c.imag << "i";
    return os << c.real << "+" << c.imag << "i";
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





