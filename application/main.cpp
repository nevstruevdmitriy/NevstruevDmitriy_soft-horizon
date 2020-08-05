#include <solution.h>
#include <cstdio>

int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("incorrect number of arguments\n");
        return 0;
    }

    Solution solution(argv[1], argv[2], argv[3]);
    return 0;
}