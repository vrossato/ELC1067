/*
 * vetor.c
 * TAD que implementa um vetor dinamico.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014, 2015 João V. Lima, UFSM
 *               2005       Benhur Stein, UFSM
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vetor.h"
#include "carta.h"
#include "memo.h"

struct vetor
{
	carta* baralho;   /* baralho - vetor de cartas */
	int n;		/* número de cartas */
};

vetor_t* vetor_cria(void)
{
	int i;
	struct vetor *vet = (struct vetor*)memo_aloca(sizeof(struct vetor));
	vet -> n = 0;

	vet -> baralho = (carta*)memo_aloca(52 * sizeof(carta));

	for(i = 0;  i < 53; i++){
        vet -> baralho[i] = NULL;
	}

	return vet;
}

void vetor_destroi(vetor_t* vet)
{
	memo_libera(vet -> baralho);
	memo_libera(vet);
}

int vetor_numelem(vetor_t *vet)
{
	return vet -> n;
}

void vetor_insere_carta(vetor_t *vet, int indice, carta c)
{
	int  n_cartas = vet->n-1;
	if(vet->baralho[indice] != NULL){

	    vet->baralho[n_cartas+1] = vet->baralho[n_cartas];
	    vet->baralho[indice] = c;
	    vet->n++;
	}else{
	      vet->baralho[indice] = c;
	      vet->n++;
    }
}

carta vetor_remove_carta(vetor_t *vet, int indice)
{
	carta aux;
	aux = vet -> baralho[indice];
	int num_cartas = vet -> n;
	int i;

	for(i = indice; i < num_cartas; i++){
	  vet -> baralho[i] = vet -> baralho[i+1];
	}

	vet -> n--;
	vet -> baralho[vet -> n]= NULL;

	return aux;
}

carta vetor_acessa_carta(vetor_t *vet, int indice)
{
	return vet -> baralho[indice];
}

bool vetor_valido(vetor_t *vet)
{
	if(vet -> baralho != NULL && vet -> n != 0){
	  return true;
	}
	return false;
}
