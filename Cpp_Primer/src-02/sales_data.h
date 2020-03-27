#pragma once

#include <iostream>
#include <string>

using namespace std;

typedef struct SalesData{
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
} SData;

