#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // data
    int dataLength = 0;
    while (dataLength < 2) {
        cout << "number of data points: ";
        cin >> dataLength;
    }

    const int n = dataLength;

    vector<double> inputs (n);
    vector<double> expectedOutputs (n);

    for (int i = 0; i < n; i++) {
        cout << "x" << i+1 << ": "; cin >> inputs[i];
        cout << "y" << i+1 << ": "; cin >> expectedOutputs[i];
    }

    // initial values before training
    double weight = 0;
    double bias = 0;

    // training values
    int iterations = 3e+4;
    double learningRate = 1e-2;

    double currentLoss;



    // initial loss
    double total = 0;

    for (int j = 0; j < n; j++) {
        double pred = weight * inputs[j] + bias;
        double error = expectedOutputs[j] - pred;
        total += error * error;
    }

    currentLoss = total / (2 * n);



    // training loop
    for (int i = 0; i < iterations; i++) {
        if (currentLoss < 1e-6) break;

        double total = 0;

        double biasChange = 0, weightChange = 0;

        for (int j = 0; j < n; j++) {
            double pred = weight * inputs[j] + bias;
            double error = pred - expectedOutputs[j];

            total += error * error;
            biasChange += error;
            weightChange += error * inputs[j];
        }

        currentLoss = total / (2 * n);

        // adjust weights and bias
        biasChange /= n;
        weightChange /= n;

        bias -= learningRate * biasChange;
        weight -= learningRate * weightChange;

        // learning rate decay
        if (i > 0 && i % 1000 == 0) learningRate *= 0.95;
    }

    // y = mx + b
    cout << "y = " << round(weight * 100.0) / 100.0 << "x + " << round(bias * 100.0) / 100.0;

    return 0;
}
