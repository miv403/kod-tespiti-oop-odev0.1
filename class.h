#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CodeChecker {

    public:
    CodeChecker(const string&);
    ~CodeChecker();
    void readCode(ifstream&, int);
    bool compareCode();
    bool lenCheck();
    void writeCode(ofstream&);

    private:
    void parseLine(const string& line);
    // vector<string> msg0; // TODO dinamik dizi yap
    int * msg;
    int givenLen;  // givenLen 1 2 3 givenLen 1 2 3
    int msgLen;    // (msg.size() - 2) / 2
    int msgSize; // real size msg.size()
    bool errorChk; // true: no-error
    string line{};

};