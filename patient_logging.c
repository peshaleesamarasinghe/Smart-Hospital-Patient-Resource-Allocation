#include <stdio.h>
#include "prototypes.h"

void patientLog(int patientCount,
                char patientNames[][50],
                int ages[],
                int urgency[],
                int specialty[],
                int admitted[],
                int ward[],
                int bedNumber[],
                int days[],
                double waitTime[],
                double finalBill[])
{
    FILE *file = fopen("patient_records.txt", "a");

    if(file == NULL)
    {
        printf("\nError: Could not open patient_records.txt!\n");
        return;
    }

    fprintf(file, "Patient ID: PAT-%04d\n", 1001 + patientCount);
    fprintf(file, "Name: %s\n", patientNames[patientCount]);
    fprintf(file, "Age: %d\n", ages[patientCount]);
    fprintf(file, "Triage Level: %d\n", urgency[patientCount]);
    fprintf(file, "Specialty: %s\n",specialtyNames[specialty[patientCount] - 1]);

    if(admitted[patientCount] == 1)
    {
        fprintf(file, "Ward: %s\n",wardNames[ward[patientCount] - 1]);
        fprintf(file, "Bed Number: %d\n", bedNumber[patientCount]);
        fprintf(file, "Days Admitted: %d\n", days[patientCount]);
    }
    else
    {
        fprintf(file, "Admission: Outpatient / OPD\n");
    }

    fprintf(file, "Waiting Time: %.0f minutes\n", waitTime[patientCount]);
    fprintf(file, "Final Bill: LKR %.2f\n", finalBill[patientCount]);

    fprintf(file,"------------------------------------------------------------\n");

    fclose(file);
}
