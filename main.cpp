#include <fstream>
#include "./functions.cpp"

#define INPUT_FILE "./girdi.in"
#define OUTPUT_FILE "./cikti.out"

int main() {
    // command line args
    


    CodeChecker chkr;

    ifstream input;
    input.open(INPUT_FILE);

    bool ret = chkr.readCode(input, MAX);

    if(ret != true) {
        return (ret - 1);
    }

    ret = chkr.compareCode();

    return (ret - 1);

}