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
//Parameters: vector<Income*> & _incomes
//Returns void
void setIncomes(vector<Income*> & _incomes);
//Writes finance data to output files
//Parameters: string expensePath, string incomePath
//Returns void
void writeFinances(string expensePath, string incomePath);
//Reports gross income and feedback message in a new output file
//Parameters: vector<Income*> & _incomes, vector <Expense*> & _expenses
//Returns void
void gross(vector<Income*> & _incomes, vector <Expense*> & _expenses);

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
    gross(incomes,expenses);//Gross
    
    expenses.clear();//Delete values in vector
    incomes.clear();//Delete values in



    return 0;
}

///FUNCTION DEFINITIONS///

//Allows user to create expenses
void setExpenses(vector<Expense*> & _expenses){
    //Open output files
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
                        //Create heading
                        if(count1 < 1){
                            college << "______________________________________________" << endl;
                            college << "College Expenses: " << endl;
                        }
                        //Add new object to vector and write data to file
                        College_Expenses* col = new College_Expenses;
                        _expenses.push_back(col);
                        college << col->toString();
                        count1++;
                        break;
                    }
                    case 2:{
                        //Add heading
                        if(count2 < 1){
                            recreation << "______________________________________________" << endl;
                            recreation << "Recreation Expenses: " << endl;
                        }
                        //Add new object to vector and write data to file
                        Recreation_Expense* rec = new Recreation_Expense;
                        _expenses.push_back(rec);
                        recreation << rec->toString();
                        count2++;
                        break;
                    }
                    case 3:{
                        //Add heading
                        if(count3 < 1){
                            miscExpense << "______________________________________________" << endl;
                            miscExpense << "Miscellaneous Expenses: " << endl;
                        }
                        //Add new object to vector and write data to file
                        Expense* ex = new Expense(false);
                        _expenses.push_back(ex);
                        miscExpense << ex->toString();
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

//Allows user to create expenses
void setIncomes(vector<Income*> & _incomes){
    //Open output files
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
                        //Create Heading
                        if(count1<1){
                            pvIncome << "______________________________________________" << endl;
                            pvIncome << "Photo/Video Incomes" << endl;
                        }  
                        //Add new PV to vector  
                        PV* pv = new PV;
                        _incomes.push_back(pv);
                        //Write to file
                        pvIncome << pv->toString() << endl;
                        count1++;//Increment count1
                        break;
                    }
                    case 2:{
                        //Write heading
                        if(count2<1){
                            silverwoodIncome << "______________________________________________" << endl;
                            silverwoodIncome << "Silverwood " << endl;
                        }
                        //Add new Silverwood to vector
                        Silverwood* s = new Silverwood;
                        _incomes.push_back(s);
                        //Write to file
                        silverwoodIncome << s->toString() << endl;
                        //Increment count2
                        count2++;
                        break;
                    }
                    case 3:{
                        //Add heading
                        if(count3<1){
                            miscIncome << "______________________________________________" << endl;
                            miscIncome << "Miscellaneous Incomes: " << endl;
                        }     
                        //Add new Income to vector                   
                        Income* m = new Income(false);
                        _incomes.push_back(m);
                        //Write data to file
                        miscIncome << m->toString() << endl;
                        //Increment count3
                        count3++;
                        break;
                    }
                    default:{
                        //If invalid entry, tell user
                        cout << "Invalid entry." << endl;
                        break;
                    }
                }
            }
        }
        loop_index++;//Increment loop index
    }
}

void writeFinances(string expensePath, string incomePath){
    cout << "Writing report..." << endl;
    //Open input and output files
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

    //READ DATA FROM ALL FILES
    // AND WRITE ALL DATA TO REPORT FILE
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
    cout << "Incomes read and written. " << endl;
    cout << "Closing files..." << endl;
    report.close();
    exp.close();
    col.close();
    rec.close();
    miscExp.close();
    inc.close();
    miscInc.close();
    pvInc.close();
    silverwoodInc.close();


}

void gross(vector<Income*> & _incomes, vector <Expense*> & _expenses){
    float totalIncome = 0;//Gross income
    //Calculate total income
    for(int i=0;i<_incomes.size();i++){
        totalIncome += _incomes[i]->getAmount();
    }
    //Calculate total expenses
    float totalExpenses = 0;
    for(int i=0;i<_incomes.size();i++){
        totalExpenses += _expenses[i]->getAmount();
    }
    //Calculate and report gross earnings
    ofstream gross(".\\output_files\\gross.txt");//Open output file
    gross << "GROSS EARNINGS: " << to_string(totalIncome - totalExpenses) << endl;
    gross << "\n";
    //Provide feedback message
    if((totalIncome - totalExpenses)>0){
        gross << "Earned enough to cover expenses." << endl;
    } else {
        gross << "Might need to work some more to make up the deficit!" << endl;
    }
}
