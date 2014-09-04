/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Recovers JPEGs from a forensic image.
 first four bytes
 0xff 0xd8 0xff 0xe0
 0xff 0xd8 0xff 0xe1
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//typedef unsigned char uint8_t;


const int BLOCK_SIZE = 512;

int main(int argc, char* argv[])
{
    // open input file
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open card.raw.\n");
        return 2;
    }

    uint8_t buf[512];

    int counter = 0;
    FILE *fw = NULL;

    // iterate over file content
    // read until end
    // each time each a block, if end the file, will return 0
    // that mean false, will break while loop
    while(fread(buf, BLOCK_SIZE, 1, inptr)){
        // check first four bytes is jpg signature
        if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] == 0xe0 || buf[3] == 0xe1)){
            // in case previous picture file is not close
            // also check writing file is avaible
            // if no permission to write will return NULL
            if (fw != NULL)
            {
                fclose(fw);
            }
            // set up new jpg file
            char filename[8];
            sprintf(filename, "%03d.jpg", counter);

            // open a new jpg file for writing
            fw = fopen(filename, "w");
            counter++;
        }
        // also check writing file is avaible
        // if no permission to write will return NULL
        if (fw != NULL)
        {
            fwrite(buf, BLOCK_SIZE, 1, fw);
        }
    }

    // close output
    if(fw != NULL){
        fclose(fw);
    }
    // close input
    fclose(inptr);
    return 0;
}
