#include "income.h"
#include <iostream>
#include <string>

using namespace std;

//Default constructor
Income::Income(bool isDerived){
    int choice = 0;
    cout << "Provide a name for it: ";
    cin.ignore();
    getline(cin,name);
    if(isDerived == false){
        cout << "Paid per hour? yes/no: ";
        cin >> choice;
        if(choice >= 0){
            cout << "Yes chosen. ";
            perHour = true;
            cout << "Wage: ";
            cin.ignore();
            cin >> hourly;
            cout << "Net Hours: ";
            cin.ignore();
            cin >> hours;
        } else {
            cout << "No chosen. " << endl;
            perHour = false;
            hourly = 0;
            hours = 0;
        }
        cout << "Flat payment? yes/no: ";
        cin.ignore();
        cin >> choice;
        if(choice >= 0){
            cout << "Yes chosen. " << endl;
            flatPayment = true;
            cout << "Amount: ";
            cin.ignore();
            cin >> flatAmount;
        } else {
            cout << "No chosen. " << endl;
            flatPayment = false;
            flatAmount = 0;
        }
        amount = (hourly*hours)+(flatAmount);
        amount = (int)(100*((amount)+0.5))/100; //Sets precision to two decimal points
    }
}
float Income::getAmount() const{
    return amount;
}
string Income::getName() const{
    return name;
}
string Income::toString() const{
    string str;
    str.append("Name: ");
    str += name;
    str += "\nAmount: ";
    str += to_string(amount);
    return str;
}
Fee::Fee() : Income(true){
    cout << "Enter amount: ";
    cin >> amount;
    perHour = 0;
    hourly = 0;
    hours = 0;
}
//Constructor
PV::PV() : Income(true){
    cout << "Is this photo or video? " << endl;
    cout << "(Enter nonnegative int for photo or negative int for video: ";
    int choice;
    cin >> choice;
    if(choice < 0){
        isPhoto = false;
    }else{
        isPhoto = true;
    }
    cin.ignore();       
    cout << "Paid per hour? yes/no: ";
    cin >> choice;
    if(choice >= 0){
        cout << "Yes chosen. ";
        perHour = true;
        cout << "Wage: ";
        cin.ignore();
        cin >> hourly;
        cout << "Hours: ";
        cin.ignore();
        cin >> hours;
    } else {cout << "No chosen. ";}
    cout << "Will you charge any additional fees? yes/no: ";
    cin.ignore(choice,sizeof(choice)/sizeof(int));
    cin >> choice;
    if(choice < 0){
        cout << "No chosen. " << endl;
    } else {
        while (choice >= 0){
            cout << "Yes chosen. Adding fee. " << endl;
            Fee* fptr = new Fee;
            fees.push_back(fptr);
            cout << "Add another fee? yes/no: ";
            cin.ignore();
            cin >> choice;
        }
    }
    cout << "Will this income incur any expenses? yes/no: ";
    cin.ignore();
    cin >> choice;
    while (choice >= 0){
        cout << "Yes chosen. Adding expense. " << endl;
        Expense* eptr = new Expense(false);
        costs.push_back(eptr);
        cout << "Add another expense? yes/no: ";
        cin.ignore();
        cin >> choice;
    }
    if (choice < 0){
        cout << "No chosen. " << endl;
    }
    for(int i=0; i<fees.size(); i++){
        totalFees += fees[i]->getAmount();
    }
    for(int i=0; i<fees.size(); i++){
        totalCost += costs[i]->getAmount();
    }
    profit = (perHour*hours)+totalFees-totalCost;
    amount = (perHour*hours)+totalFees;
    amount = (int)(100*((amount)+0.5))/100; //Sets precision to two decimal points
}
string PV::toString(){
    string str;
    str += "Name: ";
    str += name;
    str += "\n";
    str += "Type: ";
    if(isPhoto == true){
        str += "Photo ";
    } else {
        str += "Video ";
    }
    str += "\n";
    str += "Wage: ";
    str += to_string(hourly);
    str += "\n";
    str += "Fees (";
    str += to_string(totalFees);
    str += ")\n";
    for(int i=0; i<fees.size(); i++){
        str += "   ";
        str += to_string(i+1);
        str += ". ";
        str += fees[i]->getName();
        str += ": ";
        str += to_string(fees[i]->getAmount());
        str += "\n";
    }
    str += "Costs: ";
    str += to_string(totalCost);
    str += "\n";
    str += "Net Revanue: ";
    str += to_string(amount);
    str += "\n";
    str += "Total Profit: ";
    str += to_string(profit);
    str += "\n";
    return str;
}

//Constructor
Silverwood::Silverwood() : Income(true){
    perHour = true;
    cout << "How many weeks per year to work: ";
    cin >> weeksPerYear;
    cout << "How many days per week to work: ";
    cin.ignore();
    cin >> daysPerWeek;
    cout << "How many hours per day to work: ";
    cin.ignore();
    cin >> hours;
    cout << "Wage: ";
    cin.ignore();
    cin >> hourly;
    cout << "Include tips? yes/no: ";
    cin.ignore();
    int choice;
    cin >> choice;
    if(choice >= 0){
        cout << "Yes chosen. " << endl;
        cout << "Enter avg tip amount per day: ";
        cin.ignore();
        cin >> tipAvg;
    }
    amount = (hourly*hours*daysPerWeek*weeksPerYear)+tipAvg;
    amount = (int)(100*((amount)+0.5))/100; //Sets precision to two decimal points
}

