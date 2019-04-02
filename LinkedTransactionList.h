//
// Created by Ben Sykes and Liam Stickney on 2019-04-01.
//

#ifndef BENNYSBANK_LINKEDTRANSACTIONLIST_H
#define BENNYSBANK_LINKEDTRANSACTIONLIST_H

#include <string>
#include "Transaction.h"

using namespace std;

/**
 * Class used to store transactions
 */
class LinkedTransactionList {
public:
    // The head of the list (DEFAULT = NULL)
    Transaction * start;

    LinkedTransactionList() {
        this->start = NULL;
    }

    ~LinkedTransactionList() {
        delete start;
    }

    /**
     * Gets a formatted display string to show to the user
     * of the transactions present in this account
     * @return The formatted display string
     */
    string displayTransactions() {
        string displayString = "";
        Transaction * current = start;
        // Build string for each transaction
        while (current) {
            displayString += "\n---------------------------------------------"
                             "\nID: " + to_string(current->getID()) +
                    "\nAmount: $ " + to_string(current->getAmount()) +
                    "\nTime: " + to_string(current->getTime()) + "ms\n"
                    + "---------------------------------------------\n";

            current = current->next;
        }

        // Change if no transactions present
        if (displayString.length() < 1) {
            displayString = "NO TRANSACTIONS FOUND...";
        }

        return displayString;
    }

    /**
     * Insert a transaction into the
     * accounts transaction record
     * @param transaction The transaction to be inserted
     */
    void insert(Transaction * transaction) {
        Transaction * current = start;

        if (start == NULL) {
            start = transaction;
            transaction->next = NULL;
        } else {
            // Go to back of the Linked List
            while (current->next != NULL) {
                current = current->next;
            }

            current->next = transaction;
            current->next->next = NULL;
        }
    }
};

#endif //BENNYSBANK_LINKEDTRANSACTIONLIST_H
