#include <string.h>
#include <fstream>
#include <iostream>
#include "encoding.h"
using namespace std;

// arquivo de entrada
ifstream fin;

// arquivo de saída
ofstream fout;

void messageHelp();

// programa pode receber nomes de arquivos
int main(int argc, char **argv)
{
    // --help
    if (argc == 2)
    {
        if (argv[1][0] == '-')
        {
            if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-H"))
                messageHelp();

            else
                cout << "Comando inválido, use \"rle --help\" para descobrir os comandos válidos.\n";

            exit(EXIT_FAILURE);
        }
    }
    else if (argc == 4 && (argv[1][1] == 'c' || argv[1][1] == 'x'))
    {
        fin.open(argv[2]);

        // falha na abertura do arquivo
        if (!fin.is_open())
        {
            cout << "Falha na abertura do arquivo \'" << argv[2] << "\'.\n";
            cout << "Verifique se o nome está correto, ou se é protegido para leitura.\n\n";
            exit(EXIT_FAILURE);
        }

        cout << endl;

        fout.open(argv[3]);

        // comprimir
        if (argv[1][1] == 'c')
        {
            encoding();
        }
        // descomprimir
        else if (argv[1][1] == 'x')
        {
            cout << "Descomprimindo\n";
        }

        fin.close();
        fout.close();
        exit(EXIT_SUCCESS);
    }

    cout << "Falha na execução do compactador...\n";
    cout << "Use \"rle --help\" para saber como utilizar-lo.\n\n";
    exit(EXIT_FAILURE);
}

void messageHelp()
{
    cout << "Uso\n\n"

         << "   rle -c <nome-do-arquivo-de-entrada> <nome-do-arquivo-de-saida>\n"
         << "   Compactar um arquivo.\n\n"

         << "  	ou\n\n"

         << "   rle -x <nome-do-arquivo-de-entrada> <nome-do-arquivo-de-saida>\n"
         << "   Descompactar um arquivo.\n\n"

         << "Opções\n\n"

         << "	--help, -H		Imprima as informações de uso e saia.\n"

         << "Para mais informações sobre o compactador, consulte README.md em \"https://github.com/felpsribeiro/run-length-encoding\".\n\n";
}
