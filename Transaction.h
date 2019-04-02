//
// Created by Ben Sykes and Liam Stickney on 2019-04-01.
//

#ifndef BENNYSBANK_TRANSACTION_H
#define BENNYSBANK_TRANSACTION_H

#include <iostream>
#include <chrono>

using namespace std;

/**
 * Defines individual transactions
 */
class Transaction {
private:
    int id;
    double amount;
    double time;
public:
    Transaction * next;

    /**
     * Builds a transaction
     * @param id The ID of the transaction
     * @param amt The amount positive or negative of the transaction
     */
    Transaction(int id, double amt) {
        this->id = id;
        this->amount = amt;
        this->time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    }

    ~Transaction() {
        delete next;
    }

    /**
     * Prompts the user to build a transaction
     * @return The build transaction object
     */
    static Transaction * buildTransaction() {
        int transID;
        double transAmt;
        cout << "Enter transaction ID: ";
        cin >> transID;
        cout << endl;
        cout << "Enter transaction Amount: $";
        cin >> transAmt;
        cout << endl;

        Transaction * transaction = new Transaction(transID, transAmt);

        return transaction;
    }

    /**
     * Gets the ID of a transaction
     * @return integer ID of the transaction
     */
    int getID() {
        return this->id;
    }

    /**
     * Get the amount of the transaction
     * @return Amount of the transaction +/-
     */
    double getAmount() {
        return this->amount;
    };

    /**
     * Get the exact time the transaction took place.
     * @return The SYSTEM_CLOCK time of when exactly the
     * transaction was entered into the bank
     */
    double getTime() {
        return this->time;
    };
};

#endif //BENNYSBANK_TRANSACTION_H
