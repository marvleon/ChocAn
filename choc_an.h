// This file contains the class interface for the simulated client and ChocAn data ceter

#ifndef CHOCAN_H
#define CHOCAN_H

#include "provider_directory.h"

class choc_an
{
public:
    choc_an();
    ~choc_an();
    int provider_menu();
    int provider_options();
    int manager_options();
    int manager_menu();
    int operator_menu();
    int operator_options();

    // Provider wrapper functions
    int member_verify();  // Prompts for member ID and verifies member status
    int service_search(); // Prompts for service code and returns service name, code, cost, confirmation
    /*
        + Billing ChocAn for a service wrapper function
        + Report generation wrapper function
    */

    // Manager wrapper functions
    /*
        + Generate weekly summary report for accounts payable
        + Generate specific provider report (reuse from Provider wrapper functions)
        + Generate EFT report inc. provider name, ID, amount to be transferred
    */

    // Operator wrapper functions
    /*
        + Add member from member_list
        + Delete member from member_list
        + Modify member from member_list

        + Add provider from provider_list
        + Delete provider from provider_list
        + Modify provider from provider_list
    */
private:
    provider_directory provider_list;

    service_directory service_list;
    member_directory member_list;
    // service_ledger object?
};

#endif