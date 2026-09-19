#include <stdio.h>
#include "prototypes.h"

void displayTriageQueue(char patientNames[][50],
                       int urgency[],
                       int patientCount)
{
    int order[MAX_PATIENTS];
    int i,j,temp;

    if(patientCount==0)
    {
        printf("\nNo Patients Registered Yet!\n");
        return;
    }

    //store patient index
    for(i = 0; i < patientCount; i++)
    {
        order[i] = i;
    }

    //stable by urgency
    for(i = 0; i < patientCount - 1; i++)
    {
        for(j = 0; j < patientCount - i - 1; j++)
        {
            if(urgency[order[j]] < urgency[order[j+1]])
            {
                temp = order[j];
                order[j] = order[j+1];
                order[j+1] = temp;
            }
        }
    }
    printf("\n");
    printf("============================================================\n");
    printf("                 EMERGENCY PRIORITY QUEUE\n");
    printf("============================================================\n");

    printf("%-6s %-12s %-25s %-12s\n",
           "NO.", "PATIENT ID", "NAME", "TRIAGE");

    printf("------------------------------------------------------------\n");

    for(i = 0; i < patientCount; i++)
    {
        int index = order[i];

        printf("%-6d PAT-%-8.4d %-25s ",
               i + 1,
               1001 + index,
               patientNames[index]);

        if(urgency[index] == 3)
        {
            printf("Critical\n");
        }
        else if(urgency[index] == 2)
        {
            printf("Urgent\n");
        }
        else
        {
            printf("Normal\n");
        }
    }

    printf("============================================================\n");
}
