#include "CLI.h"
#include <thread>
#include  <sstream>
#include <vector>

using namespace std;
//constructor of CLI by receiving DefaultIO
CLI::CLI(DefultIO *IO) {
    this->DIO = IO;
    HoldInfo *inf = new HoldInfo(IO);
    this->info = inf;
    func1 *func1_command = new func1(this->info);
    func2 *func2_command = new func2(this->info);
    func3 *func3_command = new func3(this->info);
    func4 *func4_command = new func4(this->info);
    func5 *func5_command = new func5(this->info);
    functions.insert(make_pair(1, func1_command));
    functions.insert(make_pair(2, func2_command));
    functions.insert(make_pair(3, func3_command));
    functions.insert(make_pair(4, func4_command));
    functions.insert(make_pair(5, func5_command));
}
//a function to show the menu by passing description.
int CLI::menu() {
    std::stringstream menu_options;
    menu_options << "Menu options:\n";
    for (auto f: functions) {
        menu_options << f.first << " . " << f.second->getDesctiption() << std::endl;
    }
    menu_options<<"8 . exit\n";
    std::string final_string = menu_options.str();
    DIO->write(final_string);
    string option = DIO->read();
    double d;
    int op;
    if (checkIsDouble(option, d)) //if the option is valid number
        op = std::stoi(option);
    else {
        op = 9;

    }
        return op;
}

void CLI::start() {
    int option;
    while (true) {
        option = this->menu();
        if (option == 8) {
            DIO->write("close");
            break;
        } else if (option <= 5 && option >= 1) {
            functions.find(option)->second->execute();
        } else {
            DIO->write("invalid input\n");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};
//destructor
CLI::~CLI() {
    delete this->info->getKNN();
    delete this->info->getDistanceMetrix();
    delete this->info;
    for (auto f: functions) {
        delete f.second;
    }
};
