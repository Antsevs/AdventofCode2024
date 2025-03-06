//
// Created by Anthony Sevarino on 2/20/2025.
//

//
// Created by Anthony Sevarino on 2/20/2025.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>

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

    while (!listLeft.empty() || !listRight.empty()) {
        int minLeftIndex = distance(listLeft.begin(), min_element(listLeft.begin(), listLeft.end())); //distance calculates diff between points
        int minRightIndex = distance(listRight.begin(), min_element(listRight.begin(), listRight.end()));

        // calculate the distance between the smallest elements
        listDistance += abs(listLeft[minLeftIndex] - listRight[minRightIndex]);

        // remove the smallest elements from both lists using the calculated indices
        listLeft.erase(listLeft.begin() + minLeftIndex);
        listRight.erase(listRight.begin() + minRightIndex);
    }


    cout << listDistance << endl;
    return 0;
}
