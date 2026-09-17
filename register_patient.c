#include <stdio.h>
#include "prototypes.h"

#define MAX_PATIENTS 100
#define SPECIALTIES 4
#define WARDS 4

void registerPatient(char names[][50],
                     int age[],
                     int urg[],
                     int spec[],
                     int adm[],
                     int wId[],
                     int stay[],
                     double wait[],
                     int *pCount,
                     int qCount[],
                     const char specialtyNames[SPECIALTIES][30],
                     const double specialtyFees[SPECIALTIES],
                     const int consultationTimes[SPECIALTIES],
                     const char wardNames[WARDS][30],
                     const double wardRates[WARDS])

{
    int idx;
    int i;
    int sIndex;

    if(*pCount >= MAX_PATIENTS)
    {
        printf("\nPatient database is full!\n");
        return;
    }

    idx = *pCount;

    printf("\n");
    printf("============================================================\n");
    printf("                  PATIENT REGISTRATION\n");
    printf("============================================================\n");

    printf("Generated Patient ID : PAT-%04d\n", 1001 + idx);

    printf("\nPatient Name : ");
    scanf(" %[^\n]", names[idx]);


    do
    {
        printf("Age          : ");
        scanf("%d", &age[idx]);

        if(age[idx] < 0 || age[idx] > 120)
        {
            printf("Invalid age. Please try again.\n");
        }

    } while(age[idx] < 0 || age[idx] > 120);


    printf("\n");
    printf("+---------------- TRIAGE LEVEL ----------------+\n");
    printf("| 1. Normal                                    |\n");
    printf("| 2. Urgent                                    |\n");
    printf("| 3. Critical                                  |\n");
    printf("+----------------------------------------------+\n");

    do
    {
        printf("Select Triage Level : ");
        scanf("%d", &urg[idx]);

    } while(urg[idx] < 1 || urg[idx] > 3);


    printf("\nAVAILABLE SPECIALTIES\n");
    printf("------------------------------------------------------------\n");

    for(i = 0; i < SPECIALTIES; i++)
    {
        printf("[%d] %-25s LKR %.2f\n",
               i + 1,
               specialtyNames[i],
               specialtyFees[i]);
    }


    do
    {
        printf("\nSelect Specialty ID : ");
        scanf("%d", &spec[idx]);

    } while(spec[idx] < 1 || spec[idx] > SPECIALTIES);

    sIndex = spec[idx] - 1;

    wait[idx] = qCount[sIndex] * consultationTimes[sIndex];

    qCount[sIndex]++;

    printf("\nIs patient admitted to a ward?\n");
    printf("[1] Yes\n");
    printf("[0] No - Outpatient\n");

    do
    {
      printf("Selection : ");
      scanf("%d", &adm[idx]);

    } while(adm[idx] != 0 && adm[idx] != 1);

    wId[idx] = 0;
    stay[idx] = 0;

    if(adm[idx] == 1)
{
    printf("\nAVAILABLE WARDS\n");
    printf("------------------------------------------------------------\n");

    for(i = 0; i < WARDS; i++)
    {
        printf("[%d] %-22s LKR %.2f/day\n",
               i + 1,
               wardNames[i],
               wardRates[i]);
    }

    do
    {
        printf("\nSelect Ward ID : ");
        scanf("%d", &wId[idx]);

    } while(wId[idx] < 1 || wId[idx] > WARDS);


    do
    {
        printf("Days Admitted : ");
        scanf("%d", &stay[idx]);

    } while(stay[idx] < 1);
}


    (*pCount)++;


    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|              REGISTRATION SUCCESSFUL                     |\n");
    printf("+----------------------------------------------------------+\n");

    printf(" Patient ID : PAT-%04d\n", 1001 + idx);
    printf(" Patient    : %s\n", names[idx]);
    printf(" Age        : %d\n", age[idx]);
    printf(" Specialty  : %s\n", specialtyNames[spec[idx] - 1]);
    printf(" Waiting    : %.0f minutes\n", wait[idx]);

    printf("+----------------------------------------------------------+\n");

        if(adm[idx] == 1)
    {
      printf(" Ward       : %s\n",wardNames[wId[idx] - 1]);

      printf(" Stay       : %d Days\n",stay[idx]);
    }
    else
    {
      printf(" Admission  : Outpatient / OPD\n");
    }

printf("+----------------------------------------------------------+\n");
}
