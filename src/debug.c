#include "debug.h"
#include <stdio.h>

void debug_printf(char* s) {
	printf("%s:%d - %s\n", __FILE__, __LINE__, s);
}
