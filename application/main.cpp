#include <solution.h>
#include <cstdio>
#include <ctime>
#include <unistd.h>

int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("incorrect number of arguments\n");
        return 0;
    }

    Solution solution(argv[1], argv[2], argv[3]);
    
    while (true) {
        solution.updateDirrectory(argv[1]);
        sleep(1);
    }
    
    return 0;
}