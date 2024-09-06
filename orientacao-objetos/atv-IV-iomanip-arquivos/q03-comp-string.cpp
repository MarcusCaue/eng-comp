#include <iostream>
using std::getline, std::cout, std::endl, std::cin;

#include <iomanip>
using std::setw;

#include <string>
using std::string;


int main() {
	
	string str;
	cout << "Digite uma string: ";
	getline(cin, str);

	const int lenStr = str.length();
	cout << "Tamanho da string: " << lenStr << endl;
	cout << "Saída formatada:" << endl;
	
	cout << setw(lenStr * 2) << str << endl;

	return 0;
}