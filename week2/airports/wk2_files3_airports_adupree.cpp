/*******************************************************************************
* File: wk2_files3_airports_adupree.cpp
*
* Description: Reads airports.csv into memory, performs search operations on 
*              the objects
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
#include "CSV_Reader.h"
#include "airport.h"

void printChoices();
// Displays to console the available program options

void printError(std::string error);
// Displays to console the error message

void printList(Airport* airports[], int left, int right, std::string header);
// Prints the header, then calls printAirport() for each  airports within the 
// left/right index. Prints 5 airports at a time. 

void printAirport(Airport* airport);
// Prints the airports data in a formatted output.

void extractData(std::ifstream& fin, Airport airports[], int lines, int fields,
                 char delim);
// extract data reads each line of the input file and attempts to use each field
// as the argument for the airport objects constructor. If the constructor fails
// then an std::invalid_argument error is thrown. That entry is skipped and we 
// continue on the next line. 

void searchCountry(Airport* countries[], int size, std::pair<int, int>* range);
// Prompts user for search query, searches SORTED array for match. Returns the 
// bounds of the matching elements

void searchElev(Airport* elevations[], int size, std::pair<int, int>* range);
// Prompts user for search query, searches SORTED array for match.  Returns the 
// bounds of the matching elements. 

void searchIdent(Airport* airports[], int size, std::pair<int, int>* range);
// Prompts user for search query, searches array match. Returns the bounds of 
// the matching elements.

void assignPointers(Airport airports[], Airport* pointers[], int size);
// Loops through the heap allocated master airports array and assigns pointers 
// to the stack allocated pointers array. 

void quickSort(Airport* airports[], int left, int right, 
               bool(*Compare)(Airport*, Airport*));
// Standard quicksort algorithm but instead of using the > comparison operator
// we use a function pointer to determine the correct comparison


int partition(Airport* airports[], int left, int right, 
              bool(*Compare)(Airport*, Airport*));
// Parition is used within quick sort to move objects around the pivot point and 
// returning the index of the pivot in the array.

template <typename T>
T getInput(std::string prompt);
// Prints prompt to the console, then records and returns the user input

std::string toUpper(std::string input);
// Returns an uppercase version of the input string

bool compareElevation(Airport* port1, Airport* port2);
// Returns the comparison boolean of each airports elevation

bool compareCountries(Airport* port1, Airport* port2);
// Returns the comparison boolean of each airports country

int main() 
{
    int lines;
    // Total line written to FILEOUT

    std::ifstream fin;
    std::string input;
    std::pair<int, int> range(-1, -1);
    // Range represents the left/right bound of indexes of valid data in our 
    // arrays.

    const char DELIMITER = '\t';
    const char FILEIN[] = "airports2.csv";
    const char FILEOUT[] = "newAirportFile.csv";
    const std::string FIELDS[5] = {"ident", "type", "name", "elevation_ft", 
                                "iso_country"};

    CSV_Reader reader(FILEIN, FILEOUT, DELIMITER);
    // CSV_Reader object cleans up our data file based on the field names and 
    // delimiter settings we give it. It then writes the cleaned data to FILEOUT

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

    lines = reader.linesWrote();
    
    reader.closeFiles();
    
    fin.open(FILEOUT);
    if (fin.fail())
    {
        std::cerr << "Failed to open " << FILEOUT << std::endl;
        exit(1);
    }

    
    Airport* countries[lines];
    Airport* elevations[lines];
    Airport* airports = new Airport[lines];
    /* Stack allocation of parrallel arrays was blowing my stack. I also wanted
       to be able to sort the parrallel arrays so I could search for elements 
       faster. To solve this I dynamically allocated an array of airport objects
       onto the heap, and on the stack I created pointer arrays of the search 
       criteria. This allows me to sort the pointer arrays and binary search 
       them.  */ 

    extractData(fin, airports, lines, 5, DELIMITER);

    assignPointers(airports, countries, lines);
    assignPointers(airports, elevations, lines);
    // Points our pointer arrays to the correct objects in memory

    quickSort(elevations, 0, lines - 1, &compareElevation);
    quickSort(countries, 0, lines - 1, &compareCountries);
    // Sort by different criteria
    
    // User Interface
    do {
        printChoices();

        input = getInput<std::string>("\n> ");

        switch(input[0])
        {
            case '1' : searchCountry(countries, lines, &range); 
                       printList(countries, range.first, range.second,
                               "\t\t\nAirports in Searched Country");
                       break;

            case '2' : searchElev(elevations, lines, &range);
                       printList(elevations, range.first, range.second,
                               "\t\t\nAirports above Searched Elevation");
                       break;

            case '3' : searchIdent(elevations, lines, &range); 
                       printList(elevations, range.first, range.second,
                               "\t\t\nAirport with matching Identifier");
                       break;

            case 'q' : break;

            default : printError("Invalid input."); 
        }
    } while (input != "q");
     
    return 0;
       
}

void printChoices()
{
    std::cout << "\n\t\tAIRPORTS\n\nPlease choose an option from the menu:";
    std::cout << "\n\n  1.  View all airports in a country\n  2.  View all "
              << "airports above a certain elevation\n  3.  View airport by "
              << "identifier\n(Enter 'q' to quit)";
}

void printError(std::string error)
{
    std::cout << '\n' << error << std::endl;
    return;
}

