#include <stdio.h>
#include <errno.h>
#include <sstream>
#include <string.h>

#define BUF_SIZE 256

using namespace std;

int string_size_const_char(const char * str){
        //const char * str = "Hello World !";
        int Size = 0;
        while (str[Size] != '\0') Size++;
        return Size;
}

int main(int argc, char *argv[]) {

   

    FILE *in_file, *out_file;
    char rec [BUF_SIZE];

    size_t bytes_in, bytes_out;

    stringstream strs;
    strs << argv [1];
    string temp_str = strs.str();
    char* char_type_argv_1  = (char*) temp_str.c_str();
    printf(char_type_argv_1);

    if (argv[1] == std::string("-D")) {
        printf("Копируем рабочий стол в корень D ");

        string path("\"C:\\Users\\mixxxxx\\Desktop\"");
        string command("dir /a-d ");
        command.append(path);
        const char* final_command = command.c_str();
        //printf(final_command);

        //stringstream ss;
        //ss << int(string_size_const_char(final_command));
        //string str_final_command = ss.str();

        int counter = string_size_const_char(final_command); 

        //std::string ss = std::to_string(couter);

        //printf(ss);

        printf("%d\n", counter);
        printf("%d\n", counter);
        //system(final_command);



        //for (const char *p = final_command; *p; ++p)
        //std::puts(*p);

        /*if (SUCCEEDED(SHGetFolderPath(NULL,CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE, NULL, SHGFP_TYPE_CURRENT,appData))) 
        {
            int Size = 0;
            string pathDesktop;
            while (appData[Size] != '\0') pathDesktop+= appData[Size++];
            pathDesktop+= "\\test.txt";
            printf(pathDesktop);
        }  */  

        return 1;
    }


    if (argc != 3) {
        printf("Использование: main.exe файл1 файл2 ");
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
    printf("Файл успешно скопирован");
    return 0;
}



