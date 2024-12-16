#include "inputmodule.h"

void inputmodule::user_input(string userchoice[])
{
    system("CLS");
    cout << "\n\n                                             -------------------------------------        Welcome to Journey Guider       -------------------------------------" << endl;
    cout << endl;
    cout << "                 -------------------------------------" << endl;
    cout << "                 Please Enter Your City:";
    cin >> source;
    cout << "                 -------------------------------------" << endl;
    cout << "                 Please Enter Your Destination:";
    cin >> destination;
    cout << "                 -------------------------------------" << endl;
    userchoice[0] = source;
    userchoice[1] = destination;
}

string inputmodule::login()
{
    while (1)
    {
        cout << "\n\n                                             -------------------------------------        Welcome to Journey Guider       -------------------------------------" << endl;
        cout << "\n\n\n\n";
        cout << "                 SELECT                     " << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "                 -------------------------------------   1. To Log In                  -------------------------------------" << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "                 -------------------------------------   2. To Create A New Account     -------------------------------------" << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "\n                 Enter Your Choice:";
        int ch;
        bool res;
        filehandlingmodule fobj;
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("CLS");
            cout << "\n\n                                             -------------------------------------        Welcome to Journey Guider       -------------------------------------" << endl;
            cout << endl;
            cout << "                 -------------------------------------" << endl;
            cout << "                 Username:";
            cin >> username;
            cout << "                 -------------------------------------" << endl;
            cout << "                 Password:";
            cin >> password;
            cout << "                 -------------------------------------" << endl;
            res = fobj.log_in(username, password);
            break;
        case 2:
            system("CLS");
            cout << "\n\n                                             -------------------------------------        Welcome to Journey Guider       -------------------------------------" << endl;
            cout << endl;
            cout << "                 -------------------------------------" << endl;
            cout << "                 Username:";
            cin >> username;
            cout << "                 -------------------------------------" << endl;
            cout << "                 Password:";
            cin >> password;
            cout << "                 -------------------------------------" << endl;
            fobj.createaccount(username, password);
            break;
        }
        if (res == true)
            return username;
    }
}

int inputmodule::noofpassenger()
{
    int no;
    cout << endl
         << "                 How many passengers?";
    cin >> no;
    return no;
}
