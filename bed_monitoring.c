#include <stdio.h>
#include "prototypes.h"

void monitorBeds(int bedOccupancy[][MAX_BEDS])
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
}
