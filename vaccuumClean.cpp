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
