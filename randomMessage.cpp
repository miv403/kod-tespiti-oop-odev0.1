#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

#define MAX 250

int main() {

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
