#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct batsmen_disp{            //declare a structure to contain batsmen stats
	char name[30];
	char country[15];
	int total;
	int best;
	float sr;
	int fifties;
	int hundereds;
};

void display_batsmen(){
    int option,i = 0,llimit,ulimit,j;
    char option2;
    char country[20];
    struct batsmen_disp entry[30];
    FILE *fp1 = fopen("data_batsmen.txt","r");         //scans the file and puts corresponding data in the array of structures
    while(!feof(fp1))
    {
        fscanf(fp1,"%s %s %d %d %f %d %d\n",entry[i].name,entry[i].country,&entry[i].total,&entry[i].best,&entry[i].sr,&entry[i].fifties,&entry[i].hundereds);
        // printf("%s %s %d %d %f %d %d\n",entry[i].name,entry[i].country,entry[i].total,entry[i].best,entry[i].fifties,entry[i].hundereds,entry[i].sr);

        i++;
    }

    //the below code does according to the option choosen by the user and does the same job of displaying them wrt the user recommondations
    printf("\n1. Display everything\n");
    printf("2. Display by country\n");
    printf("3. Dislay by total ODI runs\n");
    printf("4. Display by best till date\n");
    printf("5. Display by number of 50's\n");
    printf("6. Display by number of 100's\n");
    printf("7. Display by strike rate\n");
    printf("Choose the option you want to undertake : ");
    scanf("%d",&option);
    //printf("Name  Country  ODI_Total  ODI_Best  ODI_Strike_Rate  50s  100s\n");
    switch(option)
    {		// checking the cases and displaying likewise
	    	
                case 1: printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
			for(j = 0;j<i;j++)
                        {
                            printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);   
                        }
                        break;
                
                case 2: printf("Enter the country you want the players to be diplayed from:");
                        scanf("%s",country);
			printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
                        for(j = 0;j<i;j++)
                        {
                            if(strcmp(country,entry[j].country) == 0)
                            {
                                printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);
                            }
                        }
                        break;
                    
                    case 3: printf("Enter the lowerlimit and upper limit of the total runs you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%d",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%d",&ulimit);
			    printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((entry[j].total<=ulimit) && (entry[j].total>=llimit))
                                {
                                    printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);
                                }
                            }
                            break;
                    case 4: printf("Enter the lowerlimit and upper limit of the best you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%d",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%d",&ulimit);
			    printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((entry[j].best<=ulimit) && (entry[j].best>=llimit))
                                {
                                    printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);
                                }
                            }
                            break;
                    case 5: printf("Enter the lowerlimit and upper limit of the stat you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%d",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%d",&ulimit);
			    printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((entry[j].fifties<=ulimit) && (entry[j].fifties>=llimit))
                                {
                                    printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);
                                }
                            }
                            break;
                    
                    case 6: printf("Enter the lowerlimit and upper limit of the stat you want to be displayed\n");
                            printf("Enter the lower limit : ");
                            scanf("%d",&llimit);
                            printf("Enter the upper limit : ");
                            scanf("%d",&ulimit);
			    printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((entry[j].hundereds<=ulimit) && (entry[j].hundereds>=llimit))
                                {
                                    printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);
                                }
                            }
                            break;
                            
                    case 7: printf("Enter the lowerlimit and upper limit of the strike rate you want to be displayed\n");
                            printf("Enter the lower limit : ");
			    float llimit, ulimit;
                            scanf("%f", &llimit);
                            printf("Enter the upper limit : ");
                            scanf("%f", &ulimit);
			    printf("Name\t\tCountry\tTotal\tBest\tStrike_Rate\t50s\t100s\n");
                            for(j = 0;j<=i;j++)
                            {
                                if((entry[j].sr<=ulimit) && (entry[j].sr>=llimit))
                                {
                                    printf("%s\t%s\t%d\t%d\t%.2f\t\t%d\t%d\n",entry[j].name,entry[j].country,entry[j].total,entry[j].best,entry[j].sr,entry[j].fifties,entry[j].hundereds);
                                }
                            }
                            break;
		    default:
			    printf("Invalid Input");
                            
        }
	fclose(fp1);
}
