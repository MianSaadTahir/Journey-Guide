#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "datamodule.h"
#include "bellmanford.h"
#include "filehandlingmodule.h"
#include "inputmodule.h"
#include "outputmodule.h"

#define INF 999999999
using namespace std;

int main()
{
    int N = 15;

    // Creating object for datamodule class
    datamodule obj;
    obj.costdeclaration(); // Initializes the cost data for cities

    // Creating object for bellmanfordalgorithm class
    bellmanfordalgorithm ob;
    ob.algorithmic_implementation(); // Run the Bellman-Ford algorithm for shortest paths

    string userchoice[2];

    // Creating object for inputmodule class
    inputmodule obj1;

    // Login to get the username
    string username;
    username = obj1.login(); // Login function returns the username

    // Creating object for outputmodule
    outputmodule object;

    // Display the initial menu
    object.initial();

    while (true)
    {
        int choice;
        cout << "\n                 Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            object.list_cities(N); // Show the list of cities
            cout << "\n\n                 Press 1 to Continue...";
            int cont;
            cin >> cont;
            if (cont == 1)
            {
                object.initial(); // Show the initial menu again
            }
            break;

        case 2:
            obj1.user_input(userchoice); // Collect source and destination from the user
            // Passing user inputted source and destination to display_price function
            object.display_price(userchoice[0], userchoice[1], N, username);
            break;

        case 3:
            object.ticketHistory(username); // View ticket history for the logged-in user
            break;

        case 4:
            cout << "Exiting the application. Goodbye!" << endl;
            return 0; // Exit the program

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}
