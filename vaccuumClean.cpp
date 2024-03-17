#include <iostream>
#include "board.h"
#include "player.h"
#include "helper.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void showTutorial();
void menuInputEmpty(Board* board, Player* player);

int main(void) {
   int option = 0;
   while(true){
      Helper::showMainMenu();
      cout << "Please enter your choice: " << endl;
      option = stoi(Helper::readInput());
      if (option == 1) {
         showTutorial();
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
   string command;
   cin >> command;
   while (command != "quit"){   
      if (command == "load"){
         string boardId;
         cin >> boardId;
         bool boardIdValid = Helper::isNumber(boardId) && 
                              (boardId == "1" || boardId == "2");
         if (boardIdValid){
            board->load(stoi(boardId));
            cout << "The game board is displayed below: " << endl << endl;
            board->display(player);
         }
         else{
            Helper::printInvalidInput();
            Helper::showGameCommandsEmpty();   
         }
      } else {
         Helper::printInvalidInput();
         Helper::showGameCommandsEmpty();
      }
      cin >> command;
   }
}