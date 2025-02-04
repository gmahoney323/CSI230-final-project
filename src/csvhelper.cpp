//csvhelper.cpp
//author: Grant Mahoney
//date: 12/12/2020
//with help from: geeks4geeks.com
//https://www.geeksforgeeks.org/sorting-vector-tuple-c-ascending-order/
//desc: parses the CSV file as well as handling sorting


#include "csvhelper.h"
#include <iostream>
#include <sstream>

//vector that stores all of the information from the CSV file
//tuple holds strings (name of the item), ints (quantity), and float(price)
std::vector<std::tuple<std::string, int, float>> tupes;

//parses CSV files and puts them in the tupes vector
int csvhelper(std::ifstream& inFile, std::string csvFileName)
{
    using boost::lexical_cast;
    using boost::bad_lexical_cast;
    
    std::string strName, strQuantity, strPrice;
    std::string strLine;
    int recordCount{};

    if(inFile)
    {
        //removes first line of CSV from processing
        getline(inFile, strLine);

        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            std::getline(s_stream, strName, ',');
            std::getline(s_stream, strQuantity, ',');
            std::getline(s_stream, strPrice, ',');
            //made prices into integers, as the game uses gold currency
            //in the game, there is no such thing as half a gold piece
            strPrice = strPrice.substr(0, strPrice.find("."));

            int quant = boost::lexical_cast<int>(strQuantity);
            int price = std::stoi(strPrice, nullptr, 10);

            tupes.push_back(std::tuple<std::string, int, float>(strName, quant, price));
            //debug cout
            //std::cout << "Name: " << std::get<0>(tupes[recordCount]) << "\n" << "Quantity: " << std::get<1>(tupes[recordCount]) << "\n" << "Price: " << std::get<2>(tupes[recordCount]) << "\n\n";
            recordCount++;
        }
    }
    return recordCount;
}


//sorts and outputs to the desired output file
//the method by which the data is sorted is determined by the -s flag --- name, quantity, price
//the output file is specified by the -o flag
//used help with sorting vectors of tuple from:
//https://www.geeksforgeeks.org/sorting-vector-tuple-c-ascending-order/

//quantity sort helper function
bool sortByQuantity(const std::tuple<std::string, int, float>& lhs, const std::tuple<std::string, int, float>& rhs)
{
    return std::get<1>(lhs) < std::get<1>(rhs);
}

//price sort helper function
bool sortByPrice(const std::tuple<std::string, int, float>& lhs, const std::tuple<std::string, int, float>& rhs)
{
    return std::get<2>(lhs) < std::get<2>(rhs);
}

//master sorting function
void sortCSV(std::ofstream& outFile, std::string outFileName, std::string sortMethod)
{
    if(sortMethod=="quantity")
    {
        std::sort(tupes.begin(), tupes.end(), sortByQuantity);
    }
    else if(sortMethod=="price")
    {
        std::sort(tupes.begin(), tupes.end(), sortByPrice);
    }
    else
    {
        std::sort(tupes.begin(), tupes.end());
    }

    //reverse the output, as std::sort() sorts in ascending order by default.
    //descending order is much more helpful in this scenario
    std::reverse(tupes.begin(), tupes.end());

    //outputs each tuple on its own line in the output file
    for(int i = 0; i < tupes.size(); i++)
    {
        outFile << std::get<0>(tupes[i]) << " " << std::get<1>(tupes[i]) << " " << std::get<2>(tupes[i]) << "\n";
    }

}
