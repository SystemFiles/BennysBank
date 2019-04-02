/* Project By: Benjamin D. Sykes, Liam Stickney
 *
 * PLEASE NOTE: data.json file included in project folder should be used as example
 * format reference for data insertion and output.
 * */

#include <iostream>
#include <string>
#include "Bank.h"
#include "Account.h"
#include "LinkedTransactionList.h"
#include "Transaction.h"

using namespace std;

/**
 * Prints the main menu for the user
 */
void printMainMenu() {
    cout << "---------- [ Benny's Bank ] ----------" << endl;
    cout << "1. Add an Account" << endl;
    cout << "2. Delete an Account" << endl;
    cout << "3. Retrieve an Account" << endl;
    cout << "4. Load Accounts from file" << endl;
    cout << "5. Save Accounts to file" << endl;
    cout << "6. Sort the Accounts" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter an option [1-7]: ";
}

/**
 * Prints the transaction menu
 */
void printTransactionMenu() {
    cout << "\n---------- [ Transaction Menu ] ----------" << endl;
    cout << "1. Add a checking transaction" << endl;
    cout << "2. Add a savings transaction" << endl;
    cout << "3. Show Display Options" << endl;
    cout << "4. Finished" << endl;
    cout << "Enter an option [1-4]: ";
}

int main() {
    // Create the bank
    Bank * bank = new Bank();

    // Handle user option input
    int opt = 0;
    while (opt != 7) {
        printMainMenu();
        cin >> opt;

        switch (opt) {
            case 1: {
                // Add an account to the selected bank
                bank->addAccount();
                break;
            }
            case 2: {
                // Delete a selected account from the selected bank
                int targetUID = 0;
                cout << "Enter account UID to be deleted: ";
                cin >> targetUID;
                bank->delAccount(targetUID);
                break;
            }
            case 3: {
                // Search for an account at the bank using their Unique ID.
                int searchInput = 0;
                cout << "Enter account UID: ";
                cin >> searchInput;
                Account * foundAccount = bank->searchAccount(searchInput);

                // If we find, allow the user to modify transactions and display them
                if (foundAccount) {
                    cout << "Account found - " << foundAccount->getFName()
                    << " " << foundAccount->getLName()
                    << ":" << endl;

                    cout << "Checking Balance: $" << foundAccount->getCBal() << endl;
                    cout << "Savings Balance: $" << foundAccount->getSBal() << endl;

                    // Show Checking transactions
                    cout << "Checking Transactions: "
                    << foundAccount->getCheckingTransactions()->displayTransactions()
                    << endl;

                    // Show savings transactions
                    cout << "Savings Transactions: "
                    << foundAccount->getSavingsTransactions()->displayTransactions()
                    << endl;

                    // Handle transaction menu choices
                    int transactionOpt = 1;
                    while (transactionOpt != 4) {
                        int transID;
                        double transAmt;
                        printTransactionMenu();
                        cin >> transactionOpt;
                        cout << endl;

                        switch (transactionOpt) {
                            case 1: { // Add a transaction to the selected accounts checking account
                                Transaction * transaction = Transaction::buildTransaction();

                                // Update account balance
                                foundAccount->setCBal(foundAccount->getCBal() - transaction->getAmount());

                                // Insert the transaction into the linked list
                                foundAccount->getCheckingTransactions()->insert(transaction);
                                break;
                            }
                            case 2: { // Add a transaction to the selected accounts saving account
                                Transaction * transaction = Transaction::buildTransaction();

                                // Update account balance
                                foundAccount->setSBal(foundAccount->getSBal() - transaction->getAmount());

                                // Insert the transaction into the linked list
                                foundAccount->getSavingsTransactions()->insert(transaction);
                                break;
                            }

                            case 3: { // Show display options for the user
                                int displayOpt = 1;
                                while (displayOpt != 3) {
                                    cout << "[Display Menu]" << endl;
                                    cout << "[1] Display Checking Account" <<
                                    "\n[2] Display Savings Account" <<
                                    "\n[3] Done Display!" << endl;
                                    cout << "Choose Option[1-3]: ";
                                    cin >> displayOpt;
                                    cout << endl;
                                    switch (displayOpt) {
                                        case 1: {
                                            cout << "[Checking Account]" << endl;
                                            cout << foundAccount->getCheckingTransactions()->displayTransactions();
                                            break;
                                        }
                                        case 2: {
                                            cout << "[Savings Account]" << endl;
                                            cout << foundAccount->getSavingsTransactions()->displayTransactions();
                                            break;
                                        }
                                        case 3: {
                                            cout << "Done Display!" << endl;
                                            break;
                                        }
                                        default: {
                                            cout << "Invalid option...Try again." << endl;
                                        }
                                    }
                                }
                                break;
                            }

                            case 4: {
                                cout << "Done interacting with transactions!" << endl;
                                break;
                            }
                            default: {
                                cout << "Invalid option. Try again." << endl;
                            }
                        }
                    }
                }
                break;
            }
            case 4: { // Load the accounts in from a selected JSON-formatted data file.
                bank->loadAccounts();
                break;
            }
            case 5: { // Save the accounts in the bank to a selected JSON-formatted data file.
                bank->saveAccounts();
                break;
            }
            case 6: { // Handle sorting of the accounts
                bank->sortAccountsByBalance();
                break;
            }
            case 7: { // Exit the program
                cout << "Exiting program...Thanks for using Benny's Bank!" << endl;
                break;
            }
            default: {
                cout << "Invalid response...exiting.." << endl;
                exit(1);
            }

        }
    }

    return 0;
}