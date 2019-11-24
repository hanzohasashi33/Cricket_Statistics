#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct batsmen_add{                    //declaring a structure to contain statistics of batsmen.
	char name[30];
	char country[15];
	int total;
	int best;
	float sr;
	int fifties;
	int hundereds;
};

void add_batsmen(void){
	struct batsmen_add b[30] ;          //declaring a new structure of type batsmen to add new record
        FILE *fp;
        fp = fopen("data_batsmen.txt", "r+");
        int i = 0;
        while (!feof(fp))                   //scans the file and puts corresponding data into respective array of structures
        {
                fscanf(fp,"%s %s %d %d %f %d %d\n", b[i].name, b[i].country, &b[i].total, &b[i].best, &b[i].sr, &b[i].fifties, &b[i].hundereds);
                //printf("%s %s %d %d %.4f %d %d\n", b[i].name, b[i].country, b[i].total, b[i].best, b[i].sr, b[i].fifties, b[i].hundereds);
                i++;
        }

	//taking inputs from user
	printf("Name: ") ;                  //takes corresponding data stats and stores them in structure input
	scanf("%s" , b[i].name) ;
	printf("Country: ");
	scanf("%s", b[i].country);
	printf("Total: ");
	scanf("%d", &b[i].total);
	printf("Best: ");
	scanf("%d", &b[i].best ) ;
	printf("No of 50s: ");
	scanf("%d", &b[i].fifties) ;
	printf("No of 100s: ");
	scanf("%d", &b[i].hundereds) ;
	printf("Strike rate: ");
	scanf("%f", &b[i].sr);
	
	i++;
	
	fseek(fp, 0, SEEK_SET);
	for (int j = 0; j<i; j++){
        	fprintf(fp, "%s %s %d %d %.4f %d %d", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
                if(j < i-1)
                	fprintf(fp, "\n");
        }

	fclose(fp) ;
}
