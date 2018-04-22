#include "CSV_Reader.h"
#include <iostream> // debug

CSV_Reader::CSV_Reader(const char infile[], char delim) 
    : m_INFILE(infile), m_delim(delim)  
{
    openFile();
    m_lines = countLines();
    m_fields = readFields();
}

CSV_Reader::~CSV_Reader()
{
    closeFile();
}

void CSV_Reader::closeFile()
{
    m_fin.close();
    return;
}

void CSV_Reader::seek(int n)
{
    int i = 0;
    
    // Return to begining of file
    m_fin.seekg(0, std::ios::beg);
    while (!m_fin.eof() && i < n)
    {
        m_fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        i++;
    }
    return;
}

void CSV_Reader::readLine(std::string container[])
{
    char data = '\0';
    int index = 0;
    container[index] = "";

    while (m_fin.get(data) && data != '\n')
    {
        if (data == m_delim)
        {
            index++;
            container[index] = "";
        }
        else 
        {
            container[index] += data;
        }
    }
    return;
}

// getters
int CSV_Reader::lines()
{
   return m_lines;
}

int CSV_Reader::fields()
{
    return m_fields;
}

bool CSV_Reader::eof()
{
    return m_fin.eof();
}

// private
void CSV_Reader::openFile()
{
    m_fin.open(m_INFILE);
   if (m_fin.fail())
   {
       throw std::ios_base::failure("failed to open INFILE");
   }
   return;
}

int CSV_Reader::readFields()
{
    char data = '\0';
    int fields = 0;
    while (m_fin.get(data) && data != '\n')
    {
        if (data == m_delim)
        {
            fields++;
        }
    }

    fields++;

    // return to beginning of file
    seek(0);
    
    return fields;
}

int CSV_Reader::countLines()
{
    // TODO make this function usable only if the file has been changed
    int lines = 0;
    while (!m_fin.eof())
    {
        m_fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        lines++;
    }

    //return to beginning of file
    seek(0);

    return lines - 1;
}
