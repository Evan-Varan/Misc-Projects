// WordLengthMode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int WordLengthMode(std::string words[], int length);

int main()
{
    std::string words[] = { "abc", "asdfasfd", "asf", "safdasfadsfa", "gsd", "a", "b", "c"};
    //std::string words[] = { "hello", "there", "beautiful" };
    int result = WordLengthMode(words, 8);

    std::cout << result;
}

int WordLengthMode(std::string words[], int length) {
    int holder_array[99];

    // initialize array
    for (int k = 0; k < 99; k++)
    {
        holder_array[k] = 0;
    }

    // fill in lengths
    for (int i = 0; i < length; i++)
    {
        holder_array[words[i].length()] ++;
    }

    int largest_idx = 0;
    int largest_count = 0;

    for (int i = 0; i < 99; i++)
    {
        if (holder_array[i] > holder_array[largest_idx])
        {
            largest_idx = i;
            largest_count = 1;
        }
        
        else if (holder_array[i] == holder_array[largest_idx])
        {
            largest_count++;
        }
    }

    if (largest_count > 1)
    {
        return -1;
    }
    else
    {
        return largest_idx;
    }
}
