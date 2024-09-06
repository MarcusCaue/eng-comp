#include <iostream>
#include <iomanip>

using std::fixed, std::setprecision;
using std::cout, std::endl;

int main() {
	
	const double number = 100.453627;
	cout << fixed;

	cout << "Número formatado (1 casas decimais): " << setprecision(1) << number << endl;
	cout << "Número formatado (2 casas decimais): " << setprecision(2) << number << endl;
	cout << "Número formatado (3 casas decimais): " << setprecision(3) << number << endl;
	cout << "Número formatado (4 casas decimais): " << setprecision(4) << number << endl;
	
	return 0;
}