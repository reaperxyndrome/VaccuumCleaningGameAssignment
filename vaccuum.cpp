#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#define MY_NAME "Leon Jayakusuma"
#define MY_STUDENT_NUMBER "s4072726"
#define MY_EMAIL "s4072726@student.rmit.edu.au"

void play_game();
void show_student_info();
void show_main_menu();

int main(void) {
   int input = 0;
   show_main_menu();
   while(input != 1){
      cout << "Please enter your choice: ";
      cin >> input;
      cout << endl;
      if (input == 1) {
         play_game();
      } else if (input == 2) {
         show_student_info();
      } else if (input == 3){
         exit(EXIT_SUCCESS);
      }
   }
   return EXIT_SUCCESS;
}


void show_main_menu(){
   cout << "Welcome to the Vaccuum Cleaning Game!" << endl;
   cout << "--------------------" << endl;
   cout << "1. Play Game" << endl;
   cout << "2. Show student information" << endl;
   cout << "3. Quit" << endl << endl;
}

void show_student_info(){
   cout << "----------------------------------------" << endl;
   cout << "Name: " <<  MY_NAME << endl;
   cout << "Student ID: " << MY_STUDENT_NUMBER << endl;
   cout << "Email:" << MY_EMAIL << endl;
   cout << "----------------------------------------" << endl << endl;
}

void play_game(){
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

