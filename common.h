#ifndef COMMON_H_
#define COMMON_H_

#include <stdio.h>
#include <stdlib.h>

char *read_file_to_str(const char *path)
{
    FILE *file;
    char *str;
    size_t size;

    file = fopen(path, "r");
    fseek(file, 0L, SEEK_END);
    size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    str = (char*) malloc(size + 1);
    str[size] = '\0';
    fread(str, 1, size, file);
    fclose(file);
    return str;
}

#endif // COMMON_H_
