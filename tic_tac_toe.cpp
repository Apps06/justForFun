// unfinished and highly inefficient code
#include <iostream>
using namespace std;

int main()
{

    char c[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            c[i][j] = '_';
        }
    }

    char xo;
    int pos1, pos2, count = 0;
    while (count <= 9)
    {
        cout << "Enter the position 1 where you want to enter you character: " << endl;
        cin >> pos1;
        cout << "Enter the position 2 where you want to enter you character: " << endl;
        cin >> pos2;
        cout << "Enter the character that you want to enter: " << endl;
        cin >> xo;

        c[pos1 - 1][pos2 - 1] = xo;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << c[i][j] << " | ";

                if (j == 2)
                {
                    cout << "\n\n";
                    break;
                }
            }

            cout << "\n";
        }
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         if (c[i][j])
        //     }
        // }
    }

    count++;
    return 0;
}