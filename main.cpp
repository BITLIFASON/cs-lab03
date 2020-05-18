#include "histogram.h"
#include "svg.h"
#include <windows.h>

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
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD build;
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & 0xff;
    DWORD version_minor = version >> 8;
    printf("M_version10 = %lu\n",version_major);
    printf("M_version16 = %08lx\n",version_major);
    printf("m_version10 = %lu\n",version_minor);
    printf("m_version16 = %08lx\n",version_minor);
    if ((info & 0x80000000) == 0)
    {
    build = platform;
    }
    else printf("minor_bit = %u",1);
    printf("Windows v%lu.%lu (build %lu)\n",version_major,version_minor,build);
    return 0;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    cerr << "Enter numbers: ";
    const auto numbers = input_numbers(number_count);
    size_t bin_count;
    cerr << "Enter column count: ";
    cin >> bin_count;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins);
}
