#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "expense.h"

    //Default constructor
    Expense::Expense(bool isDerived){
        if(isDerived == false){
            cout << "Name of expense: ";
            cin.ignore();
            getline(cin,name);
            cout << "Amount: ";
            cin >> setprecision(2) >> amount;
            amount = (int)(100*((amount)+0.5))/100; //Sets precision to two decimal points
        }
    }
    //Returns a string of Expense data
    string Expense::toString(){
        string str;
        str += "Name: ";
        str += name;
        str += "\n";
        str += "Amount: ";
        str += to_string(amount);
        str += "\n";
        return str;
    }
    float Expense::getAmount() const{
        return amount;
    }                
    //Default constructor
    College_Expenses::College_Expenses(): Expense(true){
        cout << "Name of school: ";
        cin.ignore();
        getline(cin,name);
        cout << "Tuition, yearly, costs: ";
        cin.ignore();
        cin >> setprecision(2) >> tuition;
        cout << "Housing, yearly, costs: ";
        cin.ignore();
        cin >> setprecision(2) >> housing;
        cout << "Books, yearly, cost: ";
        cin.ignore();
        cin >> setprecision(2) >> books;
        setprecision(2);
        amount = (int)(100*((tuition+housing+books)+0.5))/100;
    }
    //Returns a string of Expense data
    string College_Expenses::toString(){
        string str;
        str += "Name: ";
        str += name;
        str += "\n";
        str += "Tuition: ";
        str += to_string(tuition);
        str += "\n";
        str += "Housing: ";
        str += to_string(housing);
        str += "\n";
        str += "Books: ";
        str += to_string(books);
        str += "\n";
        str += "Total Amount: ";
        setprecision(2);
        str += to_string(amount);
        return str;
    }
    //Default constructor
    Recreation_Expense::Recreation_Expense() : Expense(true){
        cout << "Name of expense: ";
        cin.ignore();
        getline(cin,name);
        cout << "Amount: ";
        cin >> setprecision(2) >> amount;
        amount = (int)(100*((amount)+0.5))/100;
    }

