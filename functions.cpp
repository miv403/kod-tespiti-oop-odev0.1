#include <iostream>
#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "class.h"

#define MAX 250

using namespace std;

CodeChecker::CodeChecker(const string& path) {
    ifstream file;
    file.open(path);
    msgSize = 0;
    getline(file,line);
    stringstream tokens(line);
    while(getline(tokens, line, ' ')) { msgSize++; }
    file.close();

    msg = new int[msgSize];
}

CodeChecker::~CodeChecker() {
    delete[] msg;
}

void CodeChecker::readCode(ifstream& file, int max) {

    getline(file, line);
    string tmpLine = line;

    parseLine(tmpLine);

    cout << "ileti okundu." << endl;

}

bool CodeChecker::lenCheck() {

    if(msgLen % 2 != 0) {
        msgLen = (msgSize - 3) / 2;
        cerr << "gizli kod ile kopyanin uzunlugu birbirine esit degil." << endl;
        cerr << "beklenen ileti uzunlugu: " << msgLen << endl;
        errorChk = false;
        return false;
    }

    msgLen = (msgSize - 2) / 2;
    givenLen = msg[0];

    if (givenLen > MAX) {
        cerr << "iletinin belirtilen uzunlugu "
             << MAX << " sayisindan buyuk. "
             << "uzunluk: " << givenLen << endl;
        errorChk = false;
        return false;
    } else if(msgLen > MAX) {
        cerr << "iletinin uzunlugu "
             << MAX << " sayisindan buyuk olamaz." << endl;
        errorChk = false;
        return false;
    } else if(givenLen != msgLen) {
        cerr << "iletinin uzunlugu belirtilen uzunluk ile esit degil: ";
        cerr << msgLen << "/" << givenLen  << endl;
        errorChk = false;
        return false;
    }

    cout << "ileti uzunlugu: " << msgLen << endl;


    errorChk = true;

    return true;
}

bool CodeChecker::compareCode() {

    for(size_t i = 0; i <= msgLen; ++i) {
        if(msg[i] != msg[i + msgLen + 1]) {
            cerr << "iletide uyusmazlik tespit edildi." << endl;
            cerr << msg[i] <<"@[" << i << "] != "
                 << msg[i + msgLen + 1] << "@[" << i <<
                 "+" << msgLen + 1 << "]"
                 << endl;
            errorChk = false;
            return false;
        }
    }
    errorChk = true;

    cout << "ileti hata sinamasini basariyla gecti." << endl;

    return true;
}


void CodeChecker::writeCode(ofstream& file) {

    file << setw(5) << right << "Kod";
    file << setw(7) << right << "Kopya" << endl;

    for(int i = 0; i <= msgLen; ++i) {
        file << setw(5) << right << msg[i];
        file << setw(7) << right << msg[i + msgLen + 1] << endl;
    }

    file << endl << "ileti " << (errorChk ? "hatasiz" : "hatali") << " iletildi.";

}

vector<string> parseLine(string& line) {

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

void CodeChecker::parseLine(const string&line) {
    
    stringstream tokens(line);
    string hucre;

    for(size_t i = 0; i < msgSize; i++) {
        getline(tokens, hucre, ' ');
        msg[i] = stoi(hucre);
    }
}