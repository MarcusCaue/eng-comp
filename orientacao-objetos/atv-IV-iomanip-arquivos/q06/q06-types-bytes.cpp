#include <iostream>
using std::cout, std::endl;

#include <iomanip>
using std::setw;

#include <fstream>
using std::ofstream, std::ios, std::ifstream, std::left, std::right;

#include <vector>
using std::vector;

#include <string>
using std::string;


void escreverDados(ofstream* file) {
    (*file) << "char," << sizeof(char) << endl;
    (*file) << "short," << sizeof(short) << endl;
    (*file) << "int," << sizeof(int) << endl;
    (*file) << "long," << sizeof(long) << endl;
    (*file) << "float," << sizeof(float) << endl;
    (*file) << "double," << sizeof(double) << endl;
    (*file) << "long double," << sizeof(long double) << endl;
    (*file) << "unsigned int," << sizeof(unsigned int) << endl;
    (*file) << "unsigned long," << sizeof(unsigned long) << endl;
}

vector<string>* readData(ifstream* file) {
    vector<string>* typesSizes = new vector<string>[2];

    string type, size;
    while (!(*file).eof()) {
        getline(*file, type); // lê uma linha

        int indexVirg = type.find(',');

        if (indexVirg != -1) {
            size = type.substr(indexVirg + 1);
            type = type.substr(0, indexVirg);

            typesSizes[0].push_back(type);            
            typesSizes[1].push_back(size);            
        }
    }

    return typesSizes;
}

int main() {
    
    // Escrita -> Saída  
    ofstream fileOut = ofstream("./dados.dat", ios::trunc);
    escreverDados(&fileOut);
    fileOut.close();

    cout << "Dados escritos no arquivo" << endl;

    // Leitura -> Entrada
    ifstream fileIn = ifstream("dados.dat", ios::in);
    vector<string>* typesSizes = readData(&fileIn);
    fileIn.close();

    cout << "Dados lidos do arquivo" << endl << endl;

    for (int i = 0; i < typesSizes[0].size(); i++) {
        cout.fill(' ');
        cout << left << setw(20) << typesSizes[0][i] << "|" << setw(15) << " ";
        
        cout.fill('0');
        cout << right << setw(2) << typesSizes[1][i] << endl;
    }
    
    delete [] typesSizes;
    return 0;
}