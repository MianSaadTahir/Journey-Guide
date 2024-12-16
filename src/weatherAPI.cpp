#include <iostream>
#include <string>
#include <windows.h> // Required for Windows-specific functionality
#include <wininet.h> // Required for WinINet API

using namespace std;

string fetchWeatherData(const string &city, const string &apiKey)
{
    HINTERNET hInternet, hConnect;
    DWORD bytesRead;
    char buffer[4096];
    string result = "";

    // Initialize WinINet
    hInternet = InternetOpenA("WeatherApp", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0); // Use InternetOpenA for char-based
    if (hInternet == NULL)
    {
        cerr << "InternetOpen failed!" << endl;
        return "";
    }

    // Open connection to OpenWeatherMap API
    string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
    hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0); // Use InternetOpenUrlA for char-based
    if (hConnect == NULL)
    {
        cerr << "InternetOpenUrlA failed!" << endl;
        InternetCloseHandle(hInternet);
        return "";
    }

    // Read the response
    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0)
    {
        result.append(buffer, bytesRead);
    }

    // Close handles
    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return result;
}

void displayWeatherInfo(const string &weatherData)
{
    if (weatherData.find("weather") != string::npos && weatherData.find("main") != string::npos)
    {
        size_t tempPos = weatherData.find("\"temp\":") + 7;
        size_t tempEndPos = weatherData.find(",", tempPos);
        string temperature = weatherData.substr(tempPos, tempEndPos - tempPos);

        size_t descPos = weatherData.find("\"description\":") + 15;
        size_t descEndPos = weatherData.find("\"", descPos);
        string description = weatherData.substr(descPos, descEndPos - descPos);

        cout << "Weather Description: " << description << endl;
        cout << "Temperature: " << temperature << "°C" << endl;
    }
    else
    {
        cout << "Failed to parse weather data!" << endl;
    }
}

int main()
{
    string apiKey = "890309d8b37eda48a5d90d9dc1fdb528"; // Replace with your actual OpenWeatherMap API key
    string city = "Paris";                              // Example city to fetch weather data for

    // Fetch weather data
    string weatherData = fetchWeatherData(city, apiKey);

    // Check if the data was fetched
    if (!weatherData.empty())
    {
        cout << "Fetched weather data: " << endl;
        displayWeatherInfo(weatherData);
    }
    else
    {
        cout << "Failed to fetch weather data." << endl;
    }

    // Pause the console window before closing
    system("pause");

    return 0;
}
