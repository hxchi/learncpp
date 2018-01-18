#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // for strlen()
#include <ctype.h> // for isdigit()


// function hit, number and position both right.
bool hit(char c1[], char c2[]);

// function blow, check the right number
void blow(char c1[], char c2[]);

int main()
{
	// get random number from 0 to 9 
	srand(time(NULL));
	int a[4];
	int b;
	int j = 0;

	a[0] = rand()%10;
	while (1) {
		b = rand()%10;
		if ( b == a[0]) {
			continue;
		}
		else {
			a[1] = b;
			break;
		}
	}
	while (1) {
		b = rand()%10;
		if (b == a[0] || b == a[1]) {
			continue;
		}
		else {
			a[2] = b;
			break;
		}
	}
	while (1) {
		b = rand()%10;
		if (b == a[0] || b == a[1] || b == a[2]) {
			continue;
		}
		else {
			a[3] = b;
			break;
		}
	}

	// change the random number into char

	char d[42]; // right answer
	for (int i = 0; i < 4; i++) {
		sprintf(&d[i], "%d", a[i]); // the first par of sprintf must be a pointer
		// printf("%c\n", d[i]); //
	}

	// test random number 
	// for (int i = 0; i < 4; i++) {
	// 	printf("%d ", a[i]);
	// }
	// printf("\n");

	// player give the answer

	// int givenum;
	// printf("please enter four different numbers from 0-9.\n");
	// scanf("%d", &givenum);
	// printf("the number you give is %d.\n", givenum);

	char c[42]; // players answer
	printf("please enter four different numbers from 0-9.\n");
	scanf("%s", c);

	bool bl1 = 0;
	bool bl2 = 0;
	int l = 1;
	while (1) {
		while (strlen(c) != 4) { // test if there are 4 numbers?
			printf("we need four number...\n");
			scanf("%s", c); // good, every time i use this, char c[42] is auto get cleaned.
		}

		// if they all numbers?
		bl1 = 0;
		bl2 = 0;
		for (int i = 0; i < 4; i++) {
			while (isdigit(c[i]) == 0) {
				printf("we need numbers...\n");
				bl1 = 1;
				break;
			}
			if (bl1) {
				break;
			}
		}
		if (bl1) {
			scanf("%s", c);
			continue;
		}

		// if the same number?
		for (int i = 0; i < 3; i++) {
			for (int j = i+1; j < 4; j++) {
				if (c[i] == c[j]) {
					printf("numbers needs to be different...\n");
					bl2 = 1;
					break;
				}
			}
			if (bl2) {
				scanf("%s", c);
				break;
			}
		}
		if(!bl2) {
			if (!hit(c, d)) {
				blow(c, d);
				printf("please enter four different numbers from 0-9 again...\n");
				l++;
				scanf("%s", c);
			}
			else {
				printf("you are right...\n");
				printf("you guess %d times.\n", l);
				break;
			}
		}
	}
	return 0;
}



bool hit(char c1[], char c2[]) 
{
	int j = 0;
	for (int i = 0; i < 4; i++) {
		if (c1[i] == c2[i]) {
			j++;
		}
	}
	printf("there are %d numbers having right number and position.\n", j);
	if (j == 4) {
		return 1;
	}
}


void blow(char c1[], char c2[])
{
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (c1[i] == c2[j]) {
				k++;
				break;
			}
		}
	}
	printf("there are %d numbers having right number.\n", k);
}