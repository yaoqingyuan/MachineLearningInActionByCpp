#pragma once

struct strPointLabel 
{
	double x;
	double y;
	double distance;
	char label;

	strPointLabel()
	{
		x = 0.0;
		y = 0.0;
		distance = 0.0;
		label = ' ';
	}
};