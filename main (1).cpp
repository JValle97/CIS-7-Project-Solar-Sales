#include <iostream>
#include "Travel.h"
using namespace std;

int main()
{
    char selection, choice, cont;
    int start, end, stop;
    Travel trip;
    
    // Main loop.
    do {
        // Display the main menu.
        cout << "Welcome to your Travel Planner\n\n"
            << "A. Low Cost\nB. Shortest Path (Round Trip)\nC. Adjacent Cities\nD. Road Info\n"
            << "Please select an option from the menu above: ";
        cin >> selection;
        
        // Check for invalid input.
        while (cin.fail() || (toupper(selection) != 'A' && 
                              toupper(selection) != 'B' && 
                              toupper(selection) != 'C' && 
                              toupper(selection) != 'D'))
        {
            cout << "Invalid input.\nPlease enter a valid option from the menu above: ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> selection;
        }
        
        // Set the menu selection.
        trip.setSelection(toupper(selection));

        cout << "You have selected " << (char)toupper(selection) << endl << endl;
        
        // Prompt the user for the starting city if necessary.
        if (toupper(selection) == 'A' || toupper(selection) == 'C')
        {
            cout << "1. Riverside\n2. Perris\n3. Moreno Valley\n4. Hemet\n"
                << "Select a starting point: ";
            cin >> start;
            
            // Check for invalid input.
            while (cin.fail() || start < 1 || start > 4)
            {
                cout << "Invalid input. Please enter a number between 1 and 4\n"
                     << "Select a starting point: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> start;
            }
            trip.setStart(start);
        }
        
        // Prompt the user for the ending city and stopover city if necessary.
        if (toupper(selection) == 'A')
        {
            cout << "Select a destination: ";
            cin >> end;
            
            // Check for invalid input. 
            while (cin.fail() || start < 1 || start > 4)
            {
                cout << "Invalid input. Please enter a number between 1 and 4\n"
                     << "Select a destination: ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> start;
            }
            trip.setEnd(end);
            
            cout << "Will you be making a stop (Y/N): ";
            cin >> choice;
            
            // Check for invalid input.
            while (cin.fail() || (toupper(choice) != 'Y' && toupper(choice) != 'N'))
            {
                cout << "Invalid input. Please enter either 'Y' or 'N': ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> choice;
            }
            if (toupper(choice) == 'Y')
            {
                cout << "Select a stop: ";
                cin >> stop;
                
                // Check for invalid input.
                while (cin.fail() || start < 1 || start > 4)
                {
                    cout << "Invalid input. Please enter a number between 1 and 4\n"
                         << "Select a stop: ";
                    cin.clear();
                    cin.ignore(256, '\n');
                    cin >> start;
                }
                trip.setStop(stop);
            }
        }
        // Call the mainMenu function.
        trip.mainMenu(trip);
        
        //Prompt the user to plan another trip.
        cout << "Would you like to plan another trip (Y/N)? ";
        cin >> cont;
        
        // check for invalid input.
        while (cin.fail() || (toupper(choice) != 'Y' && toupper(choice) != 'N'))
        {
            cout << "Invalid input. Please enter either 'Y' or 'N': ";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> choice;
        }
    } while (toupper(cont) == 'Y');

    cout << "\n\nThank you for using your Trip Planner.\nGOODBYE.";

    return 0;
}
