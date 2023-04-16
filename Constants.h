#ifndef CONSTANTS_H
#define CONSTANTS_H

enum TokenId 
{
    EPSILON  = 0,
    DOLLAR   = 1,
    t_PARA = 2,
    t_ENQUANTO = 3,
    t_FACA_ENQUANTO = 4,
    t_SE = 5,
    t_SENAO = 6,
    t_SENAO_SE = 7,
    t_PARE = 8,
    t_FUNCAO = 9,
    t_RETORNE = 10,
    t_ID_INTEIRO = 11,
    t_ID_REAL = 12,
    t_ID_PALAVRA = 13,
    t_ID_CARACTERE = 14,
    t_ID_LOGICO = 15,
    t_PROGRAMA = 16,
    t_ESCREVA = 17,
    t_LEIA = 18,
    t_CONSTANTE = 19,
    t_ADICAO = 20,
    t_SUBTRACAO = 21,
    t_MULTIPLICACAO = 22,
    t_DIVISAO = 23,
    t_MOD = 24,
    t_MAIOR = 25,
    t_MENOR = 26,
    t_MAIOR_IGUAL = 27,
    t_MENOR_IGUAL = 28,
    t_IGUAL_COMPARACAO = 29,
    t_IGUAL_ATRIBUICAO = 30,
    t_DIFERENTE = 31,
    t_OU = 32,
    t_E = 33,
    t_NEGACAO = 34,
    t_BIT_MOVE_DIREITA = 35,
    t_BIT_MOVE_ESQUERDA = 36,
    t_BIT_OU = 37,
    t_BIT_E = 38,
    t_BIT_XOR = 39,
    t_BIT_NEGACAO = 40,
    t_INTEIRO = 41,
    t_REAL = 42,
    t_CARACTERE = 43,
    t_PALAVRA = 44,
    t_LOGICO = 45,
    t_IDENTIFICADORES = 46,
    t_COMENTARIO_SIMPLES = 47,
    t_COMENTARIO_MULTIPLO = 48,
    t_VIRGULA = 49,
    t_PONTO_VIRGULA = 50,
    t_DOIS_PONTOS = 51,
    t_ABRE_COLCHETES = 52,
    t_FECHA_COLCHETES = 53,
    t_ABRE_PARENTESES = 54,
    t_FECHA_PARENTESES = 55,
    t_ABRE_CHAVES = 56,
    t_FECHA_CHAVES = 57
};

const int STATES_COUNT = 162;

extern int SCANNER_TABLE[STATES_COUNT][256];

extern int TOKEN_STATE[STATES_COUNT];

extern const char *SCANNER_ERROR[STATES_COUNT];

const int FIRST_SEMANTIC_ACTION = 123;

const int SHIFT  = 0;
const int REDUCE = 1;
const int ACTION = 2;
const int ACCEPT = 3;
const int GO_TO  = 4;
const int ERROR  = 5;

extern const int PARSER_TABLE[286][122][2];

extern const int PRODUCTIONS[153][2];

extern const char *PARSER_ERROR[286];

#endif
