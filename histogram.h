#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED

#include <vector>
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <string>
#include <sstream>
using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

void find_minmax(const vector<double>& numbers, double& min, double& max);
vector <size_t> make_histogram(struct Input data);
void show_histogram_text(vector <size_t>& bins);

#endif // HISTOGRAM_H_INCLUDED
