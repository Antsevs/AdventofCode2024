//
// Created by Anthony Sevarino on 2/20/2025.
//
#include <iostream>
#include <vector>
#include <fstream>

#define filename "D:\\Advent of Code\\2024\\Day1\\PuzzleInputs\\Input.txt"
using namespace std;

int main(){
    ifstream fin(filename);//open input file
    if (!fin) {              //throw error if 404
        cerr << "Error Unable to open file Input.txt" << endl;
        exit(1);
    }

    vector<string> lines;    //creates a vector of strings called lines
    string line;
    vector<int> differences; //vector which stores the differences between values
    int difference;
    int val1, val2, finalSum;          //ints which store current lowest value in each string

    while (getline(fin, line)) {    //while file (fin) has lines, store in line
        lines.push_back(line);            //appends line to lines vector
    }

    fin.close();    //close file

    //display the stored lines
    for (const string& storedLine : lines) {
        cout << storedLine << endl;
    }

    //this block will determine the smallest number in each line
    for (int i = 0; i < lines.size(); ++i) {//loop for each line
        val1 = lines[i][0] - '0';                 //initialize val1 as the first value in each line (string to integer)
        val2 = lines[i][8] - '0';                 //initialize val2 as 8th value in each line (first char of second string)
        for (int j = 0; j <= 12; j++) {     //loop for each character in line
            if (j < 5 && val1 > lines[i][j] - '0') {
                val1 = lines[i][j] - '0';
            } else if (j > 7 && val2 > lines[i][j] - '0') {
                val2 = lines[i][j] - '0';
            }
        }
        differences.push_back(abs(val1 - val2)); //append difference of smallest values to differences vector
        //cout << val1 << "   " << val2 << endl;      //this list represents the smallest value in each number
        cout << differences[i] << endl;               //this list represents the differences between those smallest values
        finalSum += differences[i];                   //sum of the differences
    }

    cout << "The result of the locationIDs is: " << finalSum << endl;

    /*
    //accessing a specific index
    int index = 0;
    int charIndex = 3;
    if (index >= 0 && index < lines.size()) {
        if (charIndex >= 0 && index < lines.size()) {
            cout << "\nCharacter at line " << index << ", index " << charIndex << ": "
                 << lines[index][charIndex] << endl;
        } else {
            cout << "Invalid Character Index" << endl;
        }
    } else {
        cout << "Invalid Line Index" << endl;
    }*/
    return 0;
}