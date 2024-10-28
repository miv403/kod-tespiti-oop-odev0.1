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
    vector<string> parseLine(string& line);

    private:
    vector<string> msg;
    int givenLen;
    int msgLen;
    string line{};

};