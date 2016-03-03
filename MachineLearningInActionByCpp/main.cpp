#include <iostream>
#include "knn/knn.h"

void main()
{
	CKNN knn;
	knn.DefaultDataSet();

	std::vector<double> inX;
	inX.push_back(0);
	inX.push_back(0);

	int k = 1;
	char label = knn.Classify(inX, k);
	std::cout << label << std::endl;

	std::cin.get();
}