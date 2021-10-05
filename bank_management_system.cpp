#include <iostream>

using namespace std;


class Bank_management_sys {

private:

    int acno;
    char name[30];
    long balance;

public:

    void Open_Account();
    void Show_Account();
    void Deposit();
    void Withdrawal();
    int Search_id(int);

};

void Bank_management_sys :: Open_Account(){
        
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter  Balance: ";
        cin >> balance;
        cout<<endl;
}

void Bank_management_sys :: Show_Account(){

        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout<<endl;
}

void Bank_management_sys :: Deposit(){
        
        long amt;
        cout << "Enter Amount U want to deposit? ";
        cin >> amt;
        balance = balance + amt;
        cout<<endl;
}

void Bank_management_sys :: Withdrawal()
    {
        long amt;
        cout << "Enter Amount U want to withdraw? ";
        cin >> amt;
        if (amt <= balance){

            balance = balance - amt;
            cout<<"Balance Amount in Account "<< acno <<" is: "<<balance;
        }
        else{
            cout << "Less Balance..." << endl;
        }
        cout<<endl;
    }

int Bank_management_sys::Search_id(int a)
{
    if (acno == a) {
        Show_Account();
        return (1);
    }
    return (0);
}

// main Program
int main()
{
    // Variable Decleration 
    
    int n ;
    int found = 0; 
    int a; 
    int ch;

    // To get number of datas to be entered

    cout << "Enter the No of details to be Entered : ";
    cin>>n ; 
    cout<<endl;
    
    //Object of the class Bank_management_system having n objects
   
    Bank_management_sys C[n]; 

    for (int i = 0; i < n; i++) {
        C[i].Open_Account();
    }

    do {
        
        // Display options
        
        cout << "\n1:Display All Accounts \n2: Display By Account No\n3: Deposit\n4: Withdraw\n5: Exit" << endl;

        // User input
        
        cout << "Please enter your choice: ";
        cin >> ch;
        cout<<endl;
 
        switch (ch) {
        case 1: // To display account information
            
            for (int i = 0; i < n; i++) {
                C[i].Show_Account();
            }
            break;
       
        case 2: // To search Detail 
    
            cout << "Account Number: ";
            cin >> a;

            for (int i = 0; i < n; i++) {
                found = C[i].Search_id(a);
                if (found)
                    break;
            }

            if (!found)
                cout << "Record Not Found" << endl;
            break;
       
       case 3: // deposit operation
            
            cout << "Account Number To Deposit Amount? ";
            cin >> a;
            
            for (int i = 0; i < n; i++) {
                found = C[i].Search_id(a);
                if (found) {
                    C[i].Deposit();
                    break;
                }
            }
            
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        
        case 4: // withdraw operation
            
            cout << "Account Number To Withdraw Amount? ";
            cin >> a;
            for (int i = 0; i < n; i++) {
                found = C[i].Search_id(a);
                if (found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            
            if (!found)
                cout << "Record Not Found" << endl;
            break;
        
        case 5: // exit
            
            cout << "Have a nice day" << endl;
            break;
        
        default:
            
            cout << "Wrong Option" << endl;
        }
    } while (ch != 5);
    
    return 0;
}