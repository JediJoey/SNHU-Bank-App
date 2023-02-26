#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include "Balance.h"

using namespace std;


int main() {
    
    Balance balance;

    double initial_investment;
    double monthly_deposit;
    double annual_interest;
    int number_of_years;

    cout << "**************************************" << endl;
    cout << "*************DATA INPUT***************" << endl;
    
    //Validate Input for Initial Investment
    while (true) {
        cout << "Initial investment amount:  $";
        cin >> initial_investment;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        } else {
            balance.setInitialInvestment(initial_investment);
            break;
        }
    }

    //Validate Input for Monthly Deposit
    while (true) {
        cout << "Monthly deposit:  $";
        cin >> monthly_deposit;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        } else {
            balance.setMonthlyDeposit(monthly_deposit);
            break;
        }
    }

    //Validate Input for Annual Interest
    while (true) {
        cout << "Annual interest:  %";
        cin >> annual_interest;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        } else {
            balance.setAnnualInterest(annual_interest);
            break;
        }
    }

    //Validate Input for Number of years
    while (true) {
        cout << "Number of years:  ";
        cin >> number_of_years;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again." << endl;
        } else {
            balance.setNumberOfYears(number_of_years);
            break;
        }
    }

    //Print Reports
    balance.printReportNoAdditional();
    balance.printReportWithAdditional();

    return 0;
}