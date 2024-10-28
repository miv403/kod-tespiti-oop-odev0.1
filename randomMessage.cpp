#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

    int MAX = std::stoi(argv[1]);

    std::srand(std::time(nullptr));

    std::ofstream file;
    file.open("./data/random.msg");
    file << MAX;

    for(int i = 0; i < MAX; ++i){
        file << " " << std::rand() % 10;
    }

    file.close();
    return 0;
}
