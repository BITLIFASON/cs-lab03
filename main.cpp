#include "histogram.h"

vector<double> input_numbers(size_t count)
{
    vector<double> result(count);
    for (size_t i = 0; i < count; i++)
    {
        cin >> result[i];
    }
    return result;
}

int main() {
    // Ввод данных
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    size_t font_size;
    bool wrong_size = false;
    while (!wrong_size)
    {
        cerr << "Enter font size: ";
        cin >> font_size; cerr << endl;
        wrong_size = check_size(font_size);
    }
    const auto bins = make_histogram(numbers, bin_count);    // Обработка данных
    show_histogram_svg(bins,font_size);  // Вывод данных
    return 0;
}
