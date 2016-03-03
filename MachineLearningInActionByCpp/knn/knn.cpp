#include "knn.h"
#include <algorithm>
#include <assert.h>

CKNN::CKNN()
{
}

CKNN::~CKNN()
{
}

void CKNN::DefaultDataSet()
{
	strPointLabel temp;
	temp.x = 1.0;
	temp.y = 1.1;
	temp.label = 'A';
	temp.distance = 0.0;
	m_vecPointLabel.push_back(temp);
	temp.x = 1.0;
	temp.y = 1.0;
	temp.label = 'A';
	temp.distance = 0.0;
	m_vecPointLabel.push_back(temp);
	temp.x = 0.0;
	temp.y = 0.0;
	temp.label = 'B';
	temp.distance = 0.0;
	m_vecPointLabel.push_back(temp);
	temp.x = 0.0;
	temp.y = 0.1;
	temp.label = 'B';
	temp.distance = 0.0;
	m_vecPointLabel.push_back(temp);

	std::cout << "默认初始化的点分布与标签：\n";
	for (int i = 0; i < 4; ++i)
	{
		std::cout << m_vecPointLabel[i].x << "\t" << m_vecPointLabel[i].y << "\t" << m_vecPointLabel[i].label << "\n";
	}
}

bool MySort(const strPointLabel &lhs, const strPointLabel &rhs)
{
	return lhs.distance < rhs.distance;
}

char CKNN::Classify(const std::vector<double>& inX, const int k)
{
	assert(m_vecPointLabel.size() >= k);

	for (int i = 0; i < m_vecPointLabel.size(); ++i)
	{
		m_vecPointLabel.at(i).distance = sqrt(pow(m_vecPointLabel.at(i).x - inX[0], 2.0) + pow(m_vecPointLabel.at(i).y - inX[1], 2.0));
	}

	std::sort(m_vecPointLabel.begin(), m_vecPointLabel.end(), MySort);

	int ANum = 0;
	int BNum = 0;
	for (int i = 0; i < k; ++i)
	{
		if (m_vecPointLabel.at(i).label == 'A')
		{
			ANum++;
		}
		else if (m_vecPointLabel.at(i).label == 'B')
		{
			BNum++;
		}
	}

	return ANum > BNum ? 'A' : 'B';
}

void CKNN::PrintPointLabels()
{
	for (std::vector<strPointLabel>::iterator it = m_vecPointLabel.begin(); it != m_vecPointLabel.end(); ++it)
	{
		std::cout << it->x << "\t" << it->y << "\t" << it->label << "\t" << it->distance << std::endl;
	}
}

void CKNN::CreateDataSet(strPointLabel & pl)
{
	m_vecPointLabel.push_back(pl);
}

