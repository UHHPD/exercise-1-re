#include <iostream>
#include <fstream>

int main(){
    int zahl1, zahl2;
    
    std::ifstream fin("daten.txt");
    fin >> zahl1 >> zahl2;
    fin.close();
    std::cout << "Number 1 and 2:" << zahl1 << zahl2 <<std::endl;

    int a, b;

    std::ifstream input("daten.txt");
    std::ofstream output("datensumme.txt");

    for (int i = 0; i < 234; i++){
        input >> a >> b;
        int sum = a + b;
        output << sum << std::endl;
        std::cout << "This is row" << i+1 << ":" << a << " " << b << " " << "\nAnd sum:" << sum << std::endl; 
    }
    input.close();
    output.close();

    return 0;
}