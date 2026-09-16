#include <stdio.h>

#define MAX_PATIENTS 100
#define SPECIALTIES 4
#define WARDS 4

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

void hospitalHeader();
void hospitalMenue();
void printSpecialties();
void printWards();

int main()
{
    char patientNames[MAX_PATIENTS][50];

    int ages[MAX_PATIENTS];
    int urgency[MAX_PATIENTS];
    int specialty[MAX_PATIENTS];

    int admitted[MAX_PATIENTS];
    int ward[MAX_PATIENTS];
    int bedNumber[MAX_PATIENTS];
    int days[MAX_PATIENTS];

    int patientCount = 0;


    hospitalHeader();
    hospitalMenue();
    printSpecialties();
    printWards();


    return 0;
}

void hospitalHeader()
{
    printf("*****************************************************************************************************************  \n");
    printf("**    ##### ##     ##     #     ##### #######   #    #  ####  ##### ###### ####### #######     #     #         **\n");
    printf("**    #     # #   # #    # #    #   #    #      #    # #    # #     #    #    #       #       # #    #         **\n");
    printf("**    ##### #  # #  #   #####   #####    #      ###### #    # ##### ######    #       #      #####   #         **\n");
    printf("**        # #   #   #  #     #  #  #     #      #    # #    #     # #         #       #     #     #  #         **\n");
    printf("**    ##### #       # #       # #   #    #      #    #  ####  ##### #      #######    #    #       # ######    **\n");
    printf("*****************************************************************************************************************  \n");
    printf("                               ________________________________ \n");
    printf("                              /               |||              \\ \n");
    printf("                             /              |||||||             \\ \n");
    printf("                            /         MODERN  |||  HOSPITAL      \\ \n");
    printf("                           /______________________________________\\\n");
    printf("                                   |                       |\n");
    printf("                                   |                       |\n");
    printf("                                   |        WELCOME!       |\n");
    printf("                                   |                       |\n");
    printf("                                   |_______________________|\n");
    printf("  \n");


}

void hospitalMenue()
{
    printf("=========================================\n");
    printf("   SMART HOSPITAL MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. Register Patient\n");
    printf("2. Search Patient\n");
    printf("3. Exit\n");
}

void printSpecialties()
{
    int i;

    printf("\n");
    printf("==========================================================================\n");
    printf("                         MEDICAL SPECIALTIES\n");
    printf("==========================================================================\n");

    printf("%-4s %-25s %-12s %-10s %-10s\n",
           "ID", "SPECIALTY", "FEE (LKR)", "TIME (min)", "   CAP");

    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < SPECIALTIES; i++)
    {
        printf("%-4d %-25s %-12.2f %-7d       %-10d\n",
               i + 1,
               specialtyNames[i],
               specialtyFees[i],
               consultationTimes[i],
               dailyPatientCaps[i]);
    }

    printf("==========================================================================\n");
}

void printWards(void)
{
    int i;

    printf("\n");
    printf("==========================================================================\n");
    printf("                           HOSPITAL WARDS\n");
    printf("==========================================================================\n");

    printf("%-4s %-25s %-15s %-10s\n",
           "ID", "WARD", "RATE/DAY", "CAPACITY");

    printf("--------------------------------------------------------------------------\n");

    for(i = 0; i < WARDS; i++)
    {
        printf("%-4d %-25s LKR %-11.2f %-10d\n",
               i + 1,
               wardNames[i],
               wardRates[i],
               wardCapacities[i]);
    }

    printf("==========================================================================\n");
}
