#include <sstream>
#include <fstream>
#include "func5.h"
#include <thread>
#include <mutex>
#include <experimental/filesystem>
func5::func5(HoldInfo* inf){
    this->inf = inf;
}
std::string func5::getDesctiption(){
    return this->description;
}
void func5::execute() {
    if(!this->inf->haveFiles()){
        this->inf->write("please upload data\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return;
    }
    if(!this->inf->classifyFiles()){
        this->inf->write("please classify the data\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return;
    }
    std::stringstream mapS;
    this->inf->write("start func 5");
    int i = 1;
    for (auto str :this->inf->getPredictList()) {
        mapS << i << "." << str<< std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        i++;
    }
    std::string localPath;
    this->inf->write("Enter a local path: \n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    localPath=this->inf->read();
    //check if the address is valid before creating a file
    std::ifstream file(localPath);
    if(!file.good()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        this->inf->write("Invalid input\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        return;
    }
    file.close();
    std::thread t1([this, &localPath, &mapS](){this->download(localPath, mapS.str());});
    // create new thread and run function1 in it
    t1.detach();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    this->inf->write("Done\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
void func5::download(string localPath,string mapS){
   //created empty file name outputFile.txt
    std::ofstream file;
    file.open(localPath + "outputFile.txt", std::ios::trunc);
    if(file.is_open()) {
        // file is open
        file.close();
    }
    std::ofstream file2;
    file2.open(localPath + "outputFile.txt", std::ios::trunc);
    if(file2.is_open()) {
        file2 << mapS;
        file2.close();
    } else {
        // file is not open
    }
}

//datasets/iris/iris_classified.csv
//datasets/iris/iris_Unclassified.csv
//C:/Users/ilan talala/Documents/GitHub/nitay-and-ilan-last-mission