#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

#include "class.h"

#define MAX 250

using namespace std;

bool CodeChecker::readCode(ifstream& file, int max) {

    // 250 (250 x) 250 (250x)
    // 3 + 1 + 250*2 + 3 + 1 + 250*2 - 1
    // = 8 + 1000 - 1 = 1007

    getline(file, line);
    string tmpLine = line;

    msg = parseLine(tmpLine);

    givenLen = stoi(msg.at(0));
    
    if (givenLen > MAX) {
        cerr << "iletinin uzunlugu " 
            << MAX << " sayisindan buyuk olamaz." << endl;
        return false;
    }

    msgLen = (msg.size() - 2) / 2;

    cout << "ileti okundu! ileti uzunlugu: " << msgLen << endl;

    return true;
}

bool CodeChecker::compareCode(){

    if(givenLen != msgLen) {
        cerr << "iletinin uzunlugu belirtilen uzunluk ile esit degil: ";
        cerr << givenLen << "/" << (msg.size() - 2) / 2 << endl;
        return false;
    }

    for(size_t i = 0; i < msgLen; ++i){
        if(msg.at(i) != msg.at(i + msgLen + 1)){
            cerr << msg.at(i) <<"@[" << i << "] != "
                << msg.at(i + msgLen + 1) << "@[" << i <<
                                                        "+" << msgLen + 1 << "]"
                << endl;

            return false;
        }
    }

    cout << "ileti hata sinamasini basariyla gecti." << endl;
    cout << "okunan karakter sayisi: " << givenLen << endl;

    return true;
}

vector<string> CodeChecker::parseLine(string& line) {
    vector<string> tokens;
    // alınan satırın boşluk ile ayrılarak vektöre eklenmesi
    size_t pos = 0;
    string token;
    string delimiter = " ";
    while ((pos = line.find(delimiter)) != string::npos) {
        token = line.substr(0, pos);
        tokens.push_back(token);
        line.erase(0, pos + delimiter.length());
    }
    tokens.push_back(line);

    return tokens;
}