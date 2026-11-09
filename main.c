#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"

#ifdef _WIN32
#include <windows.h>
#endif

#define MSG_OK   "expressão sem erro sintático."
#define MSG_ERRO "expressão com erro sintático."

extern FILE *yyin;

int main(int argc, char **argv)
{
    FILE *arquivo = NULL;
    int resultado;

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    if (argc > 1) {
        arquivo = fopen(argv[1], "r");
        if (arquivo == NULL) {
            perror("Erro ao abrir o arquivo de entrada");
            return 1;
        }
        yyin = arquivo;
    }

    while ((resultado = yyparse()) != PARSE_FIM) {
        if (resultado == PARSE_OK)
            printf("%s\n", MSG_OK);
        else
            printf("%s\n", MSG_ERRO);
    }

    if (arquivo != NULL)
        fclose(arquivo);

    return 0;
}