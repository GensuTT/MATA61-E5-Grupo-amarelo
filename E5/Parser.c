/*
 * Gramática original (ambígua e recursiva à esquerda):
 *
 *     E ::= E + E | E - E | E * E | E / E | num
 *
 * Gramática modificada
 *     E  ::= T E'
 *     E' ::= + T E' | - T E' | λ
 *     T  ::= F T'
 *     T' ::= * F T' | / F T' | λ
 *     F  ::= num

 */
#include "token.h"
#include "Parser.h"

static int lookahead;          /* token corrente (lookahead de 1 símbolo) */
static int erro;               /* 1 se encontrou erro na linha corrente   */
static int fim_entrada = 0;    /* 1 depois que o EOF foi lido             */

static void E(void);
static void E_linha(void);
static void T(void);
static void T_linha(void);
static void F(void);

static void avancar(void)
{
    lookahead = yylex();
}

/* Consome o token esperado ou sinaliza erro sintático. */
static void casar(int esperado)
{
    if (lookahead == esperado)
        avancar();
    else
        erro = 1;
}

/* E ::= T E' */
static void E(void)
{
    T();
    E_linha();
}

/* E' ::= + T E' | - T E' | λ */
static void E_linha(void)
{
    if (erro) return;

    if (lookahead == PLUS) {
        casar(PLUS);
        T();
        E_linha();
    } else if (lookahead == MINUS) {
        casar(MINUS);
        T();
        E_linha();
    }
    /* senão: produção vazia (λ) - o token será verificado pelo chamador */
}

/* T ::= F T' */
static void T(void)
{
    if (erro) return;

    F();
    T_linha();
}

/* T' ::= * F T' | / F T' | λ */
static void T_linha(void)
{
    if (erro) return;

    if (lookahead == TIMES) {
        casar(TIMES);
        F();
        T_linha();
    } else if (lookahead == DIV) {
        casar(DIV);
        F();
        T_linha();
    }
    /* senão: produção vazia (λ) */
}

/* F ::= num */
static void F(void)
{
    if (erro) return;

    casar(NUM);   /* qualquer outro token (operador, ERRO, EOL...) é erro */
}

/* Recuperação de erro: descarta o restante da linha corrente, sem ler
 * além do EOL (para não bloquear a leitura interativa do teclado). */
static void descartar_linha(void)
{
    while (lookahead != EOL && lookahead != FIM)
        avancar();
}

int yyparse(void)
{
    if (fim_entrada)
        return PARSE_FIM;

    /* Lê o primeiro token da linha, ignorando linhas em branco. */
    do {
        avancar();
    } while (lookahead == EOL);

    if (lookahead == FIM) {
        fim_entrada = 1;
        return PARSE_FIM;
    }

    erro = 0;
    E();

    /* Após a expressão, a linha deve terminar. */
    if (!erro && lookahead != EOL && lookahead != FIM)
        erro = 1;

    if (erro)
        descartar_linha();

    if (lookahead == FIM)
        fim_entrada = 1;   /* última linha sem '\n' no final */

    return erro ? PARSE_ERRO : PARSE_OK;
}