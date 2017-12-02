#include <stdio.h>
#include "trig.h"

void
help_message() {

	printf("\nThe input format is a single line of letters and numbers comprising the\n");
	printf("following fields:\n");
	printf("\n <types> <start-value> <final-value> <intermediate-rows>\n");
	printf("\nThese fields must be input in the order shown above, where <types>\n");
	printf("is a set of letters, and the others are single numbers defining\n");
	printf("the range of computation.\n");
	printf("\nThe <types> field consists of zero or more of the letters from the set\n");
	printf("<stcdr>, which indicate respectively,\n");
	printf("\n (1) The desired trig functions: sin, tan, cos.\n");
	printf(" (2) Whether to use degrees or radians for input parameters.\n");
	printf(" (3) Whether to quit the program.\n");
	printf("\nExample input: scr 0 2.3 3\n");
	
}

