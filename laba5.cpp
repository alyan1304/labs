#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, int> findRepeat(vector<string> block) {
string repeatStr;
int counter(0);
map<string, int> aboutRepeats;
for(string str: block) {
    counter = 0;
    for(string otherStr: block) {
        if (str == otherStr && str != repeatStr) {
            counter++;
        }
    }
    if (counter > 1) {
        repeatStr = str;
        aboutRepeats[str] = counter;
    }
}
if (!aboutRepeats.empty()) {
    return aboutRepeats;
} else {
    return {{"lines", 0}};
}
}

int main() {
    string strToCheck;
    ifstream fin2("outfile.txt");
    fin2 >> strToCheck;
    fin2.close();
    ofstream fout("outfile.txt");
    
    //if (strToCheck == "\0") {
     //   ofstream fout("new.txt"); 
    //} else {
     //  ofstream fout("outfile.txt");
    //}

    string str;
    ifstream fin ("infile.txt");
    int lineIndex = 0;
    int commIndex = 0;
    int blockIndex = 0;
    vector <string> block;
    while (getline(fin, str)) {
        lineIndex += 1;
        if (str.find(' //') != -1) {
            if (commIndex + 1 == lineIndex){    
                block.push_back(str);   
            } else {
                if (!block.empty()) {
                    fout << "In the group of comments which starts at line " << blockIndex << ", \n";
                    for (const auto& element: findRepeat(block)) {
                        fout << "there are " << element.second << " repeats of ";
                        fout << element.first << endl;
                    }
                    block.clear();
                }
                block.push_back(str);
                blockIndex = lineIndex;
            }
        commIndex = lineIndex;
        }  
    }
    if (!block.empty()) {
                    fout << "In the group of comments which starts at line " << blockIndex << ", \n";
                    for (const auto& element: findRepeat(block)) {
                        fout << "there are " << element.second << " repeats of ";
                        fout << element.first << endl;
                    }
    }
    fout.close();
}