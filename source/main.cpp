#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "expense.h"
#include "income.h"

using namespace std;

//Allows user to create expenses
void setExpenses(vector<Expense*> & _expenses);
//Allows user to create incomes
void setIncomes(vector<Income*> & _incomes);
void writeFinances(string expensePath, string incomePath);

int main(){
    cout << "______________________________________________________________________________" << endl;
    cout << "Throughout this program, when prompted with a yes/no choice, " << endl;
    cout << "enter either a non-negative integer for \"yes\" or a negtive integer for \"no.\" " << endl;
    cout << "______________________________________________________________________________" << endl;
    //Vector stores all expenses
    //It gets initialized by setExpenses()
    vector<Expense*> expenses;
    vector<Income*> incomes;
    setExpenses(expenses);
    setIncomes(incomes);
    writeFinances(".\\output_files\\expenses.txt",".\\output_files\\incomes.txt");
    return 0;
}

///FUNCTION DEFINITIONS///

//Allows user to create expenses
void setExpenses(vector<Expense*> & _expenses){
    ofstream expensesFile(".\\output_files\\expenses.txt");
    ofstream college(".\\output_files\\college.txt");
    ofstream recreation(".\\output_files\\recreation.txt");
    ofstream miscExpense(".\\output_files\\miscExpense.txt");
    int loop_index = 0;//Counts times loop repeats
                   // and functions as index for
                   // vector _expenses
    int count1 = 0;//Counts College_Expenses
    int count2 = 0;//Counts Recreation_Expenses
    int count3 = 0;//Counts Misc_Expenses
    cout << "Let's gather expense data, " << endl;
    int choice = 0;//User uses as yes/no
    while(choice>-1){
        cout << "Would you like to add an expense? yes/no: ";
        //User chooses
        cin >> choice;
        //Break if no is chosen
        if(choice<0){
            cout << "No chosen. " << endl << "Expenses finished." << endl;
            break;
        } else {
            cin.ignore();
            cout << "Yes chosen. " << endl << "Adding expense." << endl;
            //Prompt for preset expenses
            cout << "____________________________________" << endl;
            cout << "Expense types: " << endl;
            cout << "1: College Expenses" << endl;
            cout << "2: Recreation Expense" << endl;
            cout << "3: Miscellaneous expense " << endl;
            cout << endl;
            cout << "Enter the number of the expense you would like to add, " << endl;
            cout << "or enter a negative number to exit without adding: ";
            cin >> choice;
            if(choice<0){
                //Break expenses loop
                cout << choice << " chosen. " << endl;
                cout << "Exiting expenses. " << endl;
                break;
            } else {
                switch (choice) {
                    case 1:{
                        if(count1 < 1){
                            college << "______________________________________________" << endl;
                            college << "College Expenses: " << endl;
                        }
                        College_Expenses* col = new College_Expenses;
                        _expenses.push_back(col);
                        college << col->toString();
                        break;
                    }
                    case 2:{
                        if(count2 < 1){
                            recreation << "______________________________________________" << endl;
                            recreation << "Recreation Expenses: " << endl;
                        }
                        Recreation_Expense* rec = new Recreation_Expense;
                        _expenses.push_back(rec);
                        recreation << rec->toString();
                        break;
                    }
                    case 3:{
                        if(count3 < 1){
                            miscExpense << "______________________________________________" << endl;
                            miscExpense << "Miscellaneous Expenses: " << endl;
                        }
                        Expense* ex = new Expense(false);
                        _expenses.push_back(ex);
                        miscExpense << ex->toString();
                        break;
                    }
                    default:{
                        cout << "Invalid entry." << endl;
                        break;
                    }
                }
            }
        }
        loop_index++;
    }
}

