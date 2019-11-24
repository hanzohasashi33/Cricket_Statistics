#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct batsmen_del{                //declare structure to contain batsmen stats
	char name[30];
	char country[15];
	int total;
	int best;
	float sr;
	int fifties;
	int hundereds;
};

void delete_batsmen(void)
{
	struct batsmen_del b[20];
	FILE *fp;
	fp = fopen("data_batsmen.txt", "r");
	int i = 0;
	while (!feof(fp))                     //scans all the contents of the file and corresponds them to respective array of structures
	{
		fscanf(fp,"%s %s %d %d %f %d %d\n", b[i].name, b[i].country, &b[i].total, &b[i].best, &b[i].sr, &b[i].fifties, &b[i].hundereds);
		i++;
	}
	char naam[30];                        //gets the name of batsmen to delete
	printf("Enter name you want to delete: ");
	scanf("%s", naam);
	FILE *fp1;
	fp1 = fopen("data_batsmen.txt", "w");  //erases the entire file and then rewrites with all records except the one we wish to delete
	for ( int j=0; j<i; j++ )
	{
		if (strcmp(b[j].name, naam) == 0)
		{

			continue;
		}
		else
		{
			fprintf(fp1,"%s %s %d %d %f %d %d", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
		}
		if (j<i-1){
			fprintf(fp1, "\n");
		}
	}
	fclose(fp);
	fclose(fp1);                              //closes the file pointers so as to save memory and variable space
}
