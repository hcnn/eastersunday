//#include <stdio.h>  // printf
#include <assert.h>
#include "eastersunday.h"

int main()
{
    int y, m, d;

    printf("Test start\n");
    y = 2019;
    eastersunday(y, &m, &d);

    assert(m == 4);
    assert(d == 21);
    printf("Test done\n");

	return 0;
}
