#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
//ROOT Macro to convert input txt files to vectors. Contains two functions to keep ROOT happy.
//Author: Love Kildetoft
std::vector<double> temp(){
    std::string tEntry; //Temporary string
    std::ifstream tempFile;
    tempFile.open("/meanT_Falun.txt"); //open file
    
    std::vector<double> tempVec;
    //Loop over file line by line and push to vector.
    if (tempFile.is_open()) {
        while (std::getline(tempFile, tEntry)) {
            tempVec.push_back(std::stod(tEntry));
        }
    };
    return tempVec;
};

std::vector<int> date(){
    std::string dEntry;
    std::ifstream dateFile;
    dateFile.open("/meanY_Falun.txt");
    
    std::vector<int> dateVec;
    if (dateFile.is_open()) {
        while (std::getline(dateFile, dEntry)) {
            dateVec.push_back(std::stoi(dEntry));
        }
    };
    return dateVec;
};
