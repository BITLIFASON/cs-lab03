#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>

vector<double> input_numbers(istream& in, size_t count)
{
    vector <double> result(count);
    for (size_t i=0; i<count; i++)
    {
        in >> result[i];
    }
    return result;
}

Input read_input(istream& in, bool prompt) {
    Input data;

    if(prompt) cerr << "Enter number count: ";
    size_t number_count;
    cin >> number_count;

    if(prompt) cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    if(prompt) cerr << "Enter column count: ";
    size_t bin_count;
    cin >> bin_count;
    data.bin_count = bin_count;

    return data;
}

int main(int argc, char* argv[]) {
    curl_global_init(CURL_GLOBAL_ALL);
    if(argc > 1)
    {
       CURL* curl = curl_easy_init();
       if(curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        }
    }
    const auto data = read_input(cin, true);
    const auto bins = make_histogram(data);
    show_histogram_svg(bins);
    return 0;
}
