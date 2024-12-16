#include "outputmodule.h"
#include "datamodule.cpp"

void outputmodule::ticketHistory(string username)
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
        if (line.find(username) != string::npos)
        {
            found = true;
            cout << line << endl;
        }
    }

    if (!found)
    {
        cout << "No booking history found for " << username << "." << endl;
    }

    file.close();
}

void outputmodule::initial()
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

void outputmodule::list_cities(int N)
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

void outputmodule::ticket(int total_price, int no, string source, string destination, string username)
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

void outputmodule::passengerdetailedticket(int no, string firstname[], string lastname[], string sex[], int age[])
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

int outputmodule::display_price(string source, string destination, int N, string username)
{
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
                }
            }
        }
    }
    return 0;
}