//Allows user to create expenses
void setIncomes(vector<Income*> & _incomes){
    ofstream incomesFile(".\\output_files\\incomes.txt");
    ofstream miscIncome(".\\output_files\\misc.txt");
    ofstream pvIncome(".\\output_files\\pv.txt");
    ofstream silverwoodIncome(".\\output_files\\silverwood.txt");
    int loop_index = 0;//Counts times loop repeats
                   // and functions as index for
                   // vector _expenses
    int count1=0;//Counts incomes type 1
    int count2=0;//Counts incomes type 2
    int count3=0;//Counts incomes type 3
    cout << "Let's gather income data, " << endl;
    int choice = 0;//User uses as yes/no
    while(choice>-1){
        cout << "Would you like to add an income? yes/no: ";
        //User chooses
        cin >> choice;
        //Break if no is chosen
        if(choice<0){
            cout << "No chosen. " << endl << "Incomes finished." << endl;
            break;
        } else {
            cin.ignore();
            cout << "Yes chosen. " << endl << "Adding income." << endl;
            //Prompt for preset expenses
            cout << "____________________________________" << endl;
            cout << "Income types: " << endl;
            cout << "1: Photo/Video " << endl;
            cout << "2: Silverwood " << endl;
            cout << "3: Misc " << endl;
            cout << endl;
            cout << "Enter the number of the income you would like to add, " << endl;
            cout << "or enter a negative number to exit without adding: ";
            cin >> choice;
            if(choice<0){
                //Break expenses loop
                cout << choice << " chosen. " << endl;
                cout << "Exiting incomes. " << endl;
                break;
            } else {
                cout << choice << " chosen. " << endl;
                cout << "Adding income. " << endl;
                switch (choice) {
                    case 1:{
                        if(count1<1){
                            pvIncome << "______________________________________________" << endl;
                            pvIncome << "Photo/Video " << endl;
                        }    
                        PV* pv = new PV;
                        _incomes.push_back(pv);
                        pvIncome << pv->toString() << endl;
                        count1++;
                        break;
                    }
                    case 2:{
                        if(count2<1){
                            silverwoodIncome << "______________________________________________" << endl;
                            silverwoodIncome << "Silverwood " << endl;
                        }
                        Silverwood* s = new Silverwood;
                        _incomes.push_back(s);
                        silverwoodIncome << s->toString() << endl;
                        count2++;
                        break;
                    }
                    case 3:{
                        if(count2<11){
                            miscIncome << "______________________________________________" << endl;
                            miscIncome << "Miscellaneous Incomes: " << endl;
                        }                        
                        Income* m = new Income(false);
                        _incomes.push_back(m);
                        miscIncome << m->toString() << endl;
                        count3++;
                        break;
                    }
                    default:{
                        cout << "Invalid entry." << endl;
                        break;
                    }
                }
            }
        }
        loop_index++;
    }
}

void writeFinances(string expensePath, string incomePath){
    cout << "Writing report..." << endl;
    ofstream report(".\\output_files\\report.txt");
    fstream exp(expensePath);
    ifstream col(".\\output_files\\college.txt");
    ifstream rec(".\\output_files\\recreation.txt");
    ifstream miscExp(".\\output_files\\miscExpense.txt");
    fstream inc(incomePath);
    ifstream miscInc(".\\output_files\\misc.txt");
    ifstream pvInc(".\\output_files\\pv.txt");
    ifstream silverwoodInc(".\\output_files\\silverwood.txt");
    string line;

    
    col.seekg(0,ios::beg);
    cout << "Reading expenses..." << endl;
    while(getline(col,line)){
        exp << line << endl;
    }
    if(col.eof()){cout << "End of College Expenses file reached. ";}
    while(getline(rec,line)){
        exp << line << endl;
    }
    rec.seekg(0,ios::beg);
    if(rec.eof()){cout << "End of Recreation Expenses file reached. ";}
    while(getline(miscExp,line)){
        exp << line << endl;
    }
    if(miscExp.eof()){cout << "End of Miscellaneous Expenses file reached. ";}
    pvInc.seekg(0,ios::beg);
    cout << "Reading incomes..." << endl;
    while(getline(pvInc,line)){
        inc << line << endl;
    }
    if(pvInc.eof()){cout << "End of Photo/Video incomes file reached. " << endl;}
    silverwoodInc.seekg(0,ios::beg);
    while(getline(silverwoodInc,line)){
        inc << line << endl;
    }
    if(silverwoodInc.eof()){cout << "End of Silverwood incomes file reached. " << endl;}
    miscInc.seekg(0,ios::beg);
    while(getline(miscInc,line)){
        inc << line << endl;
    }
    if(miscInc.eof()){cout << "End of Miscellaneous incomes file reached. " << endl;}
    cout << "Generating summary..." << endl;    
    exp.seekg(0,ios::beg);
    while (getline(exp,line)){
        report << line << endl;
    }
    inc.seekg(0,ios::beg);
    while (getline(inc,line)){
        report << line << endl;
    }
    cout << "Incomes read and written. " << endl << endl;
}