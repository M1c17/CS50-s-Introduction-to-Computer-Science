#include <stdio.h>
#include <stdlib.h>

#define BLOCK_S 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    char *card_raw = argv[1];
    //open file
    //input file pointer to be read
    FILE *input_file = fopen(card_raw, "r");
    if(!input_file)
    {
        fprintf(stderr, "Cannot read the file %s\n", card_raw);
        return 2;
    }

    //counter jpeg found
    int count_jpeg = 0;
    //Flag to check if first jpeg is already found
    int found_jpeg = 0;
    //output file pointer to be written
    FILE *output_file = NULL;
    //creating size of filenames of jpeg
    char filename[8];

    //read first three characters
    //buffer = (HDD)
    BYTE buffer[BLOCK_S];
    while (fread(buffer, BLOCK_S, 1, input_file) == 1)
    {
        // Looking for beginning of a JPEG
            // Check first three bytes
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            //Last Byte: 0xe0, 0xe1, 0xe2,....,0xef
            {
                //check if jpeg has already been found
                if (found_jpeg == 1)
                {
                    fclose(output_file);
                }
                else
                {
                    // mark flag a jpeg has been found
                    found_jpeg = 1;
                }
                // Naming the jpeg file
                sprintf(title, "%03d.jpg", count_jpeg++);
                // open for write
                output_file = fopen(filename, "w");
            }
            // write 512 bytes until a new JPEG is found
            if (found_jpeg == 1)
            {
                fwrite(&buffer, 512, 1, output_file);
            }
    }
    // close file
    if (output_file != NULL)
    {
        fclose(output_file);
    }
    fclose(input_file);
    return 0;
}
