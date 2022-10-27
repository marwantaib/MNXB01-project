#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

//ROOT Macro to convert input txt files to vectors
//Author: Love Kildetoft
std::vector<double> parseToVec(std::string fname){
    std::string tEntry; //Temporary string
    std::ifstream tempFile; //Open file
    tempFile.open("/meanT_Falun.txt");
    
    std::vector<double> vec;
    //Read file line by line and push back to vector
    if (tempFile.is_open()) {
        while (std::getline(tempFile, tEntry)) {
            tempVec.push_back(std::stod(tEntry));
        }
    };
    return vec;
};
