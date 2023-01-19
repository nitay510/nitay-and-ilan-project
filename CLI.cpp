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
     std::cout << f.second->description << std::endl;
      menu_options << f.first << " . " << f.second->description << std::endl;
  }
  std::string final_string = menu_options.str();

  DIO->write(final_string);
    string option =DIO->read(); //needs to take into account invalid input.
    auto it = functions.find(std::stoi(option));
    if(it != functions.end()){
        it->second->execute();
    }else{
        DIO->write("Invalid option.");
    }
    return std::stoi(option);
}
void CLI::start(){

    while(true)
    {
        int option=this->menu();
        if(option==8)
        {
            break;
        }
       functions.find(option)->second->execute();
    }
};
CLI::~CLI(){
};
