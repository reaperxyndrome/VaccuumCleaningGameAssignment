#include <iostream>
#include "board.h"
#include "player.h"
#include "helper.h"
#include "game.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// Function prototypes for tutorial and menu input handling
void showTutorial();
void menuInputEmpty(Board* board, Player* player);
std::string menuInputLoaded(Board* board, Player* player);

int main(void) {
   // User's menu choice and Game instance initialization
   int option = 0;
   Game game;

   // Main game loop
   while(true){
      // Display the main menu and get user's menu choice
      Helper::showMainMenu();
      cout << "Please enter your choice: " << endl;
      string input = Helper::readInput();
      
      // Process user's input, proceed if valid
      if(Helper::isNumber(input)){
         option = stoi(input);

         // Start the game, show student info, or exit based on user's choice
         if (option == 1) {
            game.start();
         } else if (option == 2) {
            Helper::showStudentInfo();
         } else if (option == 3){
            exit(EXIT_SUCCESS);
         }
      }
   }
   return EXIT_SUCCESS;
}
