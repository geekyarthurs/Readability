#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
//declaring the functions for use
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main()
{
    //getting input
    float c_n, c_w, c_s;
    string text = get_string("text: ");
    //calling the functions
    c_n = count_letters(text);
    c_w = count_words(text);
    c_s = count_sentences(text);
    //convering the given value using Coleman-Liau index
    float l = (c_n/c_w) * 100;
    float s = (c_s/c_w) * 100;
    float index = (0.0588 * l) - (0.296 * s) - 15.8;
    //giving the output
    if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else if (index>16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
    return 0;
}


//creating a function for counting all letters
int count_letters(string text)
{
    int n=0, i=0;
    while (text[i] !='\0')
    {
        if ((text[i]>=65 && text[i]<=90) || (text[i]>=97 && text[i]<=122))
        {
            n++;
        }
        i++;
    }
    return n;
}


//creating a function for counting all world
int count_words(string text)
{
    int i = 0, n = 1;
    while (text[i] != '\0')
    {
        if (text[i] == 32)
        {
            n++;
        }
        i++;
    }
    return n;
}


//creating a function for counting all number
int count_sentences(string text)
{
    int i = 0, n = 0;
    while (text[i] != '\0')
    {
        if (text[i] == 46 || text[i] ==63 || text[i] == 33)
        {
            n++;
        }
        i++;
    }
    return n;
}
