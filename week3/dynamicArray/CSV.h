/*******************************************************************************
* File: CSV.h
* Description: 
* Author: Alexander DuPree
* Compiler:  GNU GCC 5.4.0
* Date: 2018-04-14
* Modifications:
*******************************************************************************/

#ifndef CSV_H
#define CSV_H

#include <fstream>
#include <limits>

namespace CSV 
{
    class Reader
    {
    public:

        Reader(const char infile[], char delim = ',');
        // Default constructor opens the infile and counts the number of lines
        // and fields

        ~Reader();
        // Destructor calls member function closeFiles.

        void closeFile();
        // Invokes m_fin member function to close(). 
        
        void seek(int n);
        // Loops until lines have been skipped n times. 
        
        void readLine(std::string container[]);
        // Assumes the container is at least the size of the number of fields
        // in the data file. fills each index in the container with the data 
        // corresponding to the index of the field
        
        /* Inspectors */
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

    class Writer
    {
    public:

        Writer(const char outfile[], char delim = ',', bool append = false);

        ~Writer();
        // Calls closeFile()
        
        void closeFile();
        // invokes m_fout member function close()
        
        void writeLine(const std::string data[], const int fields);
        // Iterates through each field in the data string and writes it to the
        // outfile. Ends with a newline character.
        
        /* Inspectors */

        int lines();
        // Returns the number of lines wrote to outfile
        
    private:

        const char* m_OUTFILE;

        char m_delim;
        char m_lines;

        std::ofstream m_fout;

        void openFile(bool append = false);
        // Attmepts to open outfile, throws std::ios_base::failure exception on
        // failure

    };
}

#endif // CSV_H
