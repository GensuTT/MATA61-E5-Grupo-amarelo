#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    FIM = 0,   
    NUM,       
    PLUS,      
    MINUS,   
    TIMES,    
    DIV,
    EOL,     
    ERROR, 
    ERRO = ERROR
} Token;

extern double yylval;

int yylex(void);

#endif
