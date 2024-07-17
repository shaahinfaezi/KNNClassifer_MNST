#ifndef MNIST_H
#define MNIST_H

#include <string>

#include <string.h>


using std::string;


class MNIST {

public:

	float** input_Data(string filename, long columns,long row);

	int* input_Labels(string filename,long row);

};








#endif //MNIST_H
