#include <stdio.h>
#include "prototypes.h"

void monitorAndDisplayBeds(int bedOccupancy[][MAX_BEDS])
{
    int i, j;
    int occupied;
    int available;
    double percentage;

    printf("\n");
    printf(" _________________________________________________________________________\n");
    printf("|                           BED AVAILABILITY                              |\n");
    printf("|_________________________________________________________________________|\n");

    printf("|%-20s |%-10s |%-10s |%-10s |%-12s   |\n",
           "WARD", "CAPACITY", "OCCUPIED", "AVAILABLE", "OCCUPANCY");

    printf("|_____________________|___________|___________|___________|_______________|\n");

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

        available = wardCapacities[i] - occupied;

        percentage =
            ((double)occupied / wardCapacities[i]) * 100.0;

        printf("|%-20s |%-10d |%-10d |%-10d |%6.2f%%        |\n",
               wardNames[i],
               wardCapacities[i],
               occupied,
               available,
               percentage);
    }
    printf("|_____________________|___________|___________|___________|_______________|\n");

    printf("\nBED STATUS\n");
    printf("0 = Available   1 = Occupied\n\n");

    for (i = 0; i < WARDS; i++)
    {
        printf("%-20s : ",wardNames[i]);

        for (j = 0; j < wardCapacities[i]; j++)
        {
            printf("%d ", bedOccupancy[i][j]);
        }

        printf("\n");
    }

}

void saveBeds(int bedOccupancy[][MAX_BEDS])
{
    FILE *file = fopen("beds_status.txt", "w");

    if(file == NULL)
    {
        printf("\nError: Could not save bed data!\n");
        return;
    }

    for(int i = 0; i < WARDS; i++)
    {
        for(int j = 0; j < wardCapacities[i]; j++)
        {
            fprintf(file, "%d ", bedOccupancy[i][j]);
        }

        fprintf(file, "\n");
    }

    fclose(file);
    printf("\nBed Occupancy Data Saved Successfully!\n");
}
