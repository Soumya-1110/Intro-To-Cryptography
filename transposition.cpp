#include<bits/stdc++.h>
using namespace std;

// Key for Columnar Transposition
string const key = "CRYPT";
map<int, int> keyMap;

void setPermutationOrder()
{
    // Add the permutation order into map
    for (int i = 0; i < key.length(); i++)
    {
        keyMap[key[i]] = i;
    }
}

// Encryption
string encryptMessage(string msg)
{
    int row, col, j;
    string cipher = "";

    /* calculate column of the matrix */
    col = key.length();

    /* calculate Maximum row of the matrix */
    row = msg.length() / col;

    if (msg.length() % col)
        row += 1;

    char matrix[row][col];

    for (int i = 0, k = 0; i < row; i++)
    {
        for (int j = 0; j < col; )
        {
            if (msg[k] == '\0')
            {
                /* Adding the padding character '_' */
                matrix[i][j] = '_';
                j++;
            }

            if (isalpha(msg[k]) || msg[k] == ' ')
            {
                /* Adding only space and alphabet into matrix */
                matrix[i][j] = msg[k];
                j++;
            }

            k++;
        }
    }

    for (map<int, int>::iterator it = keyMap.begin(); it != keyMap.end(); ++it)
    {
        j = it->second;

        // getting cipher text from matrix column-wise using permuted key
        for (int i = 0; i < row; i++)
        {
            if (isalpha(matrix[i][j]) == ' ' || matrix[i][j] == '_')
                cipher += matrix[i][j];
        }
    }

    return cipher;
}
