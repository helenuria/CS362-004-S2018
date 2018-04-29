// test the compare function

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

int main() {
	printf("TESTING compare():\n");
	int pass_count = 0;
	int retval;

	struct{
		int firstArg;
		int secondArg;
		int expectval;
		const char* description;
	} testTable[] = {
		{	
			.firstArg = 5, 
			.secondArg = 5, 
			.expectval = 0, 
			.description = "It returns 0 if arguments are the same value\n",
		},
		{	
			.firstArg = 10, 
			.secondArg = 1, 
			.expectval = 1, 
			.description = "It returns 1 if the first argument is greater than the second\n",
		},
		{	
			.firstArg = 1, 
			.secondArg = 10, 
			.expectval = -1, 
			.description = "It returns -1 if the first argument is less than the second\n",
		},
		{	
			.firstArg = 0, 
			.secondArg = -5, 
			.expectval = 1, 
			.description = "It works if the arguments are very small\n",
		},
		{	
			.firstArg = 999, 
			.secondArg = 998, 
			.expectval = 1, 
			.description = "It works if the arguments are very large\n",
		},
	};

	for (int i = 0; i < sizeof(testTable) / sizeof(testTable[0]); i++) {

		printf(testTable[i].description);
		retval = compare((void*)&testTable[i].firstArg, (void*)&testTable[i].secondArg);

		if (retval == testTable[i].expectval) {
			printf("PASS: %d\n", retval);
			pass_count++;
		}
		else {
			printf("FAIL: %d\n", retval);
		}
	}

	if (pass_count == 5) {
		printf("All tests passed!\n\n");
		return 0;
	}
	else {
		printf("Test suite failed\n\n");
		return 1;
	}
}
