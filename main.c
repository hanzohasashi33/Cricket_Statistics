#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bowlers.h"
#include "batsmen.h"

int main()
{
	int option;
	printf("WELCOME	TO VCH\n");
	p1: printf("---------------------------------------\n");
	printf("1. Choose batsmen statistics\n");
	printf("2. Choose bowler statistics\n");
	printf("0. Exit\n");
	printf("---------------------------------------\n");
	printf("Choose your option : ");
	scanf("%d",&option);
	
	while (1) {
	    switch(option){
		case 1:
			printf("You chose Batsmen");
			batsmen();
			goto p1;
		case 2:
			printf("You chose Bowlers");
			bowlers();
			goto p1;
		case 0:
			printf("Exiting\n");
			return 0;
		default:
			printf("Invalid input\n");
			goto p1;
	    }
	}
}
