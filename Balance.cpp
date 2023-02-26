#include <iostream>
#include <cmath>
#include "Balance.h"

using namespace std;

double Balance::getInitialInvestment() const {return initial_investment;};
void Balance::setInitialInvestment(double investment) {initial_investment = investment;};

double Balance::getMonthlyDeposit() const {return monthly_deposit;};
void Balance::setMonthlyDeposit(double deposit) {monthly_deposit = deposit;};

double Balance::getAnnualInterest() const {return annual_interest;};
void Balance::setAnnualInterest(double interest) {annual_interest = interest;};

double Balance::getNumberOfYears() const {return number_of_years;};
void Balance::setNumberOfYears(double years) {number_of_years = years;};

double Balance::calculateYearEndBalance(int yearNumber, bool withAdditional){
    //(Opening Amount + Deposited Amount) * ((Interest Rate/100)/12)

    double balance = this->getInitialInvestment();
    double deposit = this->getMonthlyDeposit();
    double interest_rate = this->getAnnualInterest();
    double interest = 0;

    for(int i = 0; i < yearNumber; i++){
        if(withAdditional){
            interest = (balance + deposit) * ((interest_rate/100)/12);
            balance += deposit;
        }else{
            interest = balance * ((interest_rate/10)/12);
        }

        interest = floor(interest * 100) / 100; //Avoids compounding errors from extra cents
        balance += interest;
    }

    return balance;
    
}

double Balance::calculateYearEndEarnedInterest(int yearNumber, bool withAdditional){
    //(Opening Amount + Deposited Amount) * ((Interest Rate/100)/12)

    double balance = this->getInitialInvestment();
    double deposit = this->getMonthlyDeposit();
    double interest_rate = this->getAnnualInterest();
    double interest = 0;

    for(int i = 0; i < yearNumber; i++){
        if(withAdditional){
            interest = (balance + deposit) * ((interest_rate/100)/12);
            balance += deposit;
        }else{
            interest = balance * ((interest_rate/10)/12);
        }

        interest = floor(interest * 100) / 100; //Avoids compounding errors from extra cents
        balance += interest;
    }

    return interest;

}

void Balance::printReportNoAdditional(){

    cout << endl;
    cout << "    Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << "  Year        Year End Balance      Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    double yearEndBalance, yearEndEarnedInterest;

    for(int i = 1; i <= number_of_years; i++){
        //Calculate year end balance
        yearEndBalance = this->calculateYearEndBalance(i,false);

        //Calculate year end earned interest
        yearEndEarnedInterest = this->calculateYearEndEarnedInterest(i,false);

        //Output Report
        cout << "     " << i << "                $" << yearEndBalance << "                $" << yearEndEarnedInterest << endl << endl;
    }
}

void Balance::printReportWithAdditional(){

    cout << endl;
    cout << "      Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "================================================================" << endl;
    cout << "  Year        Year End Balance      Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------------" << endl;

    double yearEndBalance, yearEndEarnedInterest;

    for(int i = 1; i <= number_of_years; i++){
        //Calculate year end balance
        yearEndBalance = this->calculateYearEndBalance(i,true);

        //Calculate year end earned interest
        yearEndEarnedInterest = this->calculateYearEndEarnedInterest(i,true);

        //Output Report
        cout << "     " << i << "                $" << yearEndBalance << "                $" << yearEndEarnedInterest << endl << endl;
    }
}