#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add_batsmen.h"
#include "display_batsmen.h"
#include "delete_batsmen.h"
#include "edit_batsmen.h"

/*
struct batsmen{
	char name[20];
	char country[15];
	int total;
	int best;
	float sr;
	int fifties;
	int hundereds;
};*/

void batsmen(void){
	while (1){	// to keep it running till the user wants to leave
		printf("\n--------------------------------------------------------------");
		printf("\nChoose what you would like to do with the statistics ->\n");
		printf("1.Display\n2.Add\n3.Edit\n4.Delete\n0.Return\n");
		printf("--------------------------------------------------------------\n");
		int opt;
		printf("Choose you option: ");
		scanf("%d", &opt);	// taking user input option and call the respective functions
		switch (opt){
			case 1:
				display_batsmen();
				break;
			case 2:
				add_batsmen();
				break;
			case 3:
				edit_batsmen();
				break;
			case 4:
				delete_batsmen();
				break;
			case 0:
				return;
			default:
				printf("Invalid input\n");
		}
	}
	
}	

