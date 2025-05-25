/******************************************************************************
# Author:            Ari Pollack and Xavier Braker
# Lab:               Discussion 7
# Date:              May 25, 2025
# Description:       This program will calculate health club membership fees
                     for an adult, child, or senior.
# Input:             choice (int), months (int)
# Output:            charges (double)
# Sources:           Discussion 7 specifications, discussion 7 sample, zyBooks
                     reference
#*****************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Declare and initialize constants for calculations
const int CHOICE_ADULT = 1;
const int CHOICE_CHILD = 2;
const int CHOICE_SENIOR = 3;
const int CHOICE_QUIT = 4;
const double RATE_ADULT = 40.0;
const double RATE_CHILD = 20.0;
const double RATE_SENIOR = 30.0;

// Declare core functions, which are defined after main()
void ShowMenu();
int GetChoice();
int GetMonths();
double CalcCharges(int choice, int months);
void ShowCharges(double charges);

int main() {
   // Declare variables for input and output
   int choice = 0;
   int months = 0;
   double charges = 0.0;

   // Set floating point precision to 2 decimal places for output
   cout << fixed << showpoint << setprecision(2);

   do {
      // Show menu
      ShowMenu();
      // Get and validate choice
      choice = GetChoice();
      // Quit if selected
      if (choice == CHOICE_QUIT) {
         return 0;
      }
      // Get and validate months
      months = GetMonths();
      cout << endl;
      // Calculate charges
      charges = CalcCharges(choice, months);
      // Display charges
      ShowCharges(charges);
      cout << endl;
   } while (choice != CHOICE_QUIT);

   return 0;
}

// Name:    ShowMenu()
// Desc:    This function displays the menu
// Input:   None
// Output:  Text
// Return:  void
void ShowMenu() {
   cout << "\t\tHealth Club Membership Menu" << endl;
   cout << "1. Standard Adult Membership" << endl;
   cout << "2. Child Membership" << endl;
   cout << "3. Senior Citizen Membership" << endl;
   cout << "4. Quit the program" << endl << endl;
}

// Name:    GetChoice()
// Desc:    This function gets the user's choice of membership
// Input:   choice (int)
// Output:  Prompt
// Return:  choice (int)
int GetChoice() {
   int choice = 0;
   cout << "Enter your choice: ";
   cin >> choice;
   while (cin.fail() || choice < CHOICE_ADULT || choice > CHOICE_QUIT) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter a valid menu choice: ";
      cin >> choice;
   }
   return choice;
}

// Name:    GetMonths()
// Desc:    This function gets the number of months for the membership
// Input:   months (int)
// Output:  Prompt
// Return:  months (int)
int GetMonths() {
   int months = 0;
   cout << "For how many months? ";
   cin >> months;
   while (cin.fail() || months < 0 || months > 60) {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter months between 0 and 60: ";
      cin >> months;
   }
   return months;
}

// Name:    CalcCharges()
// Desc:    This function calculates membership charges
// Input:   None
// Output:  None
// Return:  charges (double)
double CalcCharges(int choice, int months) {
   double charges = 0.0;
   switch (choice) {
      case CHOICE_ADULT:
         charges = static_cast<double>(months) * RATE_ADULT;
         break;
      case CHOICE_CHILD:
         charges = static_cast<double>(months) * RATE_CHILD;
         break;
      case CHOICE_SENIOR:
         charges = static_cast<double>(months) * RATE_SENIOR;
   }
   return charges;
}

// Name:    ShowCharges()
// Desc:    This function displays the membership charges
// Input:   charges (double)
// Output:  Text
// Return:  void
void ShowCharges(double charges) {
   cout << "The total charges are $" << charges << endl;
}