//
// Created by Ben Sykes and Liam Stickney on 2019-04-01.
//

#ifndef BENNYSBANK_ACCOUNT_H
#define BENNYSBANK_ACCOUNT_H

#include <string>
#include "LinkedTransactionList.h"

using namespace std;

/**
 * The account used in Bank
 */
class Account {
private:
    int id;
    string fName;
    string lName;
    double cBal;
    double sBal;
    LinkedTransactionList * checkingTransactions;
    LinkedTransactionList * savingsTransactions;
public:
    /**
     * Account constructor used to build the account
     * @param id The UID of the account
     * @param fName The First name of the owner of the account
     * @param lName The Last name of the owner of the account
     * @param cBal The starting checking balance for the account
     * @param sBal The starting savings balance for the account
     */
    Account(int id, string fName, string lName, double cBal, double sBal) {
        this->id = id;
        this->fName = fName;
        this->lName = lName;
        this->cBal = cBal;
        this->sBal = sBal;

        // Create empty LinkedLists for transactions
        this->checkingTransactions = new LinkedTransactionList();
        this->savingsTransactions = new LinkedTransactionList();
    }

    /**
     * Free memory on heap when deleted
     */
    ~Account() {
        delete this->checkingTransactions;
        delete this->savingsTransactions;
    }

    /**
     * Operator overloading useful for sorting by Balance
     * @param other The other account being compared
     * @return True if this account is less than other, else false.
     */
    bool operator< (const Account &other) const {
        return (cBal + sBal) < (other.cBal + other.sBal);
    }

    /**
     * Gets the entire transaction list for the checking account
     * @return The LinkedTransactionList for the checking account
     */
    LinkedTransactionList *getCheckingTransactions() const {
        return checkingTransactions;
    }

    /**
     * Gets the entire transaction list for the savings account
     * @return The LinkedTransaction list for savings account
     */
    LinkedTransactionList *getSavingsTransactions() const {
        return savingsTransactions;
    }

    /**
     * Get the UID of the account
     * @return
     */
    int getId() const {
        return id;
    }

    /**
     * Get the first name of the account
     * @return
     */
    const string &getFName() const {
        return fName;
    }

    /**
     * Set the first name
     * @param fName The first name
     */
    void setFName(const string &fName) {
        Account::fName = fName;
    }

    /**
     * Get the Last name of the account
     * @return Last name
     */
    const string &getLName() const {
        return lName;
    }

    /**
     * Set the Last name of the account
     * @param lName Last name
     */
    void setLName(const string &lName) {
        Account::lName = lName;
    }

    /**
     * Get the current Checking account balance
     * @return Checking account balance
     */
    double getCBal() const {
        return cBal;
    }

    /**
     * Set current checking account balance
     * @param cBal Checking account balance
     */
    void setCBal(double cBal) {
        Account::cBal = cBal;
    }

    /**
     * Get the current savings account balance
     * @return Savings balance
     */
    double getSBal() const {
        return sBal;
    }

    /**
     * Set the current savings balance
     * @param sBal Savings balance
     */
    void setSBal(double sBal) {
        Account::sBal = sBal;
    }
};

#endif //BENNYSBANK_ACCOUNT_H
