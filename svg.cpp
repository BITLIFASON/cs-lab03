#include "svg.h"

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text, string font_size)
{
    cout << "<text x='" << left << "' y='" << baseline << "' font-size='" << font_size << "'>"<< text<< "</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='"<< x << "' y='" << y <<"' width='" << width <<"' height='" << height <<"' stroke='"<< stroke <<"' fill='"<< fill <<"'/>";
}

void show_histogram_svg(const vector<size_t>& bins, size_t font_size)
{
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    const auto BLOCK_WIDTH = 10;
    double top = 0;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    const size_t SCREEN_WIDTH = 40;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 5;
    size_t max_count = 0;
    for (size_t bin : bins)
    {
        if (bin > max_count)
        {
            max_count = bin;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;
    for (size_t bin : bins)
    {
    size_t height = bin;
    if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            double lenght_rect = bin * scaling_factor;  //��� ��� height = (size_t)(bin * scaling_factor) �������� �� ���������
            height = (size_t)(lenght_rect);
        }
    const double bin_width = BLOCK_WIDTH * height;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin),to_string(font_size));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"red", "#ffeeee");
    top += BIN_HEIGHT;
}
    svg_end();
}
