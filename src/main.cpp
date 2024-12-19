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

    datamodule obj;
    obj.costdeclaration();

    bellmanfordalgorithm ob;
    ob.algorithmic_implementation();

    string userchoice[2];

    inputmodule obj1;

    string username;
    username = obj1.login();

    outputmodule object;

    object.initial();

    while (true)
    {
        int choice;
        cout << "\n                 Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            object.list_cities(N);
            cout << "\n\n                 Press 1 to Continue...";
            int cont;
            cin >> cont;
            if (cont == 1)
            {
                object.initial();
            }
            break;

        case 2:
            obj1.user_input(userchoice);
            object.display_price(userchoice[0], userchoice[1], N, username);
            break;

        case 3:
            object.ticketHistory(username);
            break;

        case 4:
            cout << "Exiting the application. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}
