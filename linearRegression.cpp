#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // data
    int dataLength;
    cout << "number of data points: "; cin >> dataLength;

    vector<int> inputs (dataLength);
    vector<int> expectedOutputs (dataLength);

    for (int i = 0; i < dataLength; i++) {
        cout << "x" << i+1 << ": "; cin >> inputs[i];
        cout << "y" << i+1 << ": "; cin >> expectedOutputs[i];
    }

    // initial values before training
    double weight = 0;
    double bias = 0;

    // training values
    int iterations = 3e+4;
    double learningRate = 1e-2;

    double prevLoss;
    double currentLoss;



    // initial loss
    vector<double> errors;
    double total = 0;

    for (int j = 0; j < inputs.size(); j++) {

        // prediction = weight * input + bias
        double pred = weight * inputs[j] + bias;

        // error = actual - prediction
        double error = expectedOutputs[j] - pred;
        errors.push_back(error);
    }

    // loss = ∑(error^2)/n
    for (double error : errors) {
    total += error * error;
    }
    currentLoss = total / inputs.size();



    // training loop
    for (int i = 0; i < iterations; i++) {
        if (currentLoss < 1e-6) break;

        vector<double> errors;
        double total = 0;

        double biasChange = 0, weightChange = 0;

        for (int j = 0; j < inputs.size(); j++) {
            // prediction = weight * input + bias
            double pred = weight * inputs[j] + bias;

            // error = actual - prediction
            double error = expectedOutputs[j] - pred;
            errors.push_back(error);

            // bias and weight change
            biasChange += error;
            weightChange += error * inputs[j];
        }

        prevLoss = currentLoss;

        // loss = ∑(error^2)/n
        for (double error : errors) {
            total += error * error;
        }
        currentLoss = total / inputs.size();

        // adjust weights and bias
        biasChange /= inputs.size();
        weightChange /= inputs.size();

        bias += learningRate * biasChange;
        weight += learningRate * weightChange;

        // learning rate decay
        if (i > 0 && i % 1000 == 0) learningRate *= 0.95;
    }

    // y = mx + b
    cout << "Prediction = " << round(weight * 100.0) / 100.0 << " * input + " << round(bias * 100.0) / 100.0;

    return 0;
}