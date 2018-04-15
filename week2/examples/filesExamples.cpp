/*******************************************************************************
* File: framework.cpp
*
* Description: 
*
* Author: Alexander Dupree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-12
*
* Modifications:
*******************************************************************************/

#include<iostream>
#include<fstream>
#include<cstdlib>

void writeCount(std::ofstream& fout, int range);

int main()
{
    // declare stream objects
    std::ifstream fin;
    std::ofstream fout;

    int num;
    int total = 0;
    const char file[] = "numbers.dat";

    // Open (create) file
    fout.open(file);
    if (fout.fail())
    {
        std::cout << "Failed to open " << file << std::endl;
        exit(1);
    }

    // add numbers to start of file
    writeCount(fout, 10);

    // close output file
    fout.close();

    // Open file
    fin.open(file);
    if (fin.fail())
    {
        std::cout << "Failed to open " << file << std::endl;
        exit(1);
    }

    // Read file, add to total
    while(!fin.eof())
    {
        fin >> num;
        total += num;
    }
    fin.close();

    // Append total to file
    fout.open(file, std::ios::app);
    if (fout.fail())
    {
        std::cout << "Failed to open " << file << std::endl;
        exit(1);
    }

    fout << "\nTotal: " << total << '\n';

    fout.close();

    return 0;
}

void writeCount(std::ofstream& fout, int range)
{
    for(int i = 1; i <= range; i++)
    {
        fout << ' ' << i ;
    }
    return;
}
