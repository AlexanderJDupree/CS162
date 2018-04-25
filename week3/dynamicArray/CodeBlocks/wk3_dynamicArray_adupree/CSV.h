/*******************************************************************************
* Namespace: CSV
*
* Description: CSV namespace allows user access to the Reader and Writer classes
*              to read and modify delimited file formats
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-14
*
* Modifications:
*       TODO Reader and Writer share the same constructor, destructor, and 
*       certain inspectors. Refactor CSV into a parent class with Reader and
*       Writer as children classes that inherit the basic methods from CSV
*******************************************************************************/

#ifndef CSV_H
#define CSV_H

#include <fstream>
#include <limits>

namespace CSV 
{

/*******************************************************************************
* Class Name: Reader
*
* Description: Reader class provides functionality for extracting data from a 
*              delimited file format into an array. Once a Reader object has 
*              been constructed for a file it also provides inspectors for
*              determining the number of lines and columns in a file.
*******************************************************************************/

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

/*******************************************************************************
* Class Name: Writer
*
* Description: Writer class provides functionality for writing data from an 
*              array into a delimited file format. Writer object can append to
*              a file or overwrite a file by providing a boolean argument to the
*              constructor. Writer object provides an inspector to determine the
*              number of lines wrote.
*******************************************************************************/

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
