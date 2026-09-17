#include <stdio.h>
#include "prototypes.h"


void initializeBeds(int beds[][MAX_BEDS])
{
    int i;
    int j;

    for(i = 0; i < WARDS; i++)
    {
        for(j = 0; j < MAX_BEDS; j++)
        {
            beds[i][j] = 0;
        }
    }
}
int assignNextBed(int beds[][MAX_BEDS], int wardIndex,const int wardCapacities[WARDS])
{
    int j;

    for(j = 0; j < wardCapacities[wardIndex]; j++)
    {
        if(beds[wardIndex][j] == 0)
        {
            beds[wardIndex][j] = 1;

            return j + 1;
        }
    }

    return 0;
}
