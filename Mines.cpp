
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib> 

using namespace std;
int main()
{
    int n, m;
    vector<string> strings;
    std::cin >> m;
    cin.ignore();
    std::cin >> n;
    cin.ignore();
    int x = 0, y = 0, count = 5;;

    for (int i = 0; i < n; ++i)
    {        
        std::string input;
        for (int j = 0; j < m; j++)input+= '.';
        if (i % 2 == 0) input[rand() % m] = 'x';
        strings.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (strings[i][j] == 'x')
            {
                {
                    for (int y = (i - 1); y < (i + 2); y++)
                    {
                        if (y >= 0 && y < n)
                        {
                            for (int x = (j - 1); x < (j + 2); x++)
                            {
                                if (x >= 0 && x < m)
                                {
                                    if (strings[y][x] == '.')strings[y][x] = '1';
                                    else if (strings[y][x] != 'x')
                                    {
                                        int counter = strings[y][x] - '0';
                                        counter += 1;
                                        strings[y][x] = counter + '0';
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int g = 0; g < m; g++)
            if (strings[i][g] == 'x') strings[i][g] = '.';

    for (int i = 0; i < n; ++i)
    {
        cout << strings[i] << endl;
    }
    return 0;
}