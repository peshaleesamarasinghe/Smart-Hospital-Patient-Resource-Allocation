#define MAX_PATIENTS 100
#define SPECIALTIES 4
#define WARDS 4
#define MAX_BEDS 20

extern const char specialtyNames[SPECIALTIES][30];
extern const char wardNames[WARDS][30];
extern const int wardCapacities[WARDS];

void hospitalHeader();
void hospitalMenue();
void printSpecialties(const char specialtyNames[][30],
                      const double specialtyFees[],
                      const int consultationTimes[],
                      const int dailyPatientCaps[]);
void printWards(const char wardNames[WARDS][30],
                const double wardRates[WARDS],
                const int wardCapacities[WARDS]);

void registerPatient(char patientNames[][50],
                     int ages[],
                     int urgancy[],
                     int specialty[],
                     int admitted[],
                     int ward[],
                     int days[],
                     double waitTime[],
                     double baseFee[],
                     double surcharge[],
                     double wardCost[],
                     double grossBill[],
                     double discount[],
                     double finalBill[],
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

void initializeBeds(int bedOccupancy[][MAX_BEDS]);

int assignNextBed(int bedOccupancy[][MAX_BEDS],
                  int wardIndex,
                  const int wardCapacities[WARDS]);

double calculateSurcharge(double base,int triage);
double calculateWardCost(int ward,int days,const double wardRates[WARDS]);
double calculateDiscount(double gross,int ages);

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
                      const char wardNames[][30]);

void findPatientBill(char patientNames[][50],
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
                     int patientCount);

void displayTriageQueue(char patientNames[][50],
                        int urgency[],
                        int patientCount);

void monitorBeds(int bedOccupancy[][MAX_BEDS]);

void generateReports(char patientNames[][50],
                     int urgency[],
                     double finalBill[],
                     double discount[],
                     int patientCount,
                     int bedOccupancy[][MAX_BEDS]);

void saveBeds(int bedOccupancy[][MAX_BEDS]);
