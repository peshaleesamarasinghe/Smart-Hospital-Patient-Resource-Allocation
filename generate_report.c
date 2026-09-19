#include <stdio.h>
#include "prototypes.h"

void generateReports(char patientNames[][50],
                     int urgency[],
                     double finalBill[],
                     double discount[],
                     int patientCount,
                     int bedOccupancy[][MAX_BEDS])
{
    int i, j;
    int normal = 0;
    int urgent = 0;
    int critical = 0;

    int occupied;
    int highestIndex = -1;

    double totalRevenue = 0.0;
    double totalDiscount = 0.0;
    double percentage;

    printf("\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("|                 HOSPITAL PERFORMANCE REPORT                             |\n");
    printf("|_________________________________________________________________________|\n");

    printf("|Total Registered Patients : %d                                            |\n", patientCount);

    for(i = 0; i < patientCount; i++)
    {
        if(urgency[i] == 1)
            normal++;
        else if(urgency[i] == 2)
            urgent++;
        else if(urgency[i] == 3)
            critical++;

        totalRevenue += finalBill[i];
        totalDiscount += discount[i];

        if(highestIndex == -1 ||
           finalBill[i] > finalBill[highestIndex])
        {
            highestIndex = i;
        }
    }
    printf("|                                                                         |\n");
    printf("| TRIAGE SUMMARY                                                          |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("| Normal Patients   : %d                                                   |\n", normal);
    printf("| Urgent Patients   : %d                                                   |\n", urgent);
    printf("| Critical Patients : %d                                                   |\n", critical);
    printf("|                                                                         |\n");
    printf("| FINANCIAL SUMMARY                                                       |\n");
    printf("|-------------------------------------------------------------------------|\n");
    printf("| Total Revenue     : LKR %.2f                                            |\n", totalRevenue);
    printf("| Total Discounts   : LKR %.2f                                            |\n", totalDiscount);

    if(highestIndex != -1)
    {
        printf("| Highest Paying     : %s                                                |\n",
               patientNames[highestIndex]);

        printf("| Highest Bill       : LKR %.2f                                          |\n",
               finalBill[highestIndex]);
    }
    else
    {
        printf("| Highest Paying    : No patients registered                              |\n");
    }

    printf("|                                                                         |\n");
    printf("| WARD OCCUPANCY                                                          |\n");
    printf("|-------------------------------------------------------------------------|\n");

    printf("| %-22s |%-10s   |%-34s|\n",
           "WARD ", " OCCUPIED ", " PERCENT ");

    for(i = 0; i < WARDS; i++)
    {
        occupied = 0;

        for(j = 0; j < wardCapacities[i]; j++)
        {
            if(bedOccupancy[i][j] == 1)
            {
                occupied++;
            }
        }

        percentage =
            ((double)occupied / wardCapacities[i]) * 100.0;

        printf("| %-22s |%10d   |%7.2f%%                          |\n",
               wardNames[i],
               occupied,
               percentage);
    }

    printf("|_________________________________________________________________________|\n");

}
