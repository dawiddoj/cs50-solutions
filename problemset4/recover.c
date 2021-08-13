#include <stdio.h>

// program recovers jpg files

const int BLOCK = 512; // constant block of 512 B to read and write to output file

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: ./recover [file name]\n");
        return 1;
    }
    char *infile = argv[1];
    FILE *input = fopen(infile, "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    unsigned char buffer[BLOCK];
    FILE *output = NULL;
    char imagename[7];
    int counter = 0;
    while (fread(buffer, BLOCK, 1, input) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 
            && buffer[3] <= 0xef) // checking for header of jpg
        {
            if (counter > 0)
            {
                fclose(output);
            }
            sprintf(imagename, "%03d.jpg", counter); // naming file 
            output = fopen(imagename, "w");
            counter++;
        }
        if (output != NULL)
        {
            fwrite(buffer, BLOCK, 1, output);
        }
    }
    fclose(output);
    fclose(input);
    return 0;
}