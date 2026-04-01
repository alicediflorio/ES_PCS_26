#include <iostream>
#include "rational.hpp"

using namespace std;

int main(void) {
	rational<int> a(3, 6);		// 1/2
	rational<int> b(3, -2);		// -3/2
	rational<int> c(0, 0);		// NaN
	rational<int> d(5, 0);		// + Inf
	rational<int> e(-7, 0);		// - Inf
	
	cout << "a = " << a << "\n";
	cout << "b = " << b << "\n";
	cout << "c = " << c << "\n";
	cout << "d = " << d << "\n";
	cout << "e = " << e << "\n";
	
	/* Operazioni */
	cout << "a + b = " << (a + b) << "\n";		// 1/2 + -3/2
	cout << "a - b = " << (a - b) << "\n";		// 1/2 - -3/2
	cout << "a * b = " << (a * b) << "\n";		// 1/2 * -3/2
	cout << "a / b = " << (a / b) << "\n";		// 1/2 / -3/2
	
	/* Operazioni con Inf e NaN */
	cout << "a + d = " << (a + d) << "\n";		// 1/2 + +Inf
	cout << "a + c = " << (a + c) << "\n";		// 1/2 + NaN
	cout << "d - e = " << (d - e) << "\n";		// +Inf - -Inf
	cout << "d - d = " << (d - d) << "\n";		// +Inf - +Inf

	return 0;
}