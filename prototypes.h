#define MAX_PATIENTS 100
#define SPECIALTIES 4
#define WARDS 4
#define MAX_BEDS 20

void hospitalHeader();
void hospitalMenue();
void printSpecialties();
void printWards();

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
                     const char specialtyNames[][30],
                     const double specialtyFees[],
                     const int consultationTimes[],
                     const char wardNames[][30],
                     const double wardRates[],
                     const int wardCapacities[],
                     int bedNumber[],
                     int bedOccupancy[][MAX_BEDS]);

void initializeBeds(int beds[][MAX_BEDS]);

int assignNextBed(int beds[][MAX_BEDS], int wardIndex,const int wardCapacities[WARDS]);
