#include <stdio.h>
#include <stdlib.h>
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

    double baseFee[MAX_PATIENTS];
    double surcharge[MAX_PATIENTS];
    double wardCost[MAX_PATIENTS];
    double grossBill[MAX_PATIENTS];
    double discount[MAX_PATIENTS];
    double finalBill[MAX_PATIENTS];

    initializeBeds(bedOccupancy);


    system("cls");
    hospitalHeader();

            printf("\nWelcome to the SMART HOSPITAL!\nPress Enter to view MAIN MENUE...\n");
            getchar();

do
 {
     system("cls");


     hospitalMenue();
     printf("\nSelect an option: ");

       if(scanf("%d", &choice) !=1)
       {
           printf("\n Invalid Input !\n Please Enter a number.\n");

           clearInputBuffer();
           choice = -1;
           continue;
       }

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
                    baseFee,
                    surcharge,
                    wardCost,
                    grossBill,
                    discount,
                    finalBill,
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

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            break;

        case 2:
            findPatientBill(patientNames,
                     ages,
                     urgency,
                     specialty,
                     admitted,
                     ward,
                     bedNumber,
                     days,
                     waitTime,
                     baseFee,
                     surcharge,
                     wardCost,
                     grossBill,
                     discount,
                     finalBill,
                     patientCount);

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        case 3:
            displayTriageQueue(patientNames,
                       urgency,
                       patientCount);

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        case 4:
            monitorAndDisplayBeds(bedOccupancy);

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        case 5:
            printSpecialties(specialtyNames,
                            specialtyFees,
                            consultationTimes,
                            dailyPatientCaps);
            printWards(wardNames,
                       wardRates,
                       wardCapacities);

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        case 6:
            generateReports(patientNames,
                    urgency,
                    finalBill,
                    discount,
                    patientCount,
                    bedOccupancy);

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        case 7:
            saveBeds(bedOccupancy);

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        case 0:
            printf("\nExiting Smart Hospital System...\n");

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
            break;

        default:
            printf("\nInvalid option!\n");

            printf("\nPress ENTER to check MAIN MENUE...\n");
            getchar();
            getchar();
    }

 } while(choice != 0);





    return 0;
}

void clearInputBuffer(void)
{
    int ch;

    while((ch = getchar()) != '\n' && ch != EOF)
    {
        //Clear remaining input
    }
}
