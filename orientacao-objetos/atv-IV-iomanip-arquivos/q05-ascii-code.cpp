#include <iostream>
using std::cout, std::endl;

#include <iomanip>
using std::setw;

int main() {

    cout << "CÓD ASCII";
    cout << setw(9) << "|";
    cout << setw(18) << "CHARACTER" << endl;

    for (int i = 33; i < 127; i++) {
        cout.fill('0');
        cout << setw(3)  << i;
        cout.fill(' ');
        cout << setw(15) << "|";
        cout << setw(10) << static_cast<char>(i) << " " << endl;
    }

    return 0;
}

