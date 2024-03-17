#include <iostream>
#include "board.h"
#include "player.h"
#include "helper.h"
#include "game.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void showTutorial();
void menuInputEmpty(Board* board, Player* player);
std::string menuInputLoaded(Board* board, Player* player);

int main(void) {
   int option = 0;
   Game game;
   while(true){
      Helper::showMainMenu();
      cout << "Please enter your choice: " << endl;
      option = stoi(Helper::readInput());
      if (option == 1) {
         // showTutorial();
         game.start();
      } else if (option == 2) {
         Helper::showStudentInfo();
      } else if (option == 3){
         exit(EXIT_SUCCESS);
      }
   }
   return EXIT_SUCCESS;
}

void showTutorial(){
   Player player = Player();
   Board board = Board();
   Helper::showAllGameCommands();
   cout << "Press enter or space to continue..." << endl;

   string input;
   cin.ignore();
   
   cout << "The game board is displayed below: " << endl << endl;
   board.display(&player);
   Helper::showGameCommandsEmpty();
   menuInputEmpty(&board, &player);
}

void menuInputEmpty(Board* board, Player* player){
   string command = " ";
   while (command != "quit"){
      cin >> command;   
      if (command == "load"){
         string boardId;
         cin >> boardId;
         bool boardIdValid = Helper::isNumber(boardId) && 
                              (boardId == "1" || boardId == "2");
         if (boardIdValid){
            board->load(stoi(boardId));
            cout << "The game board is displayed below: " << endl << endl;
            board->display(player);
            Helper::showGameCommandsLoaded();
            command = menuInputLoaded(board, player);
         }
         else{
            Helper::printInvalidInput();
            Helper::showGameCommandsEmpty();   
         }
      } else {
         if (command != "quit"){
            Helper::printInvalidInput();
            Helper::showGameCommandsEmpty();
         }
      }
   }
}

std::string menuInputLoaded(Board* board, Player* player){
   string command = " ";
   while (command != "quit"){
      cin >> command;
      if (command == "load"){
         string boardId;
         cin >> boardId;
         bool boardIdValid = Helper::isNumber(boardId) && 
                              (boardId == "1" || boardId == "2");
         if (boardIdValid){
            board->load(stoi(boardId));
            cout << "The game board is displayed below: " << endl << endl;
            board->display(player);
            Helper::showGameCommandsLoaded();
         }
         else {
            Helper::printInvalidInput();
            Helper::showGameCommandsLoaded();   
         }
      } else {
         if (command != "quit"){
            Helper::printInvalidInput();
            Helper::showGameCommandsLoaded();
         }
      }
   }
   return command;
}