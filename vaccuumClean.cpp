#include <iostream>
#include "board.h"
#include "player.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

#define MY_NAME "Leon Jayakusuma"
#define MY_STUDENT_NUMBER "s4072726"
#define MY_EMAIL "s4072726@student.rmit.edu.au"

void show_tutorial();
void show_all_game_commands();
void show_game_commands_empty();
void menu_input_empty(string command, Board* board, Player* player);
void show_student_info();
void show_main_menu();

int main(void) {
   int input = 0;
   bool return_to_main = false;
   show_main_menu();
   while(input != 1 || !return_to_main){
      cout << "Please enter your choice: ";
      cin >> input;
      cout << endl;
      if (input == 1) {
         show_tutorial();
      } else if (input == 2) {
         show_student_info();
      } else if (input == 3){
         exit(EXIT_SUCCESS);
      }
   }
   return EXIT_SUCCESS;
}

// TODO: change "quit" to return to main menu instead of exit the program
void show_tutorial(){
   Player player = Player();
   Board board = Board();
   show_all_game_commands();
   cout << "Press enter or space to continue...";

   string input;
   cin.ignore();
   std::getline(cin, input);
   cout << endl;
   
   cout << "The game board is displayed below: " << endl << endl;
   board.display(&player);
   show_game_commands_empty();
   
   string command = " ";
   while (command != "quit" || command != "load"){
      cin >> command;
      menu_input_empty(command, &board, &player);
   }
}

void menu_input_empty(string command, Board* board, Player* player){
   if (command == "load"){
      string boardId;
      cin >> boardId;
      if (Helper::isNumber(boardId)){
         board->load(stoi(boardId));
         cout << "The game board is displayed below: " << endl << endl;
         board->display(player);
      }
   } else if (command == "quit"){
      exit(EXIT_SUCCESS);
   } else {
      cout << "Invalid input" << endl;
      show_game_commands_empty();
   }
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

void show_all_game_commands(){
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

void show_game_commands_empty(){
   cout << "At this stage of the program, only these commands are acceptable:" << endl;
   cout << "load <g>" << endl;
   cout << "quit" << endl << endl;
}