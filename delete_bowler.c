#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "structure_bowler.h"

struct bowler_del{                    //declare structure to contain bowler stats
	char name[20];
	char country[20];
	int odiwickets;
	char besthaul[10];
	float economy;
	float best_economy;
	int hattrick;
};


void delete_bowler()
{
	struct bowler_del b1[20];
	FILE *fp;
	fp = fopen("bowler.txt", "r");
	int i = 0;
	while (!feof(fp))                  //scans all the contents of the file and corresponds them to respective array of structures
	{
		fscanf(fp,"%s %s %d %s %f %f %d\n", b1[i].name, b1[i].country, &b1[i].odiwickets, b1[i].besthaul, &b1[i].economy, &b1[i].best_economy, &b1[i].hattrick);
		i++;
	}
	char naam[20];
	printf("Enter name you want to delete: ");
	scanf("%s", naam);                  //gets the name of bowler to delete
	FILE *fp1;
	fp1 = fopen("bowler.txt", "w");
	for ( int j=0; j<i; j++ )           //erases the entire file and then rewrites with all records except the one we wish to delete.
	{
		if (strcmp(b1[j].name, naam) == 0)
		{
			continue;
		}
		else
		{
			fprintf(fp1,"%s %s %d %s %.4f %.4f %d", b1[j].name, b1[j].country, b1[j].odiwickets, b1[j].besthaul, b1[j].economy, b1[j].best_economy, b1[j].hattrick);
			
		}
		if(j < i - 1)
			{
				fprintf(fp1,"\n");
			}
	}
	fclose(fp);
	fclose(fp1);
}

