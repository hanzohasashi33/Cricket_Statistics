#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "structure_bowler.h"


struct bowler_edit{                         //creates a structure to hold batsmen statistics
    char name[30];
    char country[20];
    int odiwickets;
    char besthaul[10];
    float economy;
    float best_economy;
    int hattrick;
};


void edit_bowlers()
{
    struct bowler_edit b1[20];
    FILE *fp1 = fopen("bowler.txt","r+");
    char c;
    int i = 0;
    while(!feof(fp1))                     //scans the file and puts corresponding data into respective array of structures
    {
        fscanf(fp1,"%s %s %d %s %f %f %d\n",b1[i].name,b1[i].country,&b1[i].odiwickets,b1[i].besthaul,&b1[i].economy,&b1[i].best_economy,&b1[i].hattrick);
        //printf("%s %s %d %s %f %f %d\n",b1[i].name,b1[i].country,b1[i].odiwickets,b1[i].besthaul,b1[i].economy,b1[i].best_economy,b1[i].hattrick);
        i++;
    }
    int n = i;

    printf("Enter the name of the player whose stats you want to edit: ");
    char naam[20];                      
    scanf("%s",naam);                     //gets the name of bowler whose stats the user wants to edit
    //gets the corresponding data and edits the data according to user specifications
    for(int j = 0;j < i;j++)
    {
        if(strcmp(b1[j].name,naam) == 0)
        {
            printf("1. ODI wickets\n2. Best haul\n3. Economy\n4. Best economy\n5. Hattrick\n");
            printf("Enter the option of the stat you want to edit : ");
            int option;
            scanf("%d",&option);

            switch(option)
            {
                case 1 : printf("Enter the new number of ODI wickets the player has taken :");
                         scanf("%d",&b1[j].odiwickets);
                         printf("%s %s %d %s %.4f %.4f %d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                         break;

                case 2 : printf("Enter the new best haul of the bowler :");
                         scanf("%s",b1[j].besthaul);
                         printf("%s %s %d %s %.4f %.4f %d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                         break;

                case 3 : printf("Enter the new economy of the bowler : ");
                         scanf("%f",&b1[j].economy);
                         printf("%s %s %d %s %.4f %.4f %d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                         break;

                case 4 : printf("Enter the new best economy of the bowler : ");
                         scanf("%f",&b1[j].best_economy);
                         printf("%s %s %d %s %.4f %.4f %d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                         break;

                case 5 : printf("Enter the new number of hatricks the person took : ");
                         scanf("%d",&b1[j].hattrick);
                         printf("%s %s %d %s %.4f %.4f %d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                         break;
                
                default :printf("Option does not exist");
            }


            fseek(fp1, 0, SEEK_SET);	// overwriting the current data
	    for (int k = 0; k<i; k++)
            {
                fprintf(fp1,"%s %s %d %s %.4f %.4f %d",b1[k].name,b1[k].country,b1[k].odiwickets,b1[k].besthaul,b1[k].economy,b1[k].best_economy,b1[k].hattrick);
		if ( k < i-1 ){
			fprintf(fp1, "\n");
		}
	    }
            break;
        }
        
        else if(j == i - 1)
        {
            printf("Record does not exist\n");
        }
    }
    
    fclose(fp1);

}
