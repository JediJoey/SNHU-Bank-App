#ifndef BALANCE_H
#define BALANCE_H

#include <iostream>
#include <cmath>

using namespace std;

class Balance{

    public:
        double getInitialInvestment() const;
        void setInitialInvestment(double investment);

        double getMonthlyDeposit() const;
        void setMonthlyDeposit(double deposit);

        double getAnnualInterest() const;
        void setAnnualInterest(double interest);

        double getNumberOfYears() const;
        void setNumberOfYears(double years);

        double calculateYearEndBalance(int yearNumber, bool withAdditional);
        double calculateYearEndEarnedInterest(int yearNumber, bool withAdditional);

        void printReportNoAdditional();
        void printReportWithAdditional();
    
    private:
        double initial_investment;
        double monthly_deposit;
        double annual_interest;
        int number_of_years;

};

#endif