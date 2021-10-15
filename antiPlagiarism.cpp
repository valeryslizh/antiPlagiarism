#include <iostream>
#include <string>
#include <cstring> 
#include "md5.h"

using namespace std;

const int N = 256;

bool isSeparator(char c);
char tolowerPtr(char p);
bool isUnion(string word);
double antiPlagiarism(string text, string fragment);
int listWord(string* mas,string text);

int main()
{
    string text = "Hi guys please go to the store and buy some snacks for us to eat smth or leave because if we eat while thinking it always goes wrong.";
    string fragment = "Hi guys please go to the store and buy some snacks for us to eat smth or leave because if we eat while thinking it always goes wrong.";
    
    cout << antiPlagiarism(text, fragment);
    
    return 0;
}

double antiPlagiarism(string text, string fragment) 
{
    string masWordText[N];
    string masWordFragment[N];

    int textSize = listWord(masWordText, text);
    int fragmentSize = listWord(masWordFragment, fragment);

    int counter = 0;
    double uniquenessPercentage;

    for (int i = 0; i < fragmentSize - 2; i++)
    {
        string fragmentSelection = masWordFragment[i] + masWordFragment[i + 1] + masWordFragment[i + 2];

        for (int k = 0; k < textSize - 2; k++)
        {
            string textSelection = masWordText[k] + masWordText[k + 1] + masWordText[k + 2];

            if (md5(textSelection) == md5(fragmentSelection))
            {
                counter++;
            }
        }
    }

    uniquenessPercentage = round(((double)counter / (fragmentSize - 2) * 100) * 100) / 100;

    return  uniquenessPercentage;
}

// Не коректное название, нужно подумать
// Записывает в массив слова, но возвращает длинну масивы 
// Не нравится мне, но пока ничего другого не придумал
int listWord(string* mas, string text)
{
    char word[N] = "\0";

    int i = 0;
    int iw = 0;
    int j = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isSeparator(text[i]))
        {
            word[iw] = tolowerPtr(text[i]);
            iw++;

            if (isSeparator(text[i + 1]) or text[i + 1] == '\0')
            {
                word[iw] = '\0';
                if (isUnion(word)) {
                    mas[j] = word;
                    j++;
                }
                iw = 0;
            }
        }
    }

    return j;

}

bool isSeparator(char c)
{
    char separatorArr[] = " .,!?;:-+{}()[]*@%$^&#`~_=<>/|'\"\\“”";

    for (int i = 0; separatorArr[i] != '\0'; i++)
    {
        if (separatorArr[i] == c)
            return true;
    }
    return false;
}

bool isUnion(string word) 
{
    string unions[15] = { "and", "as", "or", "then", "but", "if", "till", "how", "so", "because", "unless", "until", "although", "however", "whenever" };

    for (int i = 0; i < 15; i++) 
    {
        if (unions[i] == word) {
            return false;
        }        
    }
    return true;
}

char tolowerPtr(char p)
{
    switch (p)
    {
    case 'A': p = 'a'; return p;
    case 'B': p = 'b'; return p;
    case 'C': p = 'c'; return p;
    case 'D': p = 'd'; return p;
    case 'E': p = 'e'; return p;
    case 'F': p = 'f'; return p;
    case 'G': p = 'g'; return p;
    case 'H': p = 'h'; return p;
    case 'I': p = 'i'; return p;
    case 'J': p = 'j'; return p;
    case 'K': p = 'k'; return p;
    case 'L': p = 'l'; return p;
    case 'M': p = 'm'; return p;
    case 'N': p = 'n'; return p;
    case 'O': p = 'o'; return p;
    case 'P': p = 'p'; return p;
    case 'Q': p = 'q'; return p;
    case 'R': p = 'r'; return p;
    case 'S': p = 's'; return p;
    case 'T': p = 't'; return p;
    case 'U': p = 'u'; return p;
    case 'V': p = 'v'; return p;
    case 'W': p = 'w'; return p;
    case 'X': p = 'x'; return p;
    case 'Y': p = 'y'; return p;
    case 'Z': p = 'z'; return p;
    };

    return p;
}