/*******************************************************************************
* File: wk2_files3_airports_adupree.cpp
*
* Description: 
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-14
*
* Modifications:
*
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "CSV_Reader.h"
#include "airport.h"

void extractData(std::ifstream& fin, Airport airports[], int lines, int fields);

int main() 
{
    int lines;
    std::ifstream fin;
    const char FNAME[] = "newAirportFile.csv";
    const char OUTNAME[] = "newAirportFile2.csv";

    const std::string FIELDS[5] = {"ident", "type", "name", "elevation_ft", 
                                "iso_country"};

    CSV_Reader reader(FNAME, OUTNAME);

    try 
    {
        reader.clean(FIELDS, 5);
        //CSV_Reader throws ios_base::failure on failed file open
    }
    catch ( std::ios_base::failure& err )
    {
        std::cerr << err.what() << std::endl;
        exit(1);
    }

    lines = reader.linesWrote() - 1;
    // Minus one to discount the top field names line.
    
    reader.closeFiles();
    
    fin.open(OUTNAME);
    if (fin.fail())
    {
        std::cerr << "Failed to open " << OUTNAME << std::endl;
        exit(1);
    }

    std::cout << lines << std::endl;
    
    Airport* airports = new Airport[lines];
    // We use dynamic allocation on an object array here because stack 
    // allocation of parralell arrays was blowing the stack on my machine. 
    // To solve this I created an array of airport objects on the heap.
    
    extractData(fin, airports, lines, 5);

    return 0;
}

void extractData(std::ifstream& fin, Airport airports[], int lines, int fields)
{
    int count = 0;
    int index = 0;
    std::string field[fields];
    // Temp array used in the airport constructor. 

    // Skip first line
    std::getline(fin, field[0]);
    while (count < lines)
    {
        for(int i = 0; i < fields; i++)
        {
            std::getline(fin, field[i], ',');
        }
        try
        {
            airports[count] = Airport(field[0], field[1], field[2], field[3], 
                                  field[4]);
            index++;
            // We only increment index for completed entries. This makes sure 
            // that valid objects are stored next to each other in the array.
        }
        catch (std::invalid_argument& err)
        {
            std::cerr << err.what() << "Elevation: " << field[3] << " line: " 
                      << count << std::endl;
        }
        count++;
    }
    std::cout << index << std::endl;
    return;
}

