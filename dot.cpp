#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define SIZE 10000

using namespace std;

char arr[SIZE] = {97};
char *ptr = arr;

int main(int argc, char *argv[])
{
    srand((unsigned)time(NULL));
    string line;
    const char *reading;
    do {
        getline(cin, line);
        reading = line.c_str();
        cout << "**start**" << endl;
        while (*reading)
        {
            if (*reading == '.')
            {
                switch (rand() % 7)
                {
                    case 0:
                        if (ptr - arr < SIZE - 1) ++ptr;
                        break;
                    case 1:
                        if (ptr - arr > 0) --ptr;
                        break;
                    case 2:
                        ++*ptr;
                        break;
                    case 3:
                        --*ptr;
                        break;
                    case 4:
                        putchar(*ptr);
                        break;
                    case 5:
                        *ptr = getchar();
                        break;
                    case 6:
                        reading = line.c_str() + rand() % (reading - line.c_str() + 1);
                        break;
                }
            }
            ++reading;
        }
        cout << "**end**" << endl;
    } while (line != "");
    return 0;
}