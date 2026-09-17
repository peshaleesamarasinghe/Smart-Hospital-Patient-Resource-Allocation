#include <stdio.h>
#include "prototypes.h"

#define SPECIALTIES 4


void printSpecialties(const char specialtyNames[SPECIALTIES][30],const double specialtyFees[SPECIALTIES],const int consultationTimes[SPECIALTIES],const int dailyPatientCaps[SPECIALTIES])
{
    int i;

    printf("\n");
    printf("==========================================================================\n");
    printf("|                        MEDICAL SPECIALTIES                              |\n");
    printf("==========================================================================\n");

    printf("|%-4s |%-25s |%-12s |%-10s |%-10s |\n",
           "Specialty ID", "Specialty Name", "FEE (LKR)", "TIME (min)", "   CAP");

    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < SPECIALTIES; i++)
    {
        printf("|%-4d |%-25s |%-12.2f |%-10d |%-10d |\n",
               i + 1,
               specialtyNames[i],
               specialtyFees[i],
               consultationTimes[i],
               dailyPatientCaps[i]);
    }

    printf("==========================================================================\n");
}
