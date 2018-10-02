#include <stdio.h>  // printf
#include "eastersunday.h"

int main(){
    int y, m, d;

    printf("Example 1\n");
    eastersunday(2018, &m, &d);
    printf("2018-%02d-%02d", m, d);

    printf("\nExample 2\n");
	for(y=1583; y <= 4099; y++) {
        eastersunday(y, &m, &d);
		printf("%04d-%02d-%02d\n", y, m, d);
	}

    return 0;
}
