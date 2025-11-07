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

double variance(double dsmean, int N){
    std::ifstream input("datensumme.txt");
    double variance = 0;
    double dsvalue;
    for (int i = 0; i < N; i++){
        input >> dsvalue;
        variance = variance + (dsvalue - dsmean) * (dsvalue - dsmean);
    }
    input.close();
    variance = variance / N;
    return variance;
}

int main() {
    //Exercise 1
    double dsmean = EW(234);
    std::cout << "mean: " << dsmean << std::endl;

    double dsvariance = variance(dsmean, 234);
    std::cout << "variance: " << dsvariance << std::endl;

    double sigma = sqrt(dsvariance);
    std::cout << "standard deviation: " << sigma << std::endl;
    
    //Exercise 2
    std::ifstream input("datensumme.txt");
    std::ofstream output("mittelwerte.txt");
    for (int i = 0; i < 26; i++){
        double sum_mean = 0;
        int add;
        for (int j = 0; j < 9; j++){
            input >> add;
            sum_mean = sum_mean + add;
        }
        sum_mean = sum_mean/9;
        output << sum_mean << std::endl;
    }
    input.close();
    output.close();

    std::ifstream input_again("datensumme.txt");
    std::ifstream input_mean("mittelwerte.txt");
    std::ofstream output_new("varianzen.txt");

    for (int i = 0; i < 26; i++){
        int value;
        double mean;
        input_mean >> mean;
        double sum_variance = 0;
        for (int j = 0; j < 9; j++){
            input_again >> value;
            sum_variance = sum_variance + (value - mean) * (value - mean);
        }
        sum_variance = sum_variance / 9;
        output_new << sum_variance << std::endl;
    }

    input_again.close();
    input_mean.close();
    output_new.close();

    std::ifstream var_input("varianzen.txt");
    std:: ifstream mean_input("mittelwerte.txt");
    double mean_variance = 0;
    double mean_of_means = 0;
    for (int i = 0; i < 26; i++){
        double var_value;
        double mean_value;
        var_input >> var_value;
        mean_input >> mean_value;
        mean_variance = mean_variance + var_value;
        mean_of_means = mean_of_means + mean_value;
    }
    mean_variance = mean_variance / 26;
    mean_of_means = mean_of_means / 26;
    double mean_variance_Bessel = mean_variance * (26.0/25.0);
    var_input.close();
    mean_input.close();
    std::cout << "mean of variances: " << mean_variance << std::endl;
    std::cout << "mean of means: " << mean_of_means << std::endl;
    std::cout << "mean of variance with Bessel correction: " << mean_variance_Bessel << std::endl;
    return 0;
}