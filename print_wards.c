#include <stdio.h>
#include "prototypes.h"

void printWards(const char wardNames[WARDS][30],
                const double wardRates[WARDS],
                const int wardCapacities[WARDS])
{
    int i;

    printf("\n");
    printf("==============================================================\n");
    printf("|                          HOSPITAL WARDS                    |\n");
    printf("==============================================================\n");

    printf("|%-4s |%-25s |%-15s |%-10s|\n",
           "ID", "WARD", "RATE/DAY", "CAPACITY");

    printf("--------------------------------------------------------------\n");

    for(i = 0; i < WARDS; i++)
    {
        printf("|%-4d |%-25s |LKR %-11.2f |%-10d|\n",
               i + 1,
               wardNames[i],
               wardRates[i],
               wardCapacities[i]);
    }

    printf("==============================================================\n");
}
