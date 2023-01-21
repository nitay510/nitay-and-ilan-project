#include "CLI.h"
#include <thread>
#include  <sstream>
#include <vector>
using namespace std;
    CLI::CLI(DefultIO* IO){
    this->DIO=IO;
    HoldInfo* inf = new HoldInfo(IO);
    this->info = inf;
    func1* func1_command = new func1(this->info);
    func2* func2_command = new func2(this->info);
    func3* func3_command = new func3(this->info);
    func4* func4_command = new func4(this->info);
    func5* func5_command = new func5(this->info);
    functions.insert(make_pair(1, func1_command));
    functions.insert(make_pair(2, func2_command));
    functions.insert(make_pair(3, func3_command));
    functions.insert(make_pair(4, func4_command));
    functions.insert(make_pair(5, func5_command));
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
       functions.find(option)->second->execute();
      }
      else{
        DIO->write("invalid input\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
};
CLI::~CLI(){
  delete this->info;
  for(auto f : functions) {
    delete f.second;
  }
};
