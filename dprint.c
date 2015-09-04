#include "util.h"
#include <stdio.h>

void _dprintf(const char *tag, const char *msg) {
	fprintf(stderr, "%s %s\n", tag, msg);
}