
#include "histogram.h"

#include <cassert>

void test(size_t font_size)
{
    assert(check_size(3) == false );
    assert(check_size(33) == false );
    assert(check_size(23) == true );
}
int main()
{
    size_t font_size;
    cin >> font_size;
    check_size(font_size);
}
