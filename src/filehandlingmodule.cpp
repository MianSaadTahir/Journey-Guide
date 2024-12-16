#include "filehandlingmodule.h"

bool filehandlingmodule::log_in(string username, string password)
{
    ifstream fileread;
    fileread.open("data/login.txt"); // Make sure the path is correct for the new file location
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

void filehandlingmodule::createaccount(string username, string password)
{
    ofstream filewrite;
    filewrite.open("data/login.txt", ios::app); // Ensure the path matches
    filewrite << username << " " << password << "\n";
    filewrite.close();
    cout << endl
         << "                 Account Successfully Created ..." << endl;
}

void filehandlingmodule::ticket(string username, string firstname[], string lastname[], string sex[], int age[], int no)
{
    ofstream filewrite;
    filewrite.open("data/ticket.txt", ios::app); // Ensure the path matches
    for (int i = 0; i < no; i++)
    {
        filewrite << username << " " << firstname[i] << " " << lastname[i] << " " << sex[i] << " " << age[i] << "\n";
    }
    filewrite.close();
}
