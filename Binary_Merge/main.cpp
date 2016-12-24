#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sstream>

#define MAX_FILE_COUNT 5
using namespace std;

void fillNull(ofstream& outFile, long startPt, long fileSize){

    char a = 255;
    for(long stPt = 0; stPt < fileSize; ++stPt )
    outFile << a;
}

void read(){

    ofstream fileOut;
    ifstream rdFile("BinMerge.cfg");
    stringstream ss;
    int countOfFiles = 0;
    string outputFile;
    /*Output File*/
    //fileOut.open("allBin.bin", ios::out | ios::binary);

    if(!fileOut)
	{
		perror("Error Message ");
		cout<<"Press any key to exit...\n";
		getch();
		exit(EXIT_FAILURE);
	}

    /*Process the Config File*/
    string fileType = "";
    while(getline(rdFile, fileType)){

        auto outPutFilePos = fileType.find("#Output File path", 0);

        if(outPutFilePos != string::npos){
            getline(rdFile, outputFile);
            if(fstream(outputFile + "AllBin.bin" ).good())
            {
                remove(string(outputFile + "AllBin.bin").c_str());
            }
            fileOut.open(outputFile + "AllBin.bin", ios::out | ios::binary);
            if(!fileOut)
            {
                perror("Error Message ");
                cout<<"Press any key to exit...\n";
                getch();
                exit(EXIT_FAILURE);
            }
        }

        if(fileOut){

            auto startPos = fileType.find("#File Path with Name", 0);
            auto endPos = fileType.find("#File start address", 0);

            if((startPos != string::npos) && (endPos != string::npos)) {

                while((getline(rdFile, fileType)) && (countOfFiles++ < MAX_FILE_COUNT))
                {

                    string entityName ;

                    string entityValue ;
                    stringstream fileStream(fileType);
                    string s;

                    fileStream >> entityName;
                    fileStream >> entityValue;

                    if(0 == std::string("unknown").compare(entityValue))
                    {
                        continue;
                    }

                    ss << std::hex << std::string(entityValue);
                    int64_t address = 0;
                    ss >> address;
                    ss.clear();

                    ifstream fileReader;
                    fileReader.open(entityName, ios::in | ios::binary);
                    if(fileReader)
                    {
                        long writtenFileSz = fileOut.tellp();
                        fillNull(fileOut, writtenFileSz, address - writtenFileSz);
                        fileOut << fileReader.rdbuf();

                    }

                    fileReader.close();

                }
            }
        }

    }

    /*Close the open files*/
	rdFile.close();
	fileOut.close();
}
int main()
{
    read();
    return 0;
}
