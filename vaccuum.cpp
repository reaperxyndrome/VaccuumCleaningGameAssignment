#include <iostream>

#define MY_NAME "Leon Jayakusuma"
#define MY_STUDENT_NUMBER "s4072726"
#define MY_EMAIL "s4072726@student.rmit.edu.au"

void show_student_info();

int main(void) {
   int input = 0;
   std::cout << "Welcome to the Vaccuum Cleaning Game!" << std::endl;
   std::cout << "--------------------" << std::endl;
   std::cout << "1. Play Game" << std::endl;
   std::cout << "2. Show student information" << std::endl;
   std::cout << "3. Quit" << std::endl << std::endl;
   std::cout << "Please enter your choice: ";
   std::cin >> input;
   if (input == 2) {
      show_student_info();
   } else if (input == 3){
      exit(EXIT_SUCCESS);
   }
   return EXIT_SUCCESS;
}

void show_student_info(){
   std::cout << std::endl;
   std::cout << "----------------------------------------" << std::endl;
   std::cout << "Name: " <<  MY_NAME << std::endl;
   std::cout << "Student ID: " << MY_STUDENT_NUMBER << std::endl;
   std::cout << "Email:" << MY_EMAIL << std::endl;
   std::cout << "----------------------------------------" << std::endl;
}


