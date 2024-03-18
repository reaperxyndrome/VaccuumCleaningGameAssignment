#include "helper.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

Helper::Helper(){}

void Helper::printInvalidInput()
{
    std::cout << std::endl;
    std::cout << "Invalid input" << std::endl << std::endl;
}

// This below function does not comply to our C++ Style Guide, 
// as it uses the banned keyword "break" twice. The marker will 
// not deduct marks in this case if you use this function, though
// this is not ideal. Nevertheless, feel free to revise this 
// function to make it complied to style guide (this is optional). 
bool Helper::isNumber(string s)
{
    string::const_iterator it = s.begin();
    char dot = '.';
    int nb_dots = 0;
    while (it != s.end()) 
    {
        if (*it == dot)
        {
            nb_dots++;
            if (nb_dots>1)
            {
                break;
            }
        }   
        else if (!isdigit(*it))
        {
            break;
        } 

        ++it;
    }
    return !s.empty() && s[0] != dot && it == s.end();
}

void Helper::splitString(string s, vector<string>& tokens, string delimeter)
{
    tokens.clear();
    char* _s = new char[s.length()+1];
    strcpy(_s, s.c_str());

    char * pch;
    pch = strtok (_s, delimeter.c_str());
    while (pch != NULL)
    {
        tokens.push_back(pch);
        pch = strtok (NULL, delimeter.c_str());
    }
    delete[] _s;
}

string Helper::readInput()
{
    string input;
    std::getline(std::cin >> std::ws, input);
    std::cout << std::endl;

    return input;
}

void Helper::showMainMenu(){
   cout << "Welcome to the Vaccuum Cleaning Game!" << endl;
   cout << "--------------------" << endl;
   cout << "1. Play Game" << endl;
   cout << "2. Show student information" << endl;
   cout << "3. Quit" << endl << endl;
}

void Helper::showStudentInfo(){
   cout << "----------------------------------------" << endl;
   cout << "Name: " <<  MY_NAME << endl;
   cout << "Student ID: " << MY_STUDENT_NUMBER << endl;
   cout << "Email:" << MY_EMAIL << endl;
   cout << "----------------------------------------" << endl << endl;
}

void Helper::showGameCommandsEmpty(){
    cout << "At this stage of the program, only two commands are acceptable:" << endl;
    cout << "load <g>" << endl;
    cout << "quit" << endl << endl;
}

void Helper::showGameCommandsLoaded(){
    cout << "At this stage of the program, only three commands are acceptable:" << endl;
    cout << "load <g>" << endl;
    cout << "init <x>,<y>,<direction>" << endl;
    cout << "quit" << endl << endl;
}

void Helper::showGameCommandsInitialized(){
    cout << "At this stage of the program, only four commands are acceptable:" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl << endl;

}

void Helper::showAllGameCommands(){
    cout << "You can use the following commands to play the game:" << endl << endl;
    cout << "load <g>" << endl;
    cout << "\tg: number of the game board to load" << endl;
    cout << "init <x>,<y>,<direction>" << endl;
    cout << "\tx: horizontal position of the vacuum cleaner in the room (between 0 & 9)" << endl;
    cout << "\ty: vertical position of the vacuum cleaner in the room (between 0 & 9)" << endl;
    cout << "\tdirection: direction of the vacuum cleaner’s movement (north, east, south, west)" << endl;
    cout << "forward (or f)" << endl;
    cout << "turn_left (or l)" << endl;
    cout << "turn_right (or r)" << endl;
    cout << "quit" << endl;
}