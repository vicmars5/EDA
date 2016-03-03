#include <iostream>

using namespace std;

int sum (unsigned long n) {
	if (n == 1 or n == 0){
		return n;
	} else {
		return n + sum(n-1);
	}
}

int factorial (unsigned long n) {
	if (n == 1 or n == 0){
		return n;
	} else {
		return n * factorial(n-1);
	}
}

int fibonacci (unsigned long p) {
	if (p == 1 or p == 0){
		return 1;
	} else {
		return  fibonacci(p-1) + fibonacci(p-2);
	}
}

int main () {
	unsigned long numero;
	int op;
	cout << "Menu:" << endl
			<< "1.-Sum" << endl
			<< "2.-Factorial" << endl
			<< "3.-Fibonacci" << endl;
	cin >> op;

	cout << "Valor: ";
	cin >> numero;
	cout << "Resultado: ";

	switch (op) { 
		case 1:
			cout << sum(numero);
			break;
		case 2:
			cout << factorial(numero);
			break;
		case 3:
			cout << fibonacci(numero);
			break;
	}

	cout << endl;
	return 0;
}

