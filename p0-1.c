#include <stdio.h>
#include <stdlib.h>

struct finalCounts
{
    int letters[26];
};

void checkChars(int n, struct finalCounts *f)
{
    if(n == 65 || n == 97) // a
    {
        f->letters[0]++;
    }

    else if(n == 66 || n == 98) // b
    {
        f->letters[1]++;
    }

    else if(n == 67 || n == 99) // c
    {
        f->letters[2]++;
    }

    else if(n == 68 || n == 100) // d
    {
        f->letters[3]++;
    }

    else if(n == 69 || n == 101) // e
    {
        f->letters[4]++;
    }

    else if(n == 70 || n == 102) // f
    {
        f->letters[5]++;
    }

    else if(n == 71 || n == 103) // g
    {
        f->letters[6]++;
    }

    else if(n == 72 || n == 104) // h
    {
        f->letters[7]++;
    }

    else if(n == 73 || n == 105) // i
    {
        f->letters[8]++;
    }

    else if(n == 74 || n == 106) // j
    {
        f->letters[9]++;
    }

    else if(n == 75 || n == 107) // k
    {
        f->letters[10]++;
    }

    else if(n == 76 || n == 108) // l
    {
        f->letters[11]++;
    }

    else if(n == 77 || n == 109) // m
    {
        f->letters[12]++;
    }

    else if(n == 78 || n == 110) // n
    {
        f->letters[13]++;
    }

    else if(n == 79 || n == 111) // o
    {
        f->letters[14]++;
    }

    else if(n == 80 || n == 112) // p
    {
        f->letters[15]++;
    }

    else if(n == 81 || n == 113) // q
    {
        f->letters[16]++;
    }

    else if(n == 82 || n == 114) // r
    {
        f->letters[17]++;
    }

    else if(n == 83 || n == 115) // s
    {
        f->letters[18]++;
    }

    else if(n == 84 || n == 116) // t
    {
        f->letters[19]++;
    }

    else if(n == 85 || n == 117) // u
    {
        f->letters[20]++;
    }

    else if(n == 86 || n == 118) // v
    {
        f->letters[21]++;
    }

    else if(n == 87 || n == 119) // w
    {
        f->letters[22]++;
    }

    else if(n == 88 || n == 120) // x
    {
        f->letters[23]++;
    }

    else if(n == 89 || n == 121) // y
    {
        f->letters[24]++;
    }

    else if(n == 90 || n == 122) // z
    {
        f->letters[25]++;
    }

    else
    {
        //for non-letter characters do nothing
    }
}

int main()
{
    struct finalCounts struct1;
    char *filename = "alice.txt";
    FILE *fp = fopen(filename, "r");    //Open the file in read mode/with read permissions
    int ch;
    //printf("hello?\n");
    while((ch = fgetc(fp)) != EOF)
    {
        checkChars(ch, &struct1);
    }

    printf("Letter Totals:\n");
    for(int i = 0; i < 26; i++)
    {
        int letterNum = i + 65;
        printf("%c: %d\n", letterNum, struct1.letters[i]);
    }

    fclose(fp);
    return 0;
}