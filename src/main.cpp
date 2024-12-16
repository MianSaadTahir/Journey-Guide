#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 999999999
using namespace std;

struct CityData
{
    long long int cost[20];
    int array[20];
} journey[15];

struct InitialCosts
{
    long long int cost[20];
} ini[15];

class datamodule
{
public:
    string city[15];
    datamodule() : city{"London", "Paris", "New York", "Tokyo", "Sydney", "Rome", "Berlin", "Los Angeles", "Dubai", "Toronto", "Barcelona", "Moscow", "Madrid", "Seoul", "Cape Town"} {}

    void costdeclaration()
    {
        int N, i, j;
        N = 15;
        long long int arr[15][15] = {{0, 3500, 2000, INF, 1000, INF, INF, INF, INF, 7000, 4000, 1500, INF, 6500, INF},
                                     {3500, 0, INF, 1520, INF, INF, INF, 2500, INF, INF, INF, INF, INF, INF, 5000},
                                     {2000, INF, 0, 1500, INF, 3000, INF, INF, INF, INF, 2000, 1000, INF, INF, 1500},
                                     {INF, 1520, 1500, 0, INF, 1200, 4500, INF, 6000, INF, INF, INF, INF, INF, 1000},
                                     {1000, INF, INF, INF, 0, 1500, INF, INF, INF, INF, INF, INF, INF, INF, INF},
                                     {INF, INF, 3000, 1200, 1500, 0, 1950, INF, INF, INF, INF, INF, INF, INF, INF},
                                     {INF, INF, INF, 4500, INF, 1950, 0, INF, INF, 2050, INF, INF, INF, INF, INF},
                                     {INF, 2500, INF, INF, INF, INF, INF, 0, 5000, INF, INF, INF, INF, INF, INF},
                                     {INF, INF, INF, 6000, INF, INF, INF, 5000, 0, 7000, INF, INF, INF, INF, INF},
                                     {7000, INF, INF, INF, INF, INF, 2050, INF, 7000, 0, INF, INF, INF, INF, INF},
                                     {4000, INF, 2000, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF, INF},
                                     {1500, INF, 1000, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF, INF},
                                     {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF, INF},
                                     {6500, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0, INF},
                                     {INF, 5000, 1500, 1000, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, 0}};
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                journey[i].cost[j] = arr[i][j];
                journey[i].array[j] = j;
                ini[i].cost[j] = arr[i][j];
            }
        }
    }
};

class bellmanfordalgorithm : public datamodule
{
public:
    int N, i, j, k;
    bellmanfordalgorithm()
    {
        N = 15;
    }
    void algorithmic_implementation()
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                for (k = 0; k < N; k++)
                {
                    if (journey[i].cost[j] > journey[i].cost[k] + journey[k].cost[j])
                    {
                        // if low fare is found for the same origin and destination, the minimum possible fare is changed.
                        journey[i].cost[j] = journey[i].cost[k] + journey[k].cost[j];
                        journey[i].array[j] = k;
                    }
                }
            }
        }
    }

    void floydWarshall()
    {
        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (journey[i].cost[k] + journey[k].cost[j] < journey[i].cost[j])
                    {
                        journey[i].cost[j] = journey[i].cost[k] + journey[k].cost[j];
                        journey[i].array[j] = k;
                    }
                }
            }
        }
    }
};
class filehandlingmodule
{
public:
    string username1, password1;
    bool log_in(string username, string password)
    {
        ifstream fileread;
        fileread.open("login.txt");
        while (fileread >> username1 >> password1)
        {
            if ((username == username1) && (password == password1))
            {
                cout << endl
                     << "                 Successfully Logged Into Your Account..." << endl;
                return true;
            }
        }
        cout << endl
             << "                 Login Attempt Unsuccessful..." << endl;
        return false;
    }
    void createaccount(string username, string password)
    {
        ofstream filewrite;
        filewrite.open("login.txt", ios::app);
        filewrite << username << " " << password << "\n";
        filewrite.close();
        cout << endl
             << "                 Account Successfully Created ..." << endl;
    }
    void ticket(string username, string firstname[], string lastname[], string sex[], int age[], int no)
    {
        ofstream filewrite;
        filewrite.open("ticket.txt", ios::app);
        for (int i = 0; i < no; i++)
        {
            filewrite << username << " " << firstname[i] << " " << lastname[i] << " " << sex[i] << " " << age[i] << "\n";
        }
        filewrite.close();
    }
};

