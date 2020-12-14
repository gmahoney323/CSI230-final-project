//csvhelper.h
//author: Grant Mahoney
//date: 12/12/2020
//desc: contributes the includes necessary for the program as well as function definitions

#ifndef CSVHELPER_H
#define CSVHELPER_H

#include <string>
#include <fstream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <tuple>

//processes the given CSV file into their respective values
int csvhelper(std::ifstream& inFile, std::string csvFileName);
void sortCSV(std::ofstream& outFile, std::string outFileName, std::string sortMethod);

#endif