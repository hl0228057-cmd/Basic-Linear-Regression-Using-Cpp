# Basic Linear Regression Using C++

Description: 
Made this in a little over an hour, it's a simple linear regression model implemented entirely from scratch in C++ without using any machine learning libraries. I mainly did this to understand how machine learning worked, including prediction, error calculation, optimization, and parameter updates.

Features: Mean Squared Error (MSE) loss, gradient descent, learning rate, learning rate decay, early stopping, and user input training data

How it works:
The model begins with weights and bias initalized as 0 and then does a baseline to determine whether to increase or decrease weights or bias. Then, it enters the training loop, which repeatedly: makes predictions, calculates prediction error, computes total loss using mean squared error, and then adjusts weights and bias to reduce error.

The loss equation is:
loss = (sigma * error ^ 2)/n

Example:
  Input:
    (1, 2),
    (2, 4),
    (3, 6)
  Output:
    Prediction = 2 * input + 0

After completing this mini project, I gained a much deeper understanding of how machine learning models work internally instead of relying on prebuilt libraries such as Scikit-Learn, and I hope this helps other learners too.