void printList(Airport* airports[], int left, int right, std::string header)
{
    if (left < 0)
    {
        printError("Search criteria was not found.");
        return;
    }

    std::cout << header << std::endl;

    int count = 1;
    while (left < right)
    {
        printAirport(airports[left]);

        if (count % 5 == 0)
        {
            std::cout << '\n' << right - left - 1 << " entries remaining."
                      << " Continue? (Y or N)";

            std::string repeat = getInput<std::string>("\n>  ");

            if (repeat[0] == 'N' || repeat[0] == 'n')
            {
                return;
            }
        }
        left++;
        count ++;
    }
    return;
}

void printAirport(Airport* airport)
{
    std::cout << "\n\t" << airport->name() << "\nIdent: "  
              << airport->identifier() << "\nType: " << airport->type()
              << "\nCountry: " << airport->country() << "\nElevation: "
              << airport->elevation() << " ft\n";
    return;
}

void extractData(std::ifstream& fin, Airport airports[], int lines, int fields, 
                 char delim)
{
    int count = 0;
    int line = 0;
    int index = 0;
    char data = '\0';
    std::string field[fields];
    // Temp array used in the airport constructor. 

    // Skip first line
    std::getline(fin, field[0]);
    while (line < lines)
    {
        field[count] = "";
        // Initialize field data to null
        
        while (fin.get(data) && (data != delim && data != '\n'))
        {
            field[count] += data;
        }

        count++;

        if (count == fields)
        {
            try
            {
                airports[index] = Airport(field[0], field[1], field[2], field[3], 
                                      field[4]);
                index++;
                //We only increment index for completed entries. This makes sure 
                //that valid objects are stored next to each other in the array.
            }
            catch (std::invalid_argument& err)
            {
                std::cerr << err.what()  << " Check line: " << count 
                          << std::endl;
            }
            
            if (data != '\n')
            {
                // Get rid of extra characters at the end of the line
                fin.ignore(100, '\n');
            }

            count = 0;
            line++;
        }
       
    }
    return;
}

void searchCountry(Airport* countries[], int size, std::pair<int, int>* range)
{
    std::string target;
    target = getInput<std::string>("\nEnter the 2 letter country identifier\n> ");
    target = toUpper(target);
  
    range->first = -1;
    // initialize to -1 to represent that the target was not found.
    range->second = size;

    int i;
    for (i = 0; i < size; i++)
    {
        // Found left bound
        if (countries[i]->country() == target)
        {
            range->first = i;
            break;
        }
    }
    while (i < size)
    {
        // Found right bound
        if (countries[i]->country() != target)
        {
            range->second = i;
            break;
        }
        i++;
    }

    return;
}

void searchElev(Airport* elevations[], int size, std::pair<int, int>* range)
{
    int target;
    range->first = -1;
    // Initialize to -1 to represent that the target was not found.
    range->second = size;

   try 
    {
        target = getInput<int>("\nEnter the elevation in feet\n> ");
    }
    catch(std::invalid_argument& err)
    {
        std::cerr << err.what() << std::endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        if (elevations[i]->elevation() >= target)
        {
            range->first = i;
            return;
        }
    }
    return;

}

void searchIdent(Airport* airports[], int size, std::pair<int, int>* range)
{
    std::string target;
    target = getInput<std::string>("\nEnter airport identifier\n> ");
    target = toUpper(target);

    range->first = -1;
    // Initialize to -1 to represent that the target was not found.
    range->second = size;

    for (int i = 0; i < size; i ++)
    {
        if (airports[i]->identifier() == target)
        {
            range->first = i;
            range->second = i + 1;
            return;
        }
    }
    return;
}

void assignPointers(Airport airports[], Airport* pointers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        pointers[i] = &airports[i];
    }
    return;
}

void quickSort(Airport* airports[], int left, int right, 
               bool(*Compare)(Airport*, Airport*))
{
    // Base case
    if (left >= right)
    {
        return;
    }
    
    int part =  partition(airports, left, right, Compare);

    quickSort(airports, left, part - 1, Compare);
    // Quick sort left partition
    
    quickSort(airports, part + 1, right, Compare);
    // Quick sort right partition

}

int partition(Airport* airports[], int left, int right, 
              bool(*Compare)(Airport*, Airport*))
{
    /* Partition takes the right most element as the pivot, places the pivot in 
       the correct index in the array and arranges elements greaeter than the 
       pivot to the right and less than or equal to the left */
   
    Airport* pivot = airports[right];
    int i = left - 1;
    // index of smaller element
    
    for (int j = left; j <= right - 1; j++)
    {
        if ((*Compare)(airports[j], pivot))
        {
            i++;
            Airport* temp = airports[i];
            airports[i] = airports[j];
            airports[j] = temp;
        }
    }
    // Swap pivot to the correct index in the array
    Airport* temp = airports[i+1];
    airports[i+1] = airports[right];
    airports[right] = temp;

    return (i + 1);
}

template <typename T>
T getInput(std::string prompt)
{
    T input;

    std::cout << prompt;
    std::cin >> input;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        throw std::invalid_argument("\nInvalid input."); 
    }

    return input;
}

std::string toUpper(std::string input)
{
    std::string newString = "";
    for (unsigned int i = 0; i < input.length(); i++)
    {
        if (input[i] <= 'z' && input[i] >= 'a')
        {
            newString += (input[i] - 32);
        }
        else 
        {
            newString += input[i];
        }
    }
    return newString;
}
bool compareElevation(Airport* port1, Airport* port2)
{
    return port1->elevation() <= port2->elevation();
}

bool compareCountries(Airport* port1, Airport* port2)
{
    return port1->country() <= port2->country();
}

