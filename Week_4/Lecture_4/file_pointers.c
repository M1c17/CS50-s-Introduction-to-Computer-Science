#include <stdio.h>
#include <cs50.h>


//the ability to get characters from files, if wrapped 
//in a loop, means we could read all the characters from a file and
// print them to the screen, one by one

char ch;
while((ch = fgetc(ptr)) != EOF)
{
    printf("%c", ch);
}


char ch;
while((ch = fputc(ptr)) != EOF)
{

}


int arr[10];
fread(arr, sizeof(int), 10, ptr);

double* arr2 = malloc(sizeof(double) * 80);
fread(arr2, sizeof(double), 80, ptr);

char c;
fread(&c, sizeof(char), 1, ptr);

//fwrite()
int arr[10];
fwrite(arr, sizeof(int), 10, ptr);

double* arr2 = malloc(sizeof(double) * 80);
fwrite(arr2, sizeof(double), 80, ptr);

char c;
fwrite(&c, sizeof(char), 1, ptr);