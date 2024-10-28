#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CodeChecker {

    public:
    // CodeChecker();
    // ~CodeChecker();
    bool readCode(ifstream&, int);
    bool compareCode();
    void writeCode(ofstream&);
    vector<string> parseLine(string& line);

    private:
    vector<string> msg;
    int givenLen;
    int msgLen;
    int cpMsgLen; // TODO: implement it!
    bool errorChk; // true: no-error
    string line{};

};