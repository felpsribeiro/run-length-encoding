#include "encoding.h"

extern std::ifstream fin;
extern std::ofstream fout;

void encoding()
{
    unsigned char current = fin.get();

    int cont = 0;
    unsigned char charCont;

    while (!fin.eof())
    {
        cont++;
        fout << current;

        if (cont == 3)
        {
            while (current != EOF && current == fin.peek() && cont <= 257)
            {
                cont++;
                current = fin.get();
            }
            charCont = cont - 3;
            fout << charCont;
            cont = 0;
        }

        if (current != fin.peek())
            cont = 0;

        current = fin.get();
    }
}