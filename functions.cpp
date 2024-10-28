#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

#include "class.h"

#define MAX 250

using namespace std;

bool CodeChecker::readCode(ifstream& file, int max) {

    getline(file, line);
    string tmpLine = line;

    msg = parseLine(tmpLine);
    
    givenLen = stoi(msg.at(0));
    
    if(msg.size() % 2 != 0){ // FIXME: daha iyi bir çözüm bulunabilir
        msgLen = (msg.size() - 3) / 2;
        cerr << "ileti asimetrik. beklenen karakter sayisi: " << msgLen << endl;
        errorChk = false;
        return false;
    }

    msgLen = (msg.size() - 2) / 2;
    
    if (givenLen > MAX) {
        cerr << "iletinin belirtilen uzunlugu "
        << MAX << " sayisindan buyuk: " << givenLen << endl;
        errorChk = false;
        return false;
    }else if(msgLen > MAX) {
        cerr << "iletinin uzunlugu " 
            << MAX << " sayisindan buyuk olamaz." << endl;
        errorChk = false;
        return false;
    }


    cout << "ileti okundu! ileti uzunlugu: " << msgLen << endl;

    errorChk = true;
    return true;
}

bool CodeChecker::compareCode(){

    if(givenLen != msgLen) {
        cerr << "iletinin uzunlugu belirtilen uzunluk ile esit degil: ";
        cerr << givenLen << "/" << msgLen << endl;
        errorChk = false;
        return false;
    }

    for(size_t i = 0; i <= msgLen; ++i){
        if(msg.at(i) != msg.at(i + msgLen + 1)){
            cerr << msg.at(i) <<"@[" << i << "] != "
                << msg.at(i + msgLen + 1) << "@[" << i <<
                                                        "+" << msgLen + 1 << "]"
                << endl;
            errorChk = false;
            return false;
        }
    }
    errorChk = true;

    cout << "ileti hata sinamasini basariyla gecti." << endl;
    cout << "okunan karakter sayisi: " << givenLen << endl;

    return true;
}

void CodeChecker::writeCode(ofstream& file){

    file << setw(5) << right << "Kod";
    file << setw(7) << right << "Kopya" << endl;

    for(int i = 0; i <= msgLen; ++i){
        file << setw(5) << right << msg.at(i);
        file << setw(7) << right << msg.at(i + msgLen + 1) << endl;
    }

    file << endl << "ileti " << (errorChk ? "hatasiz" : "hatali") << " iletildi.";
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