/*******************************************************************************
* File: CSV_Reader.h
* Description: 
* Author: Alexander DuPree
* Compiler:  GNU GCC 5.4.0
* Date: 2018-04-14
* Modifications:
   
*******************************************************************************/

#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <limits>

class CSV_Reader
{
public:

    CSV_Reader(const char infile[], char delim = ',');
    
    ~CSV_Reader();
    // Destructor calls member function closeFiles.

    void closeFile();
    // Invokes m_fin and m_fouts member function to close(). 
    
    void seek(int n);
    // Loops until lines have been skipped n times. 
    
    void readLine(std::string container[]);
    // Assumes the container is at least the size of the number of fields
    // in the data file. filles each index in the container with the data 
    // corresponding to the index of the field
    
    int lines();
    // Returns the number of lines in the file
    
    int fields();
    // Returns the number of fields (columns) of the CSV file
    
    bool eof();
    // Returns the eof flag of the member ifstream object m_fin.
    
  
private:

    const char*  m_INFILE;
    
    char m_delim;
    int m_lines;
    int m_fields;
   
    std::ifstream m_fin;

    void openFile();
    // Attempts to open infile, throws std::ios_base::failure exception on 
    // failure.
    
    int readFields();
    // Counts the number of fields in each row. This will determine the size
    // reading array
    
    int countLines();
    // Counts the number of lines in the file and stores that into m_lines
};

#endif // CSV_READER_H
