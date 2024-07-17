#include "MNIST.h"

#include <string>

#include <fstream>

#include <iostream>

#include <sstream>

using namespace std;

float** MNIST::input_Data(string filename, long columns,long row) {

    float **data=new float*[10000];

	ifstream inFile;

    inFile.open(filename);


    if (!inFile.is_open()) {
        cout << "NO FILE HAS BEEN OPENED" << endl;

        return nullptr;
    }

    string line="";

    for (int i = 0; i < row; i++) {

        data[i] = new float[784];

        getline(inFile, line);

        stringstream inputString(line);

        for (int j = 0; j < columns; j++) {

            string temp="";

            getline(inputString, temp, ',');

            data[i][j] = stof(temp);

        }


        line = "";

    }


      

        return data;
    

    inFile.close();


}

int* MNIST::input_Labels(string filename, long row) {



    int* dataLabels;

    dataLabels = new int[row];

    ifstream inFile;

    inFile.open(filename);


    if (!inFile.is_open()) {
        cout << "NO FILE HAS BEEN OPENED" << endl;

        return nullptr;
    }

    string line;

    for (long i = 0; i < row; i++) {

        getline(inFile, line);

        stringstream inputString(line);


            string temp;

            getline(inputString, temp, ',');

            dataLabels[i] = stoi(temp);

            line = "";
    }


  

    return dataLabels;


    inFile.close();







}