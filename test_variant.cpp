
#include "histogram.h"

#include <cassert>

void test()
{
    assert(check_size(3) == false );
    assert(check_size(33) == false );
    assert(check_size(8) == true );
    assert(check_size(32) == true );
    assert(check_size(16) == true );
}
int main()
{
    test();
}
