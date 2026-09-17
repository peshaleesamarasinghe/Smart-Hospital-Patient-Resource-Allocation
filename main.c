#include <stdio.h>
#include "prototypes.h"

const char specialtyNames[SPECIALTIES][30] =
{
    "General Practice (OPD)",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};

const double specialtyFees[SPECIALTIES] =
{
    1500.00,
    2500.00,
    4500.00,
    5000.00
};

const int consultationTimes[SPECIALTIES] =
{
    15,
    20,
    30,
    30
};

const int dailyPatientCaps[SPECIALTIES] =
{
    30,
    20,
    12,
    10
};

const char wardNames[WARDS][30] =
{
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU"
};

const double wardRates[WARDS] =
{
    3000.00,
    6000.00,
    12000.00,
    25000.00
};

const int wardCapacities[WARDS] =
{
    20,
    10,
    10,
    5
};

int main()
{
    char patientNames[MAX_PATIENTS][50];

    int ages[MAX_PATIENTS];
    int urgency[MAX_PATIENTS];
    int specialty[MAX_PATIENTS];

    int admitted[MAX_PATIENTS];
    int ward[MAX_PATIENTS];
    int bedNumber[MAX_PATIENTS];
    int bedOccupancy[WARDS][MAX_BEDS];
    int days[MAX_PATIENTS];


    double waitTime[MAX_PATIENTS];

    int specialtyQueue[SPECIALTIES] = {0};


    int patientCount = 0;

    int choice;

    initializeBeds(bedOccupancy);

    hospitalHeader();

do
 {
       hospitalMenue();
       printf("\nSelect an option: ");
       scanf("%d", &choice);

       switch(choice)
    {
        case 1:
            registerPatient(patientNames,
                    ages,
                    urgency,
                    specialty,
                    admitted,
                    ward,
                    days,
                    waitTime,
                    &patientCount,
                    specialtyQueue,
                    specialtyNames,
                    specialtyFees,
                    consultationTimes,
                    wardNames,
                    wardRates,
                    wardCapacities,
                    bedNumber,
                    bedOccupancy);
            break;

        case 2:
            //patient search
            break;

        case 3:
            //Priority queue
            break;

        case 4:
            //Bed monitoring
            break;

        case 5:
            printSpecialties(specialtyNames,
                            specialtyFees,
                            consultationTimes,
                            dailyPatientCaps);
            printWards(wardNames,
                       wardRates,
                       wardCapacities);
            break;

        case 6:
            //Reports
            break;

        case 7:
            //Save feature
            break;

        case 0:
            printf("\nExiting Smart Hospital System...\n");
            break;

        default:
            printf("\nInvalid option!\n");
    }

 } while(choice != 0);





    return 0;
}
