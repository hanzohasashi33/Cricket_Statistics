#include<stdio.h>
#include<string.h>
//#include "structure_bowler.h"

struct bowler_disp{               //declare a structure to contain bowler stats
    char name[20];
    char country[20];
    int odiwickets;
    char besthaul[10];
    float economy;
    float best_economy;
    int hattrick;
};

void display_bowler()
{
    int option,i = 0, j;
    float llimit,ulimit;
    char option2;
    char country[20];
    struct bowler_disp b1[20];
    FILE *fp1 = fopen("bowler.txt","r");     //scans the file and puts corresponding data in the array of structures
    while(!feof(fp1))
    {
        fscanf(fp1,"%s %s %d %s %f %f %d\n",b1[i].name,b1[i].country,&b1[i].odiwickets,b1[i].besthaul,&b1[i].economy,&b1[i].best_economy,&b1[i].hattrick);
        //printf("%s %s %d %s %f %f %d\n",b1[i].name,b1[i].country,b1[i].odiwickets,b1[i].besthaul,b1[i].economy,b1[i].best_economy,b1[i].hattrick);

        i++;
    }

    //the below code does according to the option choosen by the user and does the same job of displaying them wrt the user recommondations
    printf("1. Display everything\n");
    printf("2. Display by country\n");
    printf("3. Dislay by total ODI wickets\n");
    printf("4. Display by economy\n");
    printf("5. Display by best_economy rate\n");
    printf("6. Display by number of hattricks.\n");
    printf("Choose the option you want to undertake : ");
    scanf("%d",&option);
    
    switch(option)
    {
                case 1: printf("Name\t\tCountry\tODI_Wickets\tBest_Haul\tEconomy\t\tBest_Eco\tHattricks\n");
			for(j = 0;j<i;j++)
                        {
                            printf("%s\t%s\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);   
                        }
                        break;
                
                case 2: printf("Enter the country you want the players to be diplayed from:");
                        scanf("%s",country);
			printf("Name\t\tCountry\tODI_Wickets\tBest_Haul\tEconomy\t\tBest_Eco\tHattricks\n");
                        for(j = 0;j<i;j++)
                        {
                            if(strcmp(country,b1[j].country) == 0)
                            {
                                printf("%s\t%s\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                            }
                        }
                        break;
                    
                    case 3: printf("Enter the lowerlimit and upper limit of the odiwickets you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%f",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%f",&ulimit);
			    printf("Name\t\tCountry\tODI_Wickets\tBest_Haul\tEconomy\t\tBest_Eco\tHattricks\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((b1[j].odiwickets<=ulimit) && (b1[j].odiwickets>=llimit))
                                {
                                    printf("%s\t%s\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                                }
                            }
                            break;
                    
		    case 4: printf("Enter the lowerlimit and upper limit of the economy you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%f",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%f",&ulimit);
			    printf("Name\t\tCountry\tODI_Wickets\tBest_Haul\tEconomy\t\tBest_Eco\tHattricks\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((b1[j].economy<=ulimit) && (b1[j].economy>=llimit))
                                {
                                    printf("%s\t%s\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                                }
                            }
                            break;
                    
                    case 5: printf("Enter the lowerlimit and upper limit of the best_economy you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%f",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%f",&ulimit);
			    printf("Name\t\tCountry\tODI_Wickets\tBest_Haul\tEconomy\t\tBest_Eco\tHattricks\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((b1[j].best_economy<=ulimit) && (b1[j].best_economy>=llimit))
                                {
                                    printf("%s\t%s\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                                }
                            }
                            break;
                            
                    case 6: printf("Enter the lowerlimit and upper limit of the hattricks you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%f",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%f",&ulimit);
			    printf("Name\t\tCountry\tODI_Wickets\tBest_Haul\tEconomy\t\tBest_Eco\tHattricks\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((b1[j].hattrick<=ulimit) && (b1[j].hattrick>=llimit))
                                {
                                    printf("%s\t%s\t%d\t\t%s\t\t%.2f\t\t%.2f\t\t%d\n",b1[j].name,b1[j].country,b1[j].odiwickets,b1[j].besthaul,b1[j].economy,b1[j].best_economy,b1[j].hattrick);
                                }
                            }
                            break;
		    default:
			    printf("Invalid Input");
    }
	fclose(fp1);
}
