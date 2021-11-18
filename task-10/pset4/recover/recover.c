#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc !=2){
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        printf("Error occurred while opening th raw file\n");
        return 1;

    }

    typedef uint8_t BYTE;

    BYTE buffer[BLOCK_SIZE];

    size_t bytes_read;
    bool is_first_jpg = false;
    FILE *current_file;
    char currentfilename[100];
    int currentfileno = 0;
    bool foundjpg = false;

    while (true){
        bytes_read = fread(buffer,sizeof(BYTE),BLOCK_SIZE,file);

        if(bytes_read==0){
            break;
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            foundjpg = true;

            if(!is_first_jpg){
                is_first_jpg = true;
            }

            else{
                fclose(current_file);


            }
            sprintf(currentfilename,"%03i.jpg",currentfileno);
            current_file = fopen(currentfilename, "w");
            fwrite(buffer,sizeof(BYTE),bytes_read,current_file);
            currentfileno++;
        }
        else{

            if(foundjpg){

                fwrite(buffer,sizeof(BYTE),bytes_read,current_file);
            }


        }


    }
    fclose(file);
    fclose(current_file);
    return 0;
}