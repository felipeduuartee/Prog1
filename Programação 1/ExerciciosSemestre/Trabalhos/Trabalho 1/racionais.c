#include "racionais.h"


// retorna um valor aleatório entre minimo e maximo
// usada na função sorteia_r
int aleat (int min, int max){
    return min + rand() % (max - min + 1);
}

// mdc entre a e b
int mdc (int a, int b) {

    a = abs(a);
    b = abs(b);
    int resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}
// mmc entre os denominadores dos racionais
int mmc (int a, int b) {

    return (a * b) / mdc(a, b);
}

// simplifica um racional dividindo o num e den pelo mdc deles
struct racional simplifica_r(struct racional r) {

    int divisor = mdc(abs(r.num), abs(r.den));
    r.num /= divisor;
    r.den /= divisor;

    // se os dois são negativos,resultado é positivo
    if (r.num < 0 && r.den < 0) {
        r.num = abs(r.num);
        r.den = abs(r.den);
    }

    // se só o denominador é negativo, numerador muda o sinal
    if (r.den < 0) {
        r.num = r.num * (-1);
        r.den = abs(r.den);
    }

    return r;
}

// cria e retorna um numero racional com numerador e denominador
struct racional cria_r(int numerador, int denominador) {

    struct racional r;

    r.num = numerador;
    r.den = denominador;
    r.valido = (valido_r(r));

    return r;
}

// sorteia e retorna um valor simplificado com numerador e denominador
struct racional sorteia_r(int n) {

    struct racional r;
    int numerador, denominador;

    numerador = aleat(0, n);
    denominador = aleat(0, n);
    r = cria_r(numerador, denominador);

    return simplifica_r(r);
}


// imprime o racional com suas devidas regrinhas
void imprime_r(struct racional r) {

    if (!r.valido) {
        printf("INVALIDO ");
        return;
    }

    
    if (r.num == 0) {
        printf("0 ");
        return;
    }

    
    if (r.den == 1) {
        printf("%d ", r.num);
        return;
    }

    
    if (r.num == r.den) {
        printf("1 ");
        return;
    }

    
    if (r.den < 0) {
        r.num = -r.num;
        r.den = -r.den;
    }

   
    printf("%d/%d ", r.num, r.den);
}



// verifica se o denominador é 0, ou seja, se é invalido
int valido_r(struct racional r) {

    if (r.den == 0) {
        return 0;
    } 
    return 1;
}

// realiza a soma dos racionais
struct racional soma_r (struct racional r1, struct racional r2) {
    struct racional resposta;
    int minimoComum = mmc(r1.den, r2.den);
        resposta.num = (r1.num * (minimoComum / r1.den)) + (r2.num * (minimoComum / r2.den));
        resposta.den = (minimoComum);

        resposta = simplifica_r(resposta);
        
        return resposta;
}

// realiza a subtração dos racionais
struct racional subtrai_r (struct racional r1, struct racional r2) {
    struct racional resposta;
    
    int minimoComum = mmc(r1.den, r2.den);
    resposta.num = (r1.num * (minimoComum / r1.den)) - (r2.num * (minimoComum/ r2.den));
    resposta.den = minimoComum;
    
    resposta = simplifica_r(resposta);
    return resposta;
}


// realiza a multiplicação dos racionais
struct racional multiplica_r (struct racional r1, struct racional r2) {
    struct racional resposta;

        resposta.num = (r1.num * r2.num);
        resposta.den = (r1.den * r2.den);

        resposta = simplifica_r(resposta);
        
        return resposta;
}

// realiza a divisão dos racionais
struct racional divide_r (struct racional r1, struct racional r2) {
    struct racional resposta;

// verifica se a divisão é válida
    if (r2.num == 0 || r1.den == 0) {
        resposta.valido = 0;
        return resposta;
    }
    else {
        resposta.valido = 1;
    }
    // divisao de fracao: mantem a primeira multiplica pelo inverso da segunda
    
        resposta.num = r1.num * r2.den;
        resposta.den = r1.den * r2.num;

        resposta = simplifica_r(resposta);
        
        return resposta;
}
