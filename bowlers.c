#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "disp_bowlers.h"
#include "add_bowler.h"
#include "delete_bowler.h"
#include "edit_bowlers.h"
//include "structure_bowler.h"


void bowlers(void)
{
  while(1)
  {
    int new_options;	// for saving the user input option
    printf("\n------------------------------------\n");
    printf("Choose your option: \n");
    printf("1. Display bowlers\n");
    printf("2. Add bowler\n");
    printf("3. Delete bowler\n");
    printf("4. Edit bowler\n");
    printf("0. Return\n");
    printf("------------------------------------\n");
    printf("Choose your option: ");
    scanf("%d",&new_options);	// checking the options to run respective functions
    if(new_options == 1)
    {
        display_bowler();
    }
    else if(new_options == 2)
    {
        add_bowler();
    }
    else if(new_options == 3)
    {
        delete_bowler();
    }
    else if(new_options == 4)
    {
        edit_bowlers();
    }
    else if(new_options > 4)
    {
        printf("Select a valid option... ");
    }
    else if(new_options == 0)
    {
        return;
    }
  }
}
