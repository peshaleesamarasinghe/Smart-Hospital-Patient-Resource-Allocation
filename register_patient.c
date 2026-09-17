#include <stdio.h>
#include "prototypes.h"

void registerPatient(char patientNames[][50],
                     int ages[],
                     int urgancy[],
                     int specialty[],
                     int admitted[],
                     int ward[],
                     int days[],
                     double waitTime[],
                     int *patientCount,
                     int specialtyQueue[],
                     const char specialtyNames[SPECIALTIES][30],
                     const double specialtyFees[SPECIALTIES],
                     const int consultationTimes[SPECIALTIES],
                     const char wardNames[WARDS][30],
                     const double wardRates[WARDS],
                     const int wardCapacities[],
                     int bedNumber[],
                     int bedOccupancy[][MAX_BEDS])

{
    int idx;
    int i;
    int sIndex;

    if(*patientCount >= MAX_PATIENTS)
    {
        printf("\nPatient database is full!\n");
        return;
    }

    idx = *patientCount;

    printf("\n");
    printf("============================================================\n");
    printf("                  PATIENT REGISTRATION\n");
    printf("============================================================\n");

    printf("Generated Patient ID : PAT-%04d\n", 1001 + idx);

    printf("\nPatient Name : ");
    scanf(" %[^\n]", patientNames[idx]);


    do
    {
        printf("Age          : ");
        scanf("%d", &ages[idx]);

        if(ages[idx] < 0 || ages[idx] > 120)
        {
            printf("Invalid age. Please try again.\n");
        }

    } while(ages[idx] < 0 || ages[idx] > 120);


    printf("\n");
    printf("+---------------- TRIAGE LEVEL ----------------+\n");
    printf("| 1. Normal                                    |\n");
    printf("| 2. Urgent                                    |\n");
    printf("| 3. Critical                                  |\n");
    printf("+----------------------------------------------+\n");

    do
    {
        printf("Select Triage Level : ");
        scanf("%d", &urgancy[idx]);

    } while(urgancy[idx] < 1 || urgancy[idx] > 3);


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
        scanf("%d", &specialty[idx]);

    } while(specialty[idx] < 1 || specialty[idx] > SPECIALTIES);

    sIndex = specialty[idx] - 1;

    waitTime[idx] = specialtyQueue[sIndex] * consultationTimes[sIndex];

    specialtyQueue[sIndex]++;

    printf("\nIs patient admitted to a ward?\n");
    printf("[1] Yes\n");
    printf("[0] No - Outpatient\n");

    do
    {
      printf("Selection : ");
      scanf("%d", &admitted[idx]);

    } while(admitted[idx] != 0 && admitted[idx] != 1);

    if(admitted[idx] == 1)
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
        scanf("%d", &ward[idx]);

    } while(ward[idx] < 1 || ward[idx] > WARDS);


    bedNumber[idx] = assignNextBed(bedOccupancy,
                                   ward[idx] - 1,
                                   wardCapacities);


    if(bedNumber[idx] == 0)
    {
        printf("\nSorry! No available beds in %s.\n",
               wardNames[ward[idx] - 1]);

        printf("Patient will remain as an outpatient.\n");

        admitted[idx] = 0;
        ward[idx] = 0;
        days[idx] = 0;
    }
    else
    {
        printf("\nBed %d successfully allocated in %s.\n",
               bedNumber[idx],
               wardNames[ward[idx] - 1]);

        do
        {
            printf("Days Admitted : ");
            scanf("%d", &days[idx]);

        } while(days[idx] < 1);
    }
}
else
{
    ward[idx] = 0;
    bedNumber[idx] = 0;
    days[idx] = 0;
}



    (*patientCount)++;


    printf("\n");
    printf("+----------------------------------------------------------+\n");
    printf("|              REGISTRATION SUCCESSFUL                     |\n");
    printf("+----------------------------------------------------------+\n");

    printf(" Patient ID : PAT-%04d\n", 1001 + idx);
    printf(" Patient    : %s\n", patientNames[idx]);
    printf(" Age        : %d\n", ages[idx]);
    printf(" Specialty  : %s\n", specialtyNames[specialty[idx] - 1]);
    printf(" Waiting    : %.0f minutes\n", waitTime[idx]);

    printf("+----------------------------------------------------------+\n");

        if(admitted[idx] == 1)
    {
      printf(" Ward       : %s\n",wardNames[ward[idx] - 1]);
      printf(" Bed Number : %d\n",bedNumber[idx]);
      printf(" Stay       : %d Days\n",days[idx]);
    }
    else
    {
      printf(" Admission  : Outpatient / OPD\n");
    }

printf("+----------------------------------------------------------+\n");
}
