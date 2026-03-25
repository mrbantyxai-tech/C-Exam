#include<iostream>
#include<string>

using namespace std;

class BankAccount{
    private:
        int accountNumber;
        double balance;
        string ownerName;
    public:
        BankAccount(int accNum, double bal, string owner){
            accountNumber = accNum;
            balance = bal;
            ownerName = owner;
        }
        void credit(double amount){
            balance += amount;
        }
        void debit(double amount){
            if(balance >= amount){
                balance -= amount;
            } else {
                cout << "Insufficient funds..." << endl;
            }
        }
        void displayBalance(){
            cout << "Account Number :- " << accountNumber << endl;
            cout << "Owner Name :- " << ownerName << endl;
            cout << "Balance :- " << balance << endl;
        }
};

int main(){
    int accNum;
    double bal;
    string owner;

    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter balance: ";
    cin >> bal;
    cout << "Enter owner name: ";
    cin >> owner;

    BankAccount account1(accNum, bal, owner);
    account1.displayBalance();

    double creditAmount;
    cout << "Enter amount to credit: ";
    cin >> creditAmount;
    account1.credit(creditAmount);
    account1.displayBalance();

    double debitAmount;
    cout << "Enter amount to debit: ";
    cin >> debitAmount;
    account1.debit(debitAmount);
    account1.displayBalance();

    return 0;
}