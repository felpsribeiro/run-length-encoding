#include "encoding.h"

extern std::ifstream fin;
extern std::ofstream fout;

void encoding()
{
    char current = fin.get();

    int cont = 0;
    unsigned char charCont;

    while (current != EOF)
    {
        cont++;
        fout << current;

        if (cont == 3)
        {
            while (current != EOF && current == fin.peek() && cont <= 255)
            {
                cont++;
                current = fin.get();
            }
            charCont = cont - 3;
            fout << charCont;
        }

        if (current != fin.peek())
            cont = 0;

        current = fin.get();
    }
}