#include "CSV_Reader.h"

CSV_Reader::CSV_Reader(const char infile[], const char outfile[], char delim) 
    : m_INFILE(infile), m_OUTFILE(outfile), m_delim(delim), m_lines(0) {}

CSV_Reader::~CSV_Reader()
{
    closeFiles();
}

void CSV_Reader::clean(const std::string fields[], const int numFields)
{
    // Build set 
    for (int i = 0; i < numFields; i++)
    {
        m_fieldNames.insert(fields[i]);
    }

    openFiles();
    // Thrown exceptions are handled in driver file
    
    readFields();
    // Finds the column position of the valid fields. 
    
    copyData();
    // Copy clean data into outfile
  
    return;
}

void CSV_Reader::closeFiles()
{
    m_fin.close();
    m_fout.close();
    return;
}

int CSV_Reader::linesWrote()
{
    return m_lines;
}


// private

void CSV_Reader::openFiles()
{
    m_fin.open(m_INFILE);
   if (m_fin.fail())
   {
       throw std::ios_base::failure("failed to open INFILE");
   }

   m_fout.open(m_OUTFILE);
   if (m_fout.fail())
   {
       throw std::ios_base::failure("failed to open OUTFILE");
   }
   return;
}

void CSV_Reader::readFields()
{
    int index = 0;
    char data = '\0';
    std::string field = "";
    
    // continue until end of line
    while (data != '\n')
    {
        // reset the data variable
        data = '\0';

        // read until the delimiter or end of line
        while (m_fin.get(data) && data != m_delim && data != '\n')
        {
            // concatenate the data into a string
            field += data;
        }

        // search that the field is in our map of valid field names
        std::set<std::string>::const_iterator it = m_fieldNames.find(field);
        if (it != m_fieldNames.end())
        {
            // insert the valid index into the indexes set 
            m_fields.insert(index);
            m_rightBound = index;
        }

        //increment index to represend next column and reset field string
        index++;
        field = "";
    }
    
    m_columns = index;
    
    return;
    
}

void CSV_Reader::copyData()
{
    int index = 0;
    int marker = 0;
    char ch = '\0';
    std::set<int>::iterator it = m_fields.begin();

    // return to the beginning of the file
    m_fin.seekg(marker, std::ios::beg);

    // Read until the end of file
    while(!m_fin.eof())
    {
        std::string data = "";
        // Initialize data to null
        
        while (m_fin.get(ch) && (ch != m_delim && ch != '\n'))
        {
            data += ch;
        }

        if (index == *it)
        {
            // Found invalid data
            if (data == "")
            {
                // Jump to the marker, beginning of line
                m_fout.seekp(marker);
                index = 0;
                it = m_fields.begin();
                m_lines--;
            }
            else 
            {
                m_fout << data << m_delim;
                
                // Move iterator to the next desired column
                it++;
            }
        }

        if (index == m_rightBound)
        {
            if (ch != '\n')
            {
                // Skip the rest of line
                m_fin.ignore(1000, '\n');
            }

            index = 0;
            
            // Return iterator to begin
            it = m_fields.begin();

            // Move out file to next line
            m_fout << '\n';

            // Mark beginning of the line
            marker = m_fout.tellp();

            m_lines++;
        }
        else
        {
            index++;
        }
    }

    return;
}
