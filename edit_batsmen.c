#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct batsmen_edit{                     //creates a structure to hold batsmen statistics
	char name[30];
	char country[15];
	int total;
	int best;
	float sr;
	int fifties;
	int hundereds;
};

void edit_batsmen(void){

	struct batsmen_edit b[30];
	FILE *fp;
	fp = fopen("data_batsmen.txt", "r+");
	int i = 0;
	while (!feof(fp))                   //scans the file and puts corresponding data into respective array of structures
	{               
		fscanf(fp,"%s %s %d %d %f %d %d\n", b[i].name, b[i].country, &b[i].total, &b[i].best, &b[i].sr, &b[i].fifties, &b[i].hundereds);
		//printf("%s %s %d %d %.4f %d %d\n", b[i].name, b[i].country, b[i].total, b[i].best, b[i].sr, b[i].fifties, b[i].hundereds);
		i++;
	}

	printf("Enter whose statistics you want to edit: ");     //gets the name of batsmen whose stats the user wants to edit
	char naam[20];
	scanf("%s", naam);
	//gets the corresponding data and edits the data according to user specifications
	for ( int j=0; j<i; j++ ){
		if (strcmp(b[j].name, naam) == 0){
			printf("1. Total\n2. Best\n3. Strike Rate\n4. Fifties\n5. Hundereds\n");
			printf("Enter the option for which data you want to update: ");
			int opt;
			scanf("%d", &opt);
			switch (opt){	// editing the data which the user wants to
				case 1:
					printf("Enter new total: ");
					scanf("%d", &b[j].total);
					printf("%s %s %d %d %.4f %d %d\n", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
					break;
				case 2:
                                        printf("Enter new best: ");
                                        scanf("%d", &b[j].best);
                                        printf("%s %s %d %d %.4f %d %d\n", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
                                        break;
				case 3:
                                        printf("Enter new strike rate: ");
                                        scanf("%f", &b[j].sr);
                                        printf("%s %s %d %d %.4f %d %d\n", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
                                        break;
				case 4:
                                        printf("Enter new fifties: ");
                                        scanf("%d", &b[j].fifties);
                                        printf("%s %s %d %d %.4f %d %d\n", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
                                        break;
				case 5:
                                        printf("Enter new hundereds: ");
                                        scanf("%d", &b[j].hundereds);
                                        printf("%s %s %d %d %.4f %d %d\n", b[j].name, b[j].country, b[j].total, b[j].best, b[j].sr, b[j].fifties, b[j].hundereds);
                                        break;
				default:
					printf("Option does not exist\n");
			}
			fclose(fp);
			FILE *fp = fopen("data_batsmen.txt", "w");	// overwriting the existing data
			for (int k = 0; k<i; k++){
				fprintf(fp, "%s %s %d %d %.4f %d %d", b[k].name, b[k].country, b[k].total, b[k].best, b[k].sr, b[k].fifties, b[k].hundereds);
				if(k < i-1)
					fprintf(fp, "\n");
			}
			break;
		}
		else if (j==i-1)
			printf("Record does not exist\n");
	}
	fclose(fp);	
}

