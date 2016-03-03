#pragma once

#include <iostream>
#include <vector>
#include "../struct/structdef.h"

class CKNN
{
public:
	CKNN();
	~CKNN();
public:
	void CreateDataSet(strPointLabel &pl);
	void DefaultDataSet();
	char Classify(const std::vector<double> &inX, const int k);
	void PrintPointLabels();
private:
	std::vector<strPointLabel> m_vecPointLabel;
};