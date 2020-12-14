#include <iostream>
#include "csvhelper.h"

using namespace std;

int main(int argc, char* argv[])
{
    //args
    int opt{};
    bool csvFlag{false};
    bool sortFlag{false};
    bool outFlag{false};

    //csv filename
    string csvValue;
    //sort type
    string sortValue;
    //output filename
    string outValue;
    bool optErr=true;

    while((opt = getopt(argc, argv, "c:s:o:")) != EOF)
    {
        switch(opt)
        {
            case 'c':
                csvFlag = true;
                csvValue = optarg;
                break;
            case 's':
                sortFlag = true;
                sortValue = optarg;
                std::cout << sortValue << std::endl;
                break;
            case 'o':
                outFlag = true;
                outValue = optarg;
                break;
            default:
                optErr = true;
                break;
        }
    }

    if(csvFlag && sortFlag && outFlag)
    {
        cout << "flags set!" << endl;
        if(sortValue.compare("name")==0 || sortValue.compare("quantity")==0 || sortValue.compare("price")==0)
        {
            cout << "sort conditions set\n";
        }
        else
        {
            optErr=true;
            cout << "sort arguments are not set" << endl;
        }
        
        if (outValue.empty() || csvValue.empty())
        {
            cout << sortValue.compare("quantity") << endl;
            optErr = true;
            cout << "option arguments are not set" << endl;
        }
        else
        {
            //fout will be used to write to output file
            ofstream fout;
            fout.open(outValue, ios_base::ate);
            if(fout)
            {
                optErr = false;

                ifstream inFile;
                inFile.open(csvValue);
                if(inFile)
                {
                    int recordCount = csvhelper(inFile, csvValue + ".csv");
                    sortCSV(fout, outValue, sortValue);
                    inFile.close();
                    fout.close();
                    if(recordCount)
                    {
                        cout << recordCount << " records processed" << endl;
                        optErr = false;
                    }
                    else
                    {
                        optErr = true;
                    }
                }
                else
                {
                    optErr = true;
                }
            }
            else
            {
                cout << "couldn't open " << outValue << endl;
                optErr = true;
            }
        }
    }
    else
    {
        cout << "error - flags are not set!" << endl;
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }

    cout << "optErr: " << optErr << endl;

    return EXIT_SUCCESS;
}