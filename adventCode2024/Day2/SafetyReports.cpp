//
// Created by Anthony Sevarino on 2/26/2025.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <utility>

#define filename "D:\\Advent of Code\\2024\\Day2\\PuzzleInputs\\Input.txt"
using namespace std;

vector<string> getFile(){       //function to get and package list vectors
    ifstream fin(filename);//open input file
    if(!fin) {              //throw error if 404
        cerr << "Error Unable to open file Input.txt" << endl;
        exit(1);
    }

    vector<string> lines;    //creates a vector of strings called lines
    string line;

    while (getline(fin, line)) {    //while file (fin) has lines, store in line
        lines.push_back(line);            //appends line to lines vector
    }
    fin.close();    //close file
    return lines;
}

int main(){
    vector<string> Lines = getFile();
    vector<int> report;

    for(int i = 0; i < Lines.size(); i++){             //iterate each report
        stringstream stream(Lines[i]);
        int level;

        stream << level;

        report.push_back(level);
    }
    /*Psuedocode
        one report per line
        each report is list of numbers called levels SEPARATED BY SPACES
        report safe if:
            levels all only increase or only decrease per line
            adjacent levels differ by at least one and at most three
     */

}