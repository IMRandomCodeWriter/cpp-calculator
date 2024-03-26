#include <fstream>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cstdio>
#include <cmath>

std::vector<double> getHistory() //the function that is used to get all the numbers from the history file
{
    std::ifstream file("history.txt");
    std::vector<double> history;
    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty() && line != "\n")
        {
            history.push_back(std::stof(line));
        }
    }

    if (history.empty()){history.push_back(0.0);}

    return history;
}

bool isNumber(char c) //checks if char is a number
{
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

std::string convertNumbersToFloat(std::string string) // converts all numbers from int to double by adding .0 to number if necessary
{
    std::string newString;

    bool inNum = false;
    bool hasDot = false;

    for (int i = 0; i < string.size(); i++)
    {
        if (i == 15)
        {
            int anus = 2;
            anus++;
        }

        newString += string[i];

        if (i != string.size() && (string[i + 1] == '.' || string[i + 1] == ',')) // if next character is a dot 
        {
            inNum = true;
            hasDot = true;
        }

        if (isNumber(string[i])) // if i char is number
        {
            inNum = true;

            if (i == string.size() && !hasDot) // if its last character and number hasnt dot
            {
                newString += ".0";

                hasDot = false;
                inNum = false;
            }
            else if (!isNumber(string[i + 1]) && (string[i + 1] != '.' || string[i + 1] != ',') && !hasDot) // if next character isnt number or isnt dot and number hasnt dot
            {
                newString += ".0";

                hasDot = false;
                inNum = false;
            }
        }
        else if (string[i] != '.' && string[i] != ',') // if i char isnt dot
        {
            inNum = false;
            hasDot = false;
        }
    }

    return newString;
}

double calculate(std::string expression)
{
    std::ofstream file("calculator.cpp");
    while (file.is_open())
    {
        file << "#include <fstream>\n";
        file << "#include <string>\n";
        file << "#include <cmath>\n";
        file << "#define pi 3.14159265358979323846\n";
        file << "int main(){ std::ofstream file(\"history.txt\", std::ios::app); file << std::to_string(";
        file << convertNumbersToFloat(expression); //main part that use c++ compiler to calculate expression
        file << "); file << std::endl; file.close(); return 0; }";

        file.close();
    }

    int exitCode = system("g++ calculator.cpp");

    if (exitCode == 0)
    {
        double historyBack = getHistory().back();

        system("start a.exe");
        

        while (historyBack == getHistory().back()){} //waiting for the result by checking the end of the history file

        std::ofstream("calculator.cpp");
        remove("a.exe");

        return getHistory().back();
    }
    else// stupid code part
    {
        std::cout << "\n" << "Error: please enter only correct symbols(1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, +, /, *, (, ), %)" << "\n";

        std::ofstream("calculator.cpp");

        return 0.0;
    }
}

void runCommand(std::string command)
{
    if (command == "~ch")
    {
        std::ofstream("history.txt");
        std::cout << "\n\nhistory cleared\n\n";
    }
    else if (command == "~ph")
    {
        std::vector<double> history = getHistory();

        std::cout << "\n\ncalculator results history:\n";

        for (size_t i = 0; i < history.size(); i++)
        {
            std::cout << "\t" << i << " result: " << history[i] << "\n";
        }

        std::cout << "\n\n";
    }
    else if (command == "~exit")
    {
        exit(0);
    }
    else if (command == "~help")
    {
        std::cout << "\n\n\n\tWelcome to C++ calculator\nto calculate expression just enter it\nalso you can use commands\nall commands list : \n\t~ch - clear history\n\t~ph - print history\n\t~exit - exits the app\n\t~help - print all info about calculator\n\t~cls - clear console\n\n";
    }
    else if(command == "~cls")
    {
        system("cls");
    }
    else
    {
        std::cout << "Error: Unknown command\n";
    }
}

int main()
{
    std::string input;

    runCommand("~help");// run help command for printing welcome message

    while (true)
    {
        std::cout << "Enter the command or expression: ";
        std::getline(std::cin, input);

        if (input[0] == '~')
        {
            runCommand(input);
        }
        else
        {
            std::cout << calculate(input) << "\n";
        }
    }
    return 0;
}