class inputmodule
{
public:
    string source, destination;
    string username, password;
    void user_input(string userchoice[])
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
    string login()
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
    int noofpassenger()
    {
        int no;
        cout << endl
             << "                 How many passengers?";
        cin >> no;
        return no;
    }
};

class outputmodule
{
public:
    string source, destination;
    void ticketHistory(string username)
    {
        ifstream file("ticket.txt");

        if (!file.is_open())
        {
            cout << "Error: Could not open the ticket history file." << endl;
            return;
        }

        string line;
        bool found = false;

        cout << "Ticket history for " << username << ": " << endl;

        while (getline(file, line))
        {
            // Check if the username exists as a separate word in the line
            if (line.find(username) != string::npos)
            {
                found = true;
                cout << line << endl; // Display the matching line
            }
        }

        if (!found)
        {
            cout << "No booking history found for " << username << "." << endl;
        }

        file.close();
    }

    void initial()
    {
        system("CLS");
        cout << "\n\n                                             -------------------------------------        Welcome to Journey Guider       -------------------------------------" << endl;
        cout << "\n\n";
        cout << "                 -------------------------------------" << endl;
        cout << "                 Available Facilities:  -------------------------------------" << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "\n\n";
        cout << "                 SELECT                     " << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "                 -------------------------------------   1. To Show List of Cities      -------------------------------------" << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "                 -------------------------------------   2. To Book A Ticket            -------------------------------------" << endl;
        cout << "                 -------------------------------------" << endl;
        cout << "                 -------------------------------------   3. To View Ticket History       -------------------------------------" << endl;
        cout << "                 -------------------------------------" << endl;
    }

    void list_cities(int N)
    {
        datamodule o;
        cout << endl;
        system("CLS");
        cout << "\n\n                                             -------------------------------------        Welcome to Journey Guider       -------------------------------------" << endl;
        cout << "\n\n";
        cout << "                 These are the available cities:" << endl;
        cout << "                 -------------------------------------" << endl;
        for (int i = 0; i < N; i++)
        {
            cout << "                 -------------------------------------          " << o.city[i] << "            " << endl;
            cout << "                 -------------------------------------" << endl;
        }
        cout << "                 -------------------------------------" << endl;
    }

    void ticket(int total_price, int no, string source, string destination, string username)
    {
        system("CLS");
        cout << "\n\n                                     -------------------------------------       E-TICKET       -------------------------------------" << endl;
        cout << endl
             << "                                     Ticket issued to :" << username << endl;
        cout << endl
             << "                                     From:" << source << endl;
        cout << endl
             << "                                     To:" << destination << endl;
        cout << endl
             << "                                     No. of Passengers:" << no << endl;
        cout << endl
             << "                                     Total Price:" << total_price << endl;
        cout << "\n\n                                     -------------------------------------" << endl;
    }

    void passengerdetailedticket(int no, string firstname[], string lastname[], string sex[], int age[])
    {
        for (int i = 0; i < no; i++)
        {
            cout << "                                     Passenger " << (i + 1) << " Information:" << endl
                 << endl;
            cout << "                                     First Name: " << firstname[i] << endl;
            cout << "                                     Last Name: " << lastname[i] << endl;
            cout << "                                     Gender: " << sex[i] << endl;
            cout << "                                     Age: " << age[i] << endl;
            cout << "\n\n                                     -------------------------------------" << endl;
        }
        int ch;
        cout << endl
             << "                                     Press 1 to proceed:";
        cin >> ch;
        if (ch == 1)
        {
            initial();
        }
    }

