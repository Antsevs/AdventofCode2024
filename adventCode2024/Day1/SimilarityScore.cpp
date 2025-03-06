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

#define filename "D:\\Advent of Code\\2024\\Day1\\PuzzleInputs\\Input.txt"
using namespace std;

pair<vector<int>, vector<int>> getFile(){       //function to get and package list vectors
    ifstream fin(filename);//open input file
    if(!fin) {              //throw error if 404
        cerr << "Error Unable to open file Input.txt" << endl;
        exit(1);
    }

    vector<string> lines;    //creates a vector of strings called lines
    string line;

    vector<int> listRight, listLeft;    //right and left lists of locationIDs

    int listDistance = 0;


    while (getline(fin, line)) {    //while file (fin) has lines, store in line
        lines.push_back(line);            //appends line to lines vector
    }

    fin.close();    //close file

    //display the stored lines
    /*for (const string& storedLine : lines) {
        cout << storedLine << endl;
    }*/

    //this block separates the two columns into two vectors
    for (int i = 0; i < lines.size(); ++i) {//loop for each line
        stringstream stream(lines[i]);
        int val1, val2;

        stream >> val1 >> val2; //stringstream called stream will automatically look for number (val 1), then skip white space until val 2

        listRight.push_back(val2);
        listLeft.push_back(val1);
    }
    return make_pair(listLeft, listRight);  //packages the two vectors
}

int main(){
    auto [ListLeft, ListRight] = getFile();     //unpacks pair of vectors
    int simScore = 0;       //LEARNING EXPERIENCE                   //Uninitialized values in C++ hold garbage values

    for (int i = 0; i < ListLeft.size(); ++i) {                     //for each left number, check against each right number
        int count = 0;                                              //reset counter for number of appearances
        for (int j = 0; j < ListRight.size(); ++j) {
            if (ListLeft[i] == ListRight[j]) {                      //if match, iterate count
                count++;
            }
        }
        simScore += count * ListLeft[i];                            //add count * index to simScore val
    }

    cout << simScore << endl;
}