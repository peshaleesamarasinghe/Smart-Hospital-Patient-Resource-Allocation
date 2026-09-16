#include <stdio.h>

#define SPECIALTIES 4

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

void hospitalHeader();
void hospitalMenue();
void printSpecialties();

int main()
{
    hospitalHeader();
    hospitalMenue();
    printSpecialties();


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

void printSpecialties(void)
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
