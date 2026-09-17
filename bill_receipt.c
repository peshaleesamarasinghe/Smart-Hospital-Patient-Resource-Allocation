#include <stdio.h>
#include "prototypes.h"

void printBillReceipt(int idx,
                      char patientNames[][50],
                      int ages[],
                      int urgancy[],
                      int specialty[],
                      int admitted[],
                      int ward[],
                      int bedNumber[],
                      int days[],
                      double waitTime[],
                      double baseFee[],
                      double surcharge[],
                      double wardCost[],
                      double grossBill[],
                      double discount[],
                      double finalBill[],
                      const char specialtyNames[][30],
                      const char wardNames[][30])
{
    printf("\n");
    printf("============================================================\n");
    printf("                    PATIENT BILL RECEIPT\n");
    printf("============================================================\n");

    printf("Patient ID       : PAT-%04d\n", 1001 + idx);
    printf("Patient Name     : %s\n", patientNames[idx]);
    printf("Age              : %d\n", ages[idx]);

    if(urgancy[idx] == 1)
        printf("Triage Level     : Normal\n");
    else if(urgancy[idx] == 2)
        printf("Triage Level     : Urgent\n");
    else
        printf("Triage Level     : Critical\n");

    printf("Specialty        : %s\n",
           specialtyNames[specialty[idx] - 1]);

    if(admitted[idx] == 1)
    {
        printf("Ward             : %s\n",
               wardNames[ward[idx] - 1]);

        printf("Bed Number       : %d\n", bedNumber[idx]);
        printf("Days Admitted    : %d\n", days[idx]);
    }
    else
    {
        printf("Admission Status : Outpatient / OPD\n");
    }

    printf("Waiting Time     : %.0f minutes\n", waitTime[idx]);

    printf("------------------------------------------------------------\n");
    printf("                    BILL BREAKDOWN\n");
    printf("------------------------------------------------------------\n");

    printf("Consultation Fee : LKR %10.2f\n", baseFee[idx]);
    printf("Triage Surcharge : LKR %10.2f\n", surcharge[idx]);
    printf("Ward Cost        : LKR %10.2f\n", wardCost[idx]);

    printf("------------------------------------------------------------\n");

    printf("Gross Bill       : LKR %10.2f\n", grossBill[idx]);
    printf("Age Subsidy      : LKR %10.2f\n", discount[idx]);

    printf("============================================================\n");
    printf("FINAL PAYABLE    : LKR %10.2f\n", finalBill[idx]);
    printf("============================================================\n");
}
