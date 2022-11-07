#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

std::vector<double> temp(){
    std::string tEntry;
    std::ifstream tempFile;
    tempFile.open("/Users/marwan/Desktop/Arkiv-2/medianT_Karlstad.txt");
    
    std::vector<double> tempVec;
    if (tempFile.is_open()) {
        while (std::getline(tempFile, tEntry)) {
            tempVec.push_back(std::stod(tEntry));
        }
    };
    return tempVec;
};

std::vector<double> err(){
    std::string eEntry;
    std::ifstream eFile;
    eFile.open("/Users/marwan/Desktop/Arkiv-2/medErr_Karlstad.txt");
    
    std::vector<double> eVec;
    if (eFile.is_open()) {
        while (std::getline(eFile, eEntry)) {
            eVec.push_back(std::stod(eEntry));
        }
    };
    return eVec;
};

std::vector<int> date(){
    std::string dEntry;
    std::ifstream dateFile;
    dateFile.open("/Users/marwan/Desktop/Arkiv-2/medianY_Karlstad.txt");
    
    std::vector<int> dateVec;
    if (dateFile.is_open()) {
        while (std::getline(dateFile, dEntry)) {
            dateVec.push_back(std::stoi(dEntry));
        }
    };
    return dateVec;
};
