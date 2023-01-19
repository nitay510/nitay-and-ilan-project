#include "CLI.h"
#include  <sstream>
#include "func1.h"
#include "func2.h"
#include "func3.h"
#include "func4.h"
#include "func5.h"
#include "func8.h"
#include <vector>
using namespace std;
CLI::CLI(DefultIO* IO){
    this->DIO=IO;
    EucDistance d;
    this->metrica = &d;
    this->K=5;
    func1* func1_command = new func1();
    func2* func2_command = new func2();
    func3* func3_command = new func3();
    func4* func4_command = new func4();
    func5* func5_command = new func5();
    func8* func8_command = new func8();
    functions.insert(make_pair(1, func1_command));
    functions.insert(make_pair(2, func2_command));
    functions.insert(make_pair(3, func3_command));
    functions.insert(make_pair(4, func4_command));
    functions.insert(make_pair(5, func5_command));
    functions.insert(make_pair(8, func8_command));
}
int CLI::menu(){
  std::stringstream menu_options;
  menu_options << "Menu options:\n";
  for(auto f : functions) {
      menu_options << f.first << " . " << f.second->getDesctiption() << std::endl;
  }
    std::string final_string = menu_options.str();
    DIO->write(final_string);
    string option =DIO->read(); //needs to take into account invalid input.
    double d;
    int op;
    if(checkIsDouble(option,d))
    op=std::stoi(option);
    else
    op=9;
    return op;
}
void CLI::start(){
int option;
    while(true)
    {
        option=this->menu();
        if(option==8)
        {
          DIO->write("close");
            break;
        }
        else if(option <= 5){
        DIO->write("valid option.");
       functions.find(option)->second->execute();
      }
      else{
        DIO->write("Invalid option.");
        functions.find(8)->second->execute();

    }
  }
};
CLI::~CLI(){
};
