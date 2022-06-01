#include "decoding.h"

extern std::ifstream fin;
extern std::ofstream fout;

void decoding()
{
    unsigned char current = fin.get();

    int cont = 0;

    while (!fin.eof())
    {
        cont++;
        fout << current;

        if (cont == 3)
        {
            for (int i = fin.get(); i > 0; i--)
            {
                fout << current;
            }
            cont = 0;
        }

        if (current != fin.peek())
            cont = 0;

        current = fin.get();
    }
}