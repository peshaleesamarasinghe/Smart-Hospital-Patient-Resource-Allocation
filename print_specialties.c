#include <stdio.h>
#include "prototypes.h"


void printSpecialties(const char specialtyNames[SPECIALTIES][30],
                      const double specialtyFees[SPECIALTIES],
                      const int consultationTimes[SPECIALTIES],
                      const int dailyPatientCaps[SPECIALTIES])
{
    int i;

    printf("\n");
    printf("==========================================================================\n");
    printf("|                        MEDICAL SPECIALTIES                             |\n");
    printf("==========================================================================\n");

    printf("|%-12s |%-25s |%-12s |%-10s |%-5s|\n",
           "Specialty ID", "Specialty Name", "FEE (LKR)", "TIME (min)", "CAP");

    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < SPECIALTIES; i++)
    {
        printf("|%-12d |%-25s |%-12.2f |%-10d |%-5d|\n",
               i + 1,
               specialtyNames[i],
               specialtyFees[i],
               consultationTimes[i],
               dailyPatientCaps[i]);
    }

    printf("==========================================================================\n");
}
