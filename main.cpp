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
    in >> number_count;

    if(prompt) cerr << "Enter numbers: ";
    data.numbers = input_numbers(in, number_count);

    if(prompt) cerr << "Enter column count: ";
    size_t bin_count;

    in >> bin_count;
    data.bin_count = bin_count;

    return data;
    }

string make_info_text()
{
    stringstream buffer;
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD build;
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & 0xff;
    DWORD version_minor = version >> 8;
    //printf("M_version10 = %lu\n",version_major);
    //printf("M_version16 = %08lx\n",version_major);
    //printf("m_version10 = %lu\n",version_minor);
    //printf("m_version16 = %08lx\n",version_minor);
    if ((info & 0x80000000) == 0)
    {
    build = platform;
    }
    else printf("minor_bit = %u",1);
    //printf("Windows v%lu.%lu (build %lu)\n",version_major,version_minor,build);
    char system_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD Size = sizeof(system_name);
    GetComputerNameA(system_name, &Size);
    //printf("System name: %s\n", system_name);
    buffer << "Windows v" << version_major << "." << version_minor << " (build " << build << ") " << "Computer name: " << system_name;
    return buffer.str();
}

size_t write_data(void* items, size_t item_size, size_t item_count, void* ctx)
{
    size_t data_size;
    data_size=item_size * item_count;
    const char* new_items = reinterpret_cast<const char*>(items);
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(new_items, data_size);
    return data_size;
}

Input download(const string& address) {
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
       CURL* curl = curl_easy_init();
       if(curl) {
        char *ip;
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
            if((res == CURLE_OK) && !curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP, &ip) && ip) cerr << "IP:" << ip << endl;
            else {
                cout << curl_easy_strerror(res) << endl;
                exit(1);
            }
        curl_easy_cleanup(curl);
        }
    return read_input(buffer, false);
}

int main(int argc, char* argv[]) {
    string info = make_info_text();
    Input data;
    if(argc > 1)
    {
        data = download(argv[1]);
    }
    else {
            data = read_input(cin, true);
    }
    size_t font_size;
    bool wrong_size;
    while (!wrong_size)
    {
        cerr << "Enter font size: ";
        cin >> font_size;
        wrong_size = check_size(font_size);
    }
    const auto bins = make_histogram(data);
    show_histogram_svg(bins, info, font_size);
    return 0;
}
