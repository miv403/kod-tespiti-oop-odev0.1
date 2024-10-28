#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CodeChecker {

    public:
    // CodeChecker();
    // ~CodeChecker();
    void readCode(ifstream&, int);
    bool compareCode();
    bool lenCheck();
    void writeCode(ofstream&);
    vector<string> parseLine(string& line);

    private:
    vector<string> msg;
    int givenLen;
    int msgLen;
    // int cpMsgLen; // TODO: implement it! (KILLED)
    bool errorChk; // true: no-error
    string line{};

};