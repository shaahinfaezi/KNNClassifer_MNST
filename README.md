# KNN Classifier with KD-Tree for MNIST Dataset

This project implements a K-Nearest Neighbors (KNN) classifier using a KD-Tree for efficient nearest neighbor search, applied to the MNIST handwritten digit dataset. The code, written entirely in C++, achieves an impressive 91% accuracy on the test set without relying on external machine learning libraries.


## Overview

The KNN algorithm classifies data points by assigning them the majority class among their k nearest neighbors. While effective, this process can be slow for large datasets due to the computational cost of finding nearest neighbors. To improve efficiency, this project employs a KD-Tree, a space-partitioning data structure that accelerates nearest neighbor searches.

The implementation builds a KD-Tree from the MNIST training data and uses it to classify the test data. The MNIST dataset includes 60,000 training images and 10,000 test images of handwritten digits (0-9), each represented as a 28x28 pixel grid, flattened into a 784-dimensional vector.


## Features

- KD-Tree Implementation: A custom-built KD-Tree organizes the training data, enabling fast nearest neighbor queries.



- KNN Classifier: Uses the KD-Tree to efficiently locate k nearest neighbors and predicts classes via majority voting.



- MNIST Dataset Support: Handles loading and preprocessing of the MNIST dataset seamlessly.



- High Accuracy: Achieves 91% accuracy on the MNIST test set with k=3.



- Pure C++: Fully implemented in C++ using only standard libraries, ensuring portability and lightweight performance.


![KD](https://github.com/user-attachments/assets/cd20e238-095b-47f1-a3f4-6beaac93ed51)
![MNIST](https://github.com/user-attachments/assets/59fe27c2-3140-4d35-b0c0-db670db7fa95)
![knn](https://github.com/user-attachments/assets/f521f5b1-516f-4b07-ae6d-66cdacb89879)
