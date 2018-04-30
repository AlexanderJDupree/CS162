/*******************************************************************************
* File: wk4_encryption_adupree.cpp
*
* Description: Program encrypts and decrypts the contents of two data files and 
*              writes the results to a third file. The contents of each file is
*              also printed to the screen.
*
* Author: Alexander DuPree
*
* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-28
*
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

typedef std::vector<std::string> stringVector;

std::string encrypt(const std::string& word);
// Utilizes the encryption scheme described in the assignment to return an 
// encrypted version of the parameter 'word'

std::string decrypt(const std::string& word);
// Utilizes the decryption scheme described in the assignment to return a
// decrypted version of the parameter 'word'

void extractData(std::ifstream* fin, stringVector* container);
// Reads each line of data into our vector containter.

void writeData(std::ofstream* fout, const stringVector& words, 
                                    const stringVector& encrypted);
// Writes the data from the words and encrypted vectors into an outfile. If the
// encryptions do not match an error is wrtten to the file as well.

void printError(const std::string& error);
// Prints error to console

void printWords(const stringVector& words, const std::string& caption);
// Prints each element in the words vector to console

void printFile(std::ifstream* fin, const std::string& caption);
// Prints the entire file connected to the fin stream

void intro();
// Prints an introductory caption for the user

void openFile(const char* FNAME, std::ifstream* fin);
// Attempts to open the file for reading, exits and prints
// error if opening fails

void openFile(const char* FNAME, std::ofstream* fout);
// Overloaded openfile function for ofstream for writing.

int main()
{
    // Declarations
    std::ifstream fin;
    std::ofstream fout;
    stringVector plainWords;
    stringVector encrypted;

    const char* FNAME = "plainWords.txt";
    const char* ENCRYPTED = "encryptedWords.txt";
    const char* OUTFILE = "allWords.txt";

    // Input
    openFile(FNAME, &fin);
    extractData(&fin, &plainWords);
    fin.close();

    openFile(ENCRYPTED, &fin);
    extractData(&fin, &encrypted);
    fin.close();

    // Process
    openFile(OUTFILE, &fout);
    writeData(&fout, plainWords, encrypted);
    fout.close();

    // Output
    intro();
    printWords(plainWords, FNAME);
    printWords(encrypted, ENCRYPTED);

    openFile(OUTFILE, &fin);
    printFile(&fin, OUTFILE);
    fin.close();

    return 0;
}

std::string encrypt(const std::string& word)
{
    std::string encrypted = "";

    encrypted += *word.rbegin();
    // First letter of encrypted word equals the last letter of the word
    
    if (word[1] >= 'i')
    {
        encrypted += (word[1] + 17) - 26;
    }
    else
    {
        encrypted += word[1] + 17;
    }
    encrypted += word[2] - 50;
    encrypted += *word.begin();
    // Last letter of encrypted word equals first letter of the word

    return encrypted;
}

std::string decrypt(const std::string& word)
{
    std::string decrypted = "";

    decrypted += *word.rbegin();
    // First letter of encrypted word equals the last letter of the word
    
    if (word[1] < 'r')
    {
        decrypted += (word[1] - 17) + 26;
    }
    else 
    {
        decrypted+= word[1] - 17;
    }
    decrypted += word[2] + 50;
    decrypted += *word.begin();
    // Last letter of encrypted word equals first letter of the word
     
    return decrypted;
}

void extractData(std::ifstream* fin, stringVector* container)
{
    std::string data;
    while (std::getline(*fin, data))
    {
        container->push_back(data);
    }
    return;
}

void writeData(std::ofstream* fout, const stringVector& words, 
                                    const stringVector& encrypted)
{
    std::string decrypted; 
    *fout << "Plain\tEncrypted  Decrypted" << std::endl;
    for (unsigned int i = 0; i < words.size(); i++)
    {
        decrypted = decrypt(encrypted[i]);
        *fout << words[i] << '\t' << encrypted[i] << "\t   " << decrypted;
        if (words[i] != decrypted)
        {
            *fout << "\tEncryption error on word #" << i+1;
        }
        *fout << std::endl;
    }
    return;
}


void printError(const std::string& error)
{
    std::cout << error << std::endl;
    return;
}

void printWords(const stringVector& words, const std::string& caption)
{
    std::cout << '\n' << caption << '\n' << std::endl;

    stringVector::const_iterator it = words.begin();
    for (it = words.begin(); it != words.end(); ++it)
    {
        std::cout << *it << '\t';
    }
    std::cout << std::endl;
    return;
}

void printFile(std::ifstream* fin, const std::string& caption)
{
    std::string data;
    std::cout << '\n' << caption << '\n' <<  std::endl;

    while (std::getline(*fin, data))
    {
        std::cout << data << std::endl;
    }

    return;
}

void intro()
{
    std::cout << "\t\tENCRYPTION / DECRYPTION PROGRAM" << std::endl;
    return;
}

void openFile(const char* FNAME, std::ifstream* fin)
{
    fin->open(FNAME);
    if (fin->fail())
    {
        printError("Failed to open file for reading");
        exit(1);
    }
    return;
}

void openFile(const char* FNAME, std::ofstream* fout)
{
    fout->open(FNAME);
    if (fout->fail())
    {
        printError("Failed to open file for writing");
        exit(1);
    }
    return;
}
