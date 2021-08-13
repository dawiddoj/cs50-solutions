#include <stdio.h>

// program recovers jpg files

const int BLOCK = 512; // constant block of 512 B to read and write to output file

int main(int argc, char *argv[])
{
    if (argc < 2) // checking if there is 2 args
    {
        fprintf(stderr, "Usage: ./recover [file name]\n");
        return 1;
    }
    char *infile = argv[1]; // assigning name infile to argument given in user input
    FILE *input = fopen(infile, "r"); // input is opened
    if (input == NULL) // making sure that file is opened right
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    unsigned char buffer[BLOCK]; // char of size 512 where we store and write from to output file
    FILE *output = NULL;
    char imagename[7]; // for purpose of naming file right
    int counter = 0; // up
    while (fread(buffer, BLOCK, 1, input) == 1) // while loop reading until there is nothing to read
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 
            && buffer[3] <= 0xef) // checking for header of jpg
        {
            if (counter > 0)
            {
                fclose(output);
            }
            sprintf(imagename, "%03d.jpg", counter); // naming file 
            output = fopen(imagename, "w"); // making output file for jpg
            counter++;
        }
        if (output != NULL)
        {
            fwrite(buffer, BLOCK, 1, output);
        }
    }
    fclose(output); // closing files
    fclose(input);
    return 0;
}