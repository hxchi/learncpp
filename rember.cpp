#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function for paste x ms
int sleep(unsigned long x) 
{
	clock_t c1 = clock(), c2;
	do {
		if ((c2 = clock()) == (clock_t)-1) 
	 		return 0;
	} while (1000.0 * (c2-c1) / CLOCKS_PER_SEC < x);
	return 1;
}


int main()
{
	clock_t	start, end; // for calculate the time it takes
	srand(time(NULL)); // random seed
	int a, b; // right answer, player answer
	int m = 0, n = 0; // total times and right times

	start = clock();
	while (1) {
		a = rand() % 900 + 1000;
		printf("%d", a);
		fflush(stdout);

		sleep(500);
		// printf("\b\b\b\b    \b\b\b\b\n");
		printf("\renter you number: ");
		scanf("%d", &b);
		n++;
		if (b == a) {
			m++;
		}
		if (n == 3) {
			printf("%d tims you are right.\n", m);
			break;
		}
	}
	end = clock();

	printf("time: %.1fs.\n", (double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}


