#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAXSTAGE 10
#define MIMLEVEL 3
#define MAXLEVEL 20

// function for paste x ms
int sleep(unsigned long x); 
void getnumber(int level, char a[42]);
void getnumberP(int level, char a[42]);

int main()
{
	clock_t	start, end; 
	srand(time(NULL)); 

	char a[42];
	char b[42];
	int c;
	int m = 0,n = 1;

	start = clock();
	while (1) {
		m++;
		printf("choose a level from 3 to 20: ");
		scanf("%d", &c);
		getnumber(c, a);
		printf("%s", a);
		fflush(stdout);
		sleep(1000);

		printf("now please enter you answer: ");
		scanf("%s", b);
		printf("%s\n", b);
		if (a == b) {
			printf("you are right...\n");
			n++;
		}
		if (m == 3) {
			printf("game over...\n");
			break;
		}
	}
	end = clock();

	printf("you get %d right...\n", n);
	printf("use %.1fs...\n", (double)(end-start)/CLOCKS_PER_SEC);
	
	// test number
	// getnumber(20, a);
	// for (int i = 0; i < strlen(a); i++) {
	// 	printf("%c", a[i]);
	// }
	// printf("\n");
	
	return 0;
}


/*-------------------------------------------------------------------*/
int sleep(unsigned long x) 
{
	clock_t c1 = clock(), c2;
	do {
		if ((c2 = clock()) == (clock_t)-1) 
	 		return 0;
	} while (1000.0 * (c2-c1) / CLOCKS_PER_SEC < x);
	return 1;
}


void getnumber(int level, char a[42])
{
	int c;
	for(int i = 0; i < level; i++) {
		if (i == 0) {
			c = (rand()%9) + 1;
			sprintf(&a[0], "%d", c);
		}
		else {
			c = rand()%10;
			sprintf(&a[i], "%d", c);
		}
	}
}


