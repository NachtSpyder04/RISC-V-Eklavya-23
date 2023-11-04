#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

string BintoHex(string binValue) 
{
    size_t length = binValue.length();
    if (length % 4 != 0) 
    {
        size_t padding = 4 - (length % 4);
        binValue = string(padding, '0') + binValue;
    }

    const string Hexanum = "0123456789ABCDEF";
    string hexValue;
    for (size_t i = 0; i < length; i += 4) 
    {
        string nibble = binValue.substr(i, 4);
        int decimalValue = 0;
        int temp = stoi(nibble); 
        int base = 1;
        while (temp) 
        { 
            int last_digit = temp % 10; 
            temp = temp / 10; 
            decimalValue += last_digit * base; 
  
        base = base * 2; 
        }
        
        hexValue += Hexanum[decimalValue];
    }

    return hexValue;
}

string DecitoBin(int deciValue)
{
    if (deciValue == 0) 
    {
        return "0"; 
    }
    string binValue;
    while (deciValue > 0) 
    {
        binValue = to_string(deciValue % 2) + binValue;
        deciValue /= 2;
    }
    while (binValue.size() < 5) 
    {
        binValue = "0" + binValue;
    }
    return binValue;
} 
bool removeLastLine(string filename) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return false;
    }

    vector<string> lines;
    string line;

    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    ofstream outputFile(filename, ios::trunc);

    if (!outputFile) {
        cerr << "Error opening file for writing." <<endl;
        return false;
    }

    for (size_t i = 0; i < lines.size() - 2; i++) {
        outputFile << lines[i] << endl;
    }

    outputFile.close();
    return true;
}