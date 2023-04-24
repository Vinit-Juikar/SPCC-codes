// display mnt and mdt

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> mnt; // Macro Name Table
    vector<string> mdt; // Macro Definition Table
    // Open the input file
    ifstream inputFile(“input.asm”);
    // Read the input file line by line
    string line;
    while (getline(inputFile, line))
    {
        // Check if the line is a macro definition
        if (line.find(“MACRO”) != string::npos)
        {
            // Extract the macro name
            string macroName = line.substr(0, line.find(“ “));
            // Add the macro name to MNT and get its index
            int mntIndex = mnt.size();
            mnt.push_back(macroName);
            // Read the macro definition
            string macroDefinition;
            while (getline(inputFile, line) && line != “MEND”)
            {
                macroDefinition += line + “\n”;
            }
            // Add the macro definition to MDT
            mdt.push_back(macroDefinition);
            // Print the macro definition with its index
            cout << mntIndex << “\t” << macroDefinition;
        }
    }
    // Print MNT
    cout << “\nMacro Name Table(MNT) :\n”;
    for (int I = 0; I < mnt.size(); i++)
    {
        cout << I << “\t” << mnt[i] << endl;
    }
    // Print MDT
    cout << “\nMacro Definition Table(MDT) :\n”;
    for (int I = 0; I < mdt.size(); i++)
    {
        cout << I << “\t” << mdt[i] << endl;
    }
    // Close the input file
    inputFile.close();
    return 0;
}

// INPUT

// input.asm
// MOV AX, 0
// MOV BX, 0
// MACRO ADD_VALUES
//  ADD AX, #1
//  ADD BX, #2
// MEND
// ADD_VALUES
// ADD_VALUES
// MOV CX, AX
// MOV DX, BX
