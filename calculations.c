#include <stdio.h>
#include "prototypes.h"

double calculateSurcharge(double base, int triage)
{
    if(triage == 2)
    {
        return base * 0.20;
    }
    else if(triage == 3)
    {
        return base * 0.50;
    }

    return 0.0;
}

double calculateWardCost(int ward,
                         int days,
                         const double wardRates[WARDS])
{
    if(ward == 0)
    {
        return 0.0;
    }

    return wardRates[ward - 1] * days;
}

double calculateDiscount(double gross, int ages)
{
    if(ages < 5 || ages > 65)
    {
        return gross * 0.15;
    }

    return 0.0;
}
