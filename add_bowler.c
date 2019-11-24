#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data                                   //declaring a structure data with statistics of bowlers
{
	char name[30]; 
	char country[20];
	int odiwickets;
	char besthaul[20] ;
	float economy ;
	float best_economy ;
	int hattrick ;
};

void add_bowler()
{
	struct data b1[30];                       //taking b1[i]s from user for bowler stats
	FILE *fp1 = fopen("bowler.txt","r+");
    	char c;
   	int i = 0;
    	while(!feof(fp1))                     //scans the file and puts corresponding data into respective array of structures
    	{
        	//printf("%c",c);
        	//fseek(fp1,0,ftell(fp1)- 1);
        	fscanf(fp1,"%s %s %d %s %f %f %d\n",b1[i].name,b1[i].country,&b1[i].odiwickets,b1[i].besthaul,&b1[i].economy,&b1[i].best_economy,&b1[i].hattrick);
        	//printf("%s %s %d %s %f %f %d\n",b1[i].name,b1[i].country,b1[i].odiwickets,b1[i].besthaul,b1[i].economy,b1[i].best_economy,b1[i].hattrick);
        	//fseek(fp1,0,ftell(fp1));
        	i++;
    	}	
	printf("Name: ") ;
	scanf("%s" , b1[i].name) ; 
	printf("Country: "); 
	scanf("%s", b1[i].country);
	printf("ODI_wickets: ");
	scanf("%d", &b1[i].odiwickets);
	printf("Besthaul: ");
	scanf("%s", b1[i].besthaul) ;
	printf("Economy: ");
	scanf("%f", &b1[i].economy) ;
	printf("Best_economy: ");
	scanf("%f", &b1[i].best_economy) ;
	printf("Hattrick: ");
	scanf("%d", &b1[i].hattrick);

	i++;
	
	fseek(fp1, 0, SEEK_SET);
	    for (int k = 0; k<i; k++)
            {
                fprintf(fp1,"%s %s %d %s %.4f %.4f %d",b1[k].name,b1[k].country,b1[k].odiwickets,b1[k].besthaul,b1[k].economy,b1[k].best_economy,b1[k].hattrick);
		if(k < i - 1)
		{
			fprintf(fp1,"\n");
	    	}
	    }
	fclose(fp1);
}
