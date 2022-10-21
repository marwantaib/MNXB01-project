//
//  DataProcessor.h
//  DataProcessor
//
//  Created by Love Kildetoft on 2022-10-19.
//
#include <string>
#include <vector>
#include <stdexcept>

#ifndef DataProcessor_h
#define DataProcessor_h

class DataProcessor {
public:
    DataProcessor(std::string fname) :
    _fname(fname) {
        try {
            if (_fname.substr(_fname.find_last_of(".") + 1) != "txt") {
                throw std::invalid_argument("Input recieved is not a .txt file");
            }
        } catch (std::invalid_argument& err) {
            std::cout << err.what() << std::endl;
        }
    }
    std::vector<std::string> parseToVector();
public:
    std::string _fname;
};
    

#endif /* DataProcessor_h */
