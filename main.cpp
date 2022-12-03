#include <stdio.h>
#include <errno.h>
#include <sstream>
#include <string.h>
#define BUF_SIZE 256

using namespace std;

int main(int argc, char *argv[]) {

    FILE *in_file, *out_file;
    char rec [BUF_SIZE];

    size_t bytes_in, bytes_out;

    stringstream strs;
    strs << argc;
    string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();
    printf(char_type);
    int i=0;
    for(i=0;i<argc;i++)
    {
        printf("%s",argv[i]);
        printf("\n");
    }
  

    if (argc != 3) {
        printf("Использование: срС файл1 файл2 ");
        return 1;
    }

    in_file = fopen(argv [1], "rb");

    if (in_file == NULL) {
        perror(argv[1]);
        return 2;
    }

    out_file = fopen(argv [2], "wb");

    if (out_file == NULL) {
    perror(argv [2]);
    return 3;
    }

    /* Обработать входной файл по одной записи за один раз. */
    while ((bytes_in = fread(rec, 1, BUF_SIZE, in_file)) > 0) {
        bytes_out = fwrite(rec, 1, bytes_in, out_file);

        if (bytes_out != bytes_in) {
            perror("Неустранимая ошибка записи.");
            return 4;
        }

    }

    fclose (in_file);
    fclose (out_file);
    return 0;
}