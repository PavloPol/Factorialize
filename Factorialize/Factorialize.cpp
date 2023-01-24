// Factorialize.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

static string report_path = "report.txt";


int factorial(int number)
{
    if (number > 0)
        return number * factorial(number-1);
    return 1;
}


void write_report(string report)
{
    ofstream report_file(report_path, ios_base::app);
    time_t now = time(0);
    char str[26];
    ctime_s(str, sizeof str, &now);
    report_file << str << "Cannot open file: " << report << endl;
    report_file.close();
}


void factorialize(string input_path)
{
    ifstream input_file(input_path);
    if (!input_file.is_open())
    {
        input_file.close();
        cout << "Cannot open file: " << input_path << "\n";
        write_report(input_path);
        return;
    }
    ofstream output_file("output_from_"+input_path);

    int tmp;
    for (input_file >> tmp; !input_file.eof(); input_file >> tmp)
        output_file << factorial(tmp) << "\n";

    input_file.close();
    output_file.close();
}


int main()
{
    factorialize("input4.txt");
    factorialize("input1.txt");
    factorialize("input2.txt");
    factorialize("input3.txt");
}

