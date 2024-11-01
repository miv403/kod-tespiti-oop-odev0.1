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
    int givenLen;  // givenLen 1 2 3 givenLen 1 2 3
    int msgLen;    // (msg.size() - 2) / 2
    bool errorChk; // true: no-error
    string line{};

};