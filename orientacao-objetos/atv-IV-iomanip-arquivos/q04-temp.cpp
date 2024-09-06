#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	
	int tempFahrt;
	double tempCels;

	cout << "Temperatura em Fahrenheit: ";
	cin >> tempFahrt;

	tempCels = ((tempFahrt - 32) / 9.0) * 5.0;

	cout << fixed << right;
	
  // Linha 1 	
	cout << setw(16) << "TEMPERATURA";
	cout << setw(6) << "|";
	cout << setw(10) << "VALOR" << endl;
	
	cout.fill('-');
	cout << setw(33) << ' ' << endl;

	// Linha 2
	cout.fill(' ');
	cout << setw(16) << "FAHRENHEIT";
	cout << setw(6) << "|";
	cout << setw(10) << tempFahrt << endl;
	
  // Linha 3
  cout << setw(16) << "CELSIUS";
	cout << setw(6) << "|";
	cout << setw(10) << setprecision(3) << showpoint << tempCels << endl;
	
	return 0;
}