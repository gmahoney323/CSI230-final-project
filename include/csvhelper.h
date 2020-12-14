//csvhelper.h
//author: Devin Paden
//edited by: Grant Mahoney
//date: 11/11/2020

#ifndef CSVHELPER_H
#define CSVHELPER_H

#include <string>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <tuple>



//processes the given CSV file into their respective values
int csvhelper(std::ifstream& inFile, std::string csvFileName);
void sortCSV(std::ofstream& outFile, std::string outFileName, std::string sortMethod);

#endif