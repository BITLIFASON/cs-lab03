#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;

void svg_begin(double width, double height);
void svg_end();
void svg_text(double left, double baseline, string text, string font_size = "12");
void svg_rect(double x = 0, double y = 0, double width = 100, double height = 200, string stroke = "black", string fill = "black");
void show_histogram_svg(const vector<size_t>& bins, size_t font_size);
bool check_size(size_t font_size);

#endif // SVG_H_INCLUDED
