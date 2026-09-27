#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "dequef.h"


/**
   Aloca um novo deque.

   Capacity vira o mincap e o cap inicial.
   Factor é o fator de resize do deque, mínimo 1.0.

   Se sim, retorna o endereço de um novo deque.
   Se não, retorna NULL.
**/
dequef* df_alloc(long capacity, double factor) {
   if (factor < 1.0 || capacity < 1) {
      return NULL;
   }
   dequef* D = malloc(sizeof(dequef));
   if (D == NULL) {
      return NULL;
   }
   // Esse malloc é justamente para guardar os floats.
   D->data = malloc(capacity * sizeof(float));
   if (D->data == NULL) {
      free(D);
      return NULL;
   }
   D->first = 0;
   D->size = 0;
   D->mincap = capacity;
   D->cap = capacity;
   D->factor = factor;
   return D;
}



/**
  Libera a memória, o data e o struct.
**/
void df_free(dequef* D) {
   if (D == NULL) {
      return;
   }
   free(D->data);
   free(D);
}



/**
   Retorna size.

   Trata D == NULL, retornando 0.
**/
long df_size(dequef* D) {
   if (D == NULL) {
      return 0;
   }
   return D->size;
}



/**
   Insere x no fim do deque.

   Se está cheio, primeiro tenta aumentar o tamanho
   para capacity*factor.

   Se sim, retorna 1.
   Se resize dá erro, retorna 0 e permanece intacto.
**/
int df_push(dequef* D, float x) {
   if (D->size == D->cap) {
      long cap_novo = (long)(D->cap * D->factor);
      float* array = malloc(cap_novo * sizeof(float));
      if (array == NULL) {
         return 0;
      }
      // Copia os elementos do array antigo para o novo.
      for (long i = 0; i < D->size; i++) {
         array[i] = D->data[(D->first + i) % D->cap];
      }
      free(D->data);
      D->data = array;
      D->cap = cap_novo;
      D->first = 0;
   }
   long j = (D->first + D->size) % D->cap;
   D->data[j] = x;
   D->size++;
   return 1;
}



/**
   Remove e retorna o elemento do fim.

   Se o deque tem capacity/(factor^2), tenta reduzir
   para capacity/factor.
   Se capacity/factor é menor que mincap, mincap é usado.
   Se resize não é possível, permanece intacto.

   Se estiver vazio, a função não é chamada na main.
**/
float df_pop(dequef* D) {
   long j = (D->first + D->size - 1) % D->cap;
   float valor = D->data[j];
   D->size--;
   if (D->size <= D->cap / (D->factor * D->factor)) {
      long cap_novo = (long)(D->cap / D->factor);
      if (cap_novo < D->mincap) {
         cap_novo = D->mincap;
      }
      // Se tiver mudado, vai fazer a mesma coisa que fez em push.
      if (cap_novo != D->cap) {
         float* array = malloc(cap_novo * sizeof(float));
         if (array != NULL) {
            for (long i = 0; i < D->size; i++) {
               array[i] = D->data[(D->first + i) % D->cap];
            }
            free(D->data);
            D->data = array;
            D->cap = cap_novo;
            D->first = 0;
         }
      }
   }
   return valor;
}



/**
   Insere x no início de D.

   Se está cheio, primeiro tenta aumentar o tamanho
   para capacity*factor.

   Se sim, retorna 1.
   Se resize dá erro, retorna 0 e permanece intacto.
**/
int df_inject(dequef* D, float x) {
   // Inicia com a mesma checagem e cópia do push
   if (D->size == D->cap) {
      long cap_novo = (long)(D->cap * D->factor);
      float* array = malloc(cap_novo * sizeof(float));
      if (array == NULL) {
         return 0;
      }
      // Copia os elementos do array antigo para o novo.
      for (long i = 0; i < D->size; i++) {
         array[i] = D->data[(D->first + i) % D->cap];
      }
      free(D->data);
      D->data = array;
      D->cap = cap_novo;
      D->first = 0;
   }
   D->first = (D->first - 1 + D->cap) % D->cap;
   D->data[D->first] = x;
   D->size++;
   return 1;
}



/**
   Remove e retorna o elemento do início.

   Se o deque tem capacity/(factor^2), tenta reduzir
   para capacity/factor.
   Se capacity/factor é menor que mincap, mincap é usado.
   Se resize não é possível, permanece intacto.

   Se estiver vazio, a função não é chamada pela main.
**/
float df_eject(dequef* D) {
   float valor = D->data[D->first];
   D->first = (D->first + 1) % D->cap;
   D->size--;
   // Mesmíssima lógica do pop.
   if (D->size <= D->cap / (D->factor * D->factor)) {
      long cap_novo = (long)(D->cap / D->factor);
      if (cap_novo < D->mincap) {
         cap_novo = D->mincap;
      }
      if (cap_novo != D->cap) {
         float* array = malloc(cap_novo * sizeof(float));
         if (array != NULL) {
            for (long i = 0; i < D->size; i++) {
               array[i] = D->data[(D->first + i) % D->cap];
            }
            free(D->data);
            D->data = array;
            D->cap = cap_novo;
            D->first = 0;
         }
      }
   }
   return valor;
}



/**
   Retorna D[i].

   Se não pertence a [0,|D|-1]], a main não chama.
**/
float df_get(dequef* D, long i) {
   return D->data[(D->first + i) % D->cap];
}



/**
   Modifica D[i] pra x.

   Se não pertence a [0,|D|-1]], a min não chama.
**/
void df_set(dequef* D, long i, float x) {
   D->data[(D->first + i) % D->cap] = x;
}



/**
   Imprime os elementos de D em uma linha,
   na ordem lógica.
**/
void df_print(dequef* D) {
   printf("deque (%ld): ", D->size);
   for (long i = 0; i < D->size; i++) {
      printf("%.1f ", D->data[(D->first + i) % D->cap]);
   }
   printf("\n");
}
