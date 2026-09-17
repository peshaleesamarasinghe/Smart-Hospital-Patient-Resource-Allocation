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

void registerPatient(char names[][50],
                     int age[],
                     int urg[],
                     int spec[],
                     double wait[],
                     int *pCount,
                     int qCount[]);



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


    double waitTime[MAX_PATIENTS];

    int specialtyQueue[SPECIALTIES] = {0};


    int patientCount = 0;

    int choice;

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
                waitTime,
                &patientCount,
                specialtyQueue);
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
            printSpecialties();
            printWards();
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
    printf("3. \n");
    printf("4. \n");
    printf("5. \n");
    printf("6. \n");
    printf("7. \n");
    printf("8. Exit\n");
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

void registerPatient(char names[][50],
                     int age[],
                     int urg[],
                     int spec[],
                     double wait[],
                     int *pCount,
                     int qCount[])
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
}
