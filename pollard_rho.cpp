#include <iostream>
#include <cmath>
using namespace std;

int gcd( int a, int b) {
	int remainder;
	while (b != 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}

int main () {

	int number = 10403;
	int x_fixed = 2,cycle_size = 2,x = 2,factor = 1;

	while (factor == 1) {

		for (int count=1;count <= cycle_size && factor == 1;count++) {
			int tmp = x;
			x = (x*x+1)%number;
// cout << "X::before: " << tmp << ", after: " << x << endl;
			factor = gcd(abs(x - x_fixed), number);
		}
		cycle_size *= 2;
		x_fixed = x;
	}
	cout << "target: " << number << ", factor: " << factor << ", x: " << x << ", cycle_size: " << cycle_size << endl;
}
