#include "common.h"

#include <ctype.h>
#include <string.h>

const char *digits[] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

int part1(const char *path)
{
    char *str = read_file_to_str(path);
    char *line = strtok(str, "\n");
    int sum = 0;
    while (line != NULL) {
        int first = 0;
        int last = 0;
        for(const char *c = line; *c != '\0'; c++) {
            if (isdigit(*c)) {
                if (!first) {
                    first = *c - '0';
                }
                last = *c - '0';
            }
        }
        sum += first * 10 + last;
        line = strtok(NULL, "\n");
    }
    return sum;
}

int part2(const char *path)
{
    char *str = read_file_to_str(path);
    char *line = strtok(str, "\n");
    int sum = 0;
    while (line != NULL) {
        int first = 0;
        int last = 0;
        for(const char *c = line; *c != '\0'; c++) {
            if (isdigit(*c)) {
                if (!first) {
                    first = *c - '0';
                }
                last = *c - '0';
            } else {
                for (int i=0; i<9; i++) {
                    if (strncmp(c, digits[i], strlen(digits[i])) == 0) {
                        if (!first) {
                            first = i+1;
                        }
                        last = i+1;
                        break;
                    }
                }
            }
        }
        sum += first * 10 + last;
        line = strtok(NULL, "\n");
    }
    return sum;
}

int main()
{
    printf("part1 example: %d\n", part1("input/day_01_part1_example.txt"));
    printf("part1: %d\n", part1("input/day_01.txt"));
    printf("part2 example: %d\n", part2("input/day_01_part2_example.txt"));
    printf("part2: %d\n", part2("input/day_01.txt"));
    return 0;
}
