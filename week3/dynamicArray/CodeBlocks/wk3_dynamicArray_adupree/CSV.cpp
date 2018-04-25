/*******************************************************************************
* Source file for CSV.h
*******************************************************************************/

#include "CSV.h"

namespace CSV
{

    Reader::Reader(const char infile[], char delim) 
        : m_INFILE(infile), m_delim(delim)  
    {
        openFile();
        m_lines = countLines();
        m_fields = readFields();
    }

    Reader::~Reader()
    {
        closeFile();
    }

    void Reader::closeFile()
    {
        m_fin.close();
        return;
    }

    void Reader::seek(int n)
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

    void Reader::readLine(std::string container[])
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

    /* Inspectors */ 
    int Reader::lines()
    {
       return m_lines;
    }

    int Reader::fields()
    {
        return m_fields;
    }

    bool Reader::eof()
    {
        return m_fin.eof();
    }

    /* Private */
    void Reader::openFile()
    {
        m_fin.open(m_INFILE);
       if (m_fin.fail())
       {
           throw std::ios_base::failure("failed to open INFILE");
       }
       return;
    }

    int Reader::readFields()
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

    int Reader::countLines()
    {
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

/*******************************************************************************
* Writer class 
*******************************************************************************/
    Writer::Writer(const char outfile[], char delim, bool append) 
        : m_OUTFILE(outfile), m_delim(delim)
    {
        openFile(append);
    }

    Writer::~Writer()
    {
        closeFile();
    }

    void Writer::closeFile()
    {
        m_fout.close();
        return;
    }

    void Writer::writeLine(const std::string data[], const int fields)
    {
        for (int i = 0; i < fields; i++)
        {
            m_fout << data[i] << ',';
        }
        m_fout << '\n';
        m_lines++;
        return;
    }

    /* Inspectors */
    int Writer::lines()
    {
        return m_lines;
    }

    /* Private */
    void Writer::openFile(bool append)
    {
        if(append)
        {
            m_fout.open(m_OUTFILE, std::ios::app);
        }
        else
        {
            m_fout.open(m_OUTFILE);
        }

        if (m_fout.fail())
        {
            throw std::ios_base::failure("Failed to open OUTFILE");
        }

        return;
    }

}

