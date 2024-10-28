#include <fstream>
#include "./functions.cpp"

#define INPUT_FILE "./data/girdi.in"
#define OUTPUT_FILE "./data/cikti.out"

int main() {
    // command line args
    


    CodeChecker chkr;

    ifstream input;
    ofstream output;
    input.open(INPUT_FILE);

    if(!input.is_open()){
        cerr << INPUT_FILE << " bulunamadi." << endl;
        return 1;
    }

    output.open(OUTPUT_FILE);

    bool ret = chkr.readCode(input, MAX);

    if(ret) {
        ret = chkr.compareCode();
    }
    
    chkr.writeCode(output);

    return ret ? 0 : 1;

}