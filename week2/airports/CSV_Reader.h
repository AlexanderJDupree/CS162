/*******************************************************************************
* File: CSV_Reader.h
* Description: 
* Author: Alexander DuPree
* Compiler:  GNU GCC 5.4.0
* Date: 2018-04-14
* Modifications:
*
*   TODO add methods to change in and outfile and append new data onto the end 
*   of outfile
*
*   TODO add methods to read a single line from infile and store onto an array.
*
*   TODO Restructer std::set<int> m_fields into a regular array. We don't need 
*   the set functionality or iterators.
*******************************************************************************/

#ifndef CSV_READER_H
#define CSV_READER_H

#include <fstream>
#include <string>
#include <set>

class CSV_Reader
{
public:

    CSV_Reader(const char infile[], const char oufile[], char delim = ',');
    // Constructor assigns the parameters infile, outfile and delim to the 
    // corresponding member variables. Constructor then attempts to open the 
    // files as well as set m_fields to 0. Default delim is a comma.
    
    ~CSV_Reader();
    // Destructor calls member function closeFiles.

    void clean(const std::string fields[], const int numFields);
    // Parameter fields array contains all column identifiers for the 
    // CSV reader to look for. numFields should be the size of the fields array 
    
    void closeFiles();
    // Invokes m_fin and m_fouts member function to close(). 
    
    int linesWrote();
    // returns the running total of lines written to OUTFILE

private:

    const char*  m_INFILE;
    const char*  m_OUTFILE;
    
    char m_delim;
    int m_rightBound;
    int m_columns;
    int m_lines;
   
    std::ifstream m_fin;
    std::ofstream m_fout;

    std::set<std::string> m_fieldNames;
    std::set<int> m_fields;

    void openFiles();
    // Attempts to open infile and outfile, throws std::ios_base::failure 
    // exception on failure.
    
    void readFields();
    // Reads the first line of the csv file and stores matching field indexes in
    // to m_fields. 
  
    void copyData();
    // Copies relevent data within the bounds of acceptable field names into the 
    // outfile. 

};

#endif // CSV_READER_H
