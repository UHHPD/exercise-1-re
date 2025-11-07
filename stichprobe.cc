#include <iostream>
#include <fstream>
#include <cmath>

double EW(int N){
    double sum = 0;
    int add;
    std::ifstream input("datensumme.txt");

    for (int i = 0; i < N; i++){
        input >> add;
        sum = sum + add;
    }

    input.close();
    return sum/N;
}

double variance(double dsmean){
    std::ifstream input("datensumme.txt");
    double variance = 0;
    double dsvalue;
    for (int i = 0; i < 234; i++){
        input >> dsvalue;
        variance = variance + (dsvalue - dsmean) * (dsvalue - dsmean);
    }
    input.close();
    variance = variance / 234;
    return variance;
}

int main() {
    double dsmean = EW(234);
    std::cout << "mean: " << dsmean << std::endl;

    double dsvariance = variance(dsmean);
    std::cout << "variance: " << dsvariance << std::endl;

    double sigma = sqrt(dsvariance);
    std::cout << "standard deviation: " << sigma << std::endl;
    
    return 0;
}