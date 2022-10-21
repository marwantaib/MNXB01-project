//
//  DataProcessor.cpp
//  DataProcessor
//
//  Created by Love Kildetoft on 2022-10-19.
//

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "DataProcessor.h"

std::vector<std::string> DataProcessor::parseToVector() {
    std::vector<std::string> vec;
    std::string entry;
    std::ifstream inFile;
    inFile.open(_fname);
    
    try {
        if (inFile.is_open()) {
            while (std::getline(inFile, entry)) {
                vec.push_back(entry);
            }
        } else {
            throw std::runtime_error("File not open");
        }
    } catch (std::runtime_error& err) {
        err.what();
    }
    
    inFile.close();
    return vec;
};