    int display_price(string source, string destination, int N, string username)
    {
        source = source;
        destination = destination;
        datamodule o;
        inputmodule in;
        int i, j, choiceofpassenger;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (source == o.city[i] && destination == o.city[j])
                {
                    cout << endl;
                    if (ini[i].cost[j] == INF)
                    {
                        cout << "                 No direct flight from " << source << " to " << destination << ". You can journey via other cities." << endl;
                        cout << "                 Price: " << journey[i].cost[j] << endl
                             << endl;
                        cout << "                 Suggested Route:" << source;
                        int c1 = i, c2 = j;
                        while (c1 != c2)
                        {
                            cout << "-->" << o.city[journey[c1].array[j]];
                            c1 = journey[c1].array[j];
                        }
                        cout << endl
                             << endl;
                    }
                    else if ((ini[i].cost[j] != INF) && (ini[i].cost[j] == journey[i].cost[j]))
                    {
                        cout << "                 Direct flight available from " << source << " to " << destination << " . And it's the cheapest option..." << endl;
                        cout << "                 Price: " << journey[i].cost[j] << endl;
                    }
                    else if ((ini[i].cost[j] != INF) && (ini[i].cost[j] > journey[i].cost[j]))
                    {
                        cout << "                 Direct flight available from " << source << " to " << destination << " ." << endl;
                        cout << "                 Price: " << ini[i].cost[j] << endl
                             << endl;
                        cout << "                 -------------------------------------" << endl
                             << endl;
                        cout << "                 You can take a cheaper route via other cities." << endl;
                        cout << "                 Price: " << journey[i].cost[j] << endl
                             << endl;
                        cout << "                 Suggested Route:" << source;
                        int c1 = i, c2 = j;
                        while (c1 != c2)
                        {
                            cout << "-->" << o.city[journey[c1].array[j]];
                            c1 = journey[c1].array[j];
                        }
                        cout << endl
                             << endl;
                        cout << "                 Press 1 for direct flight or Press 2 to go via other cities: ";
                        cin >> choiceofpassenger;
                    }
                    char c;
                    cout << endl;
                    cout << "                 Do you wish to continue (Y/N)?";
                    cin >> c;
                    if (c == 'Y')
                    {
                        int no = in.noofpassenger();
                        string *firstname = new string[no]; // Dynamic array for first names
                        string *lastname = new string[no];  // Dynamic array for last names
                        string *sex = new string[no];       // Dynamic array for sex
                        int *age = new int[no];             // Dynamic array for ages
                        delete[] firstname;                 // delete memory when done
                        delete[] lastname;
                        delete[] sex;
                        delete[] age;
                        for (int i = 0; i < no; i++)
                        {
                            cout << endl;
                            cout << "                 -------------------------------------" << endl;
                            cout << "                 Passenger " << (i + 1) << ":" << endl
                                 << endl;
                            cout << "                 First Name:";
                            cin >> firstname[i];
                            cout << endl
                                 << "                 Last Name:";
                            cin >> lastname[i];
                            cout << endl
                                 << "                 Gender(Male/Female/Other):";
                            cin >> sex[i];
                            cout << endl
                                 << "                 Age:";
                            cin >> age[i];
                        }
                        int total_price;
                        if (choiceofpassenger == 1)
                        {
                            total_price = no * ini[i].cost[j];
                        }
                        else
                        {
                            total_price = no * journey[i].cost[j];
                        }
                        cout << endl
                             << "                 The total cost is:" << total_price << endl;
                        char y;
                        cout << "                 Do you confirm your ticket (Y/N)?";
                        cin >> y;
                        if (y == 'Y')
                        {
                            filehandlingmodule f;
                            f.ticket(username, firstname, lastname, sex, age, no);
                            ticket(total_price, no, source, destination, username);
                            passengerdetailedticket(no, firstname, lastname, sex, age);
                        }
                        else
                        {
                            cout << endl
                                 << "                 Thanks for choosing us...";
                            cout << endl
                                 << "                 Do you wish to continue (Y/N)?";
                            char ch;
                            cin >> ch;
                            if (ch == 'Y')
                            {
                                initial();
                            }
                            return 0;
                        }
                    }
                    else
                    {
                        cout << endl
                             << "                 Thanks for choosing us...";
                        cout << endl
                             << "                 Do you wish to continue (Y/N)?";
                        char ch;
                        cin >> ch;
                        if (ch == 'Y')
                        {
                            initial();
                        }
                    }
                    return 0;
                }
            }
        }
        cout << "                 Sorry, no flights available between these cities..." << endl;
        cout << endl
             << "                 Do you wish to continue (Y/N)?";
        char ch;
        cin >> ch;
        if (ch == 'Y')
        {
            initial();
        }
        return 0;
    }
};

int main()
{
    int N = 15;

    // Creating object for datamodule class
    datamodule obj;
    obj.costdeclaration();

    // Creating object for bellmanfordalgorithm class
    bellmanfordalgorithm ob;
    ob.algorithmic_implementation();

    string userchoice[2];

    // Creating object for inputmodule class
    inputmodule obj1;

    // Login to get the username
    string username;
    username = obj1.login();

    // Creating object for outputmodule
    outputmodule object;

    // Display the initial menu
    object.initial();

    while (1)
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

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }

    return 0;
}