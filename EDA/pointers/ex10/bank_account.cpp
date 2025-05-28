#include "bank_account.h"
#include <iostream>

BankAccount::BankAccount(int accNum, string accHolder, double bal): accountNumber(accNum), accountHolderName(accHolder), balance(bal){}

int BankAccount::getAccountNumber() {
   return accountNumber;
}

void BankAccount::setAccountNumber(int accNum) {
    accountNumber= accNum;
}

string BankAccount::getAccountHolderName() {
    return accountHolderName;
}

void BankAccount::setAccountHolderName(string accHolder) {
    accountHolderName = accHolder;
}

double BankAccount::getBalance() {
    return balance;
}

void BankAccount::setBalance(double bal) {
    balance = bal;
}

void BankAccount::deposit(double amount) {
    cout<<"Deposited: $"<<amount<<endl;
    balance += amount;
}

void BankAccount::withdraw(double amount) {
    if(balance>amount){
        cout<<"withdrawn: $"<<amount<<endl;
        balance -= amount;
    }
    else{
        cout<<"Insufficient balance"<<endl;
    }
}