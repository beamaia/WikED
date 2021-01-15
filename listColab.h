#ifndef LIST_COLAB_H
#define LIST_COLAB_H

#include <stdio.h>
#include "listColab.h"
#include "colab.h"

typedef struct listColab ListColab;

/* EN
 * Pre-condition: none
 * Post-condition: empty list of colabs is created
 * 
 * PT
 * Pré-condição: nenhuma
 * Pós-condição: lista vazia de colaboracoes eh criada
 * 
 * Input: void
 * Output: ListColab*
 */
ListColab* initListColab (void);

/* EN
 * Pre-condition: list of colabs and colab exist
 * Post-condition: colab added to list of colabs
 * 
 * PT
 * Pré-condição: lista de colaboracoes e colaboracao existem
 * Pós-condição: colaboracao adicionada para lista de colaboracoes
 * 
 * Input: ListColab*, Colab*
 * Output: void
 */
void addColabToListColab (ListColab* lc, Colab* colab);

/* EN
 * Pre-condition: list of colabs exists and "key" string is informed
 * Post-condition: colab with "key" file name is returned
 * 
 * PT
 * Pré-condição: lista de colaboracoes existe e "key" string eh informada
 * Pós-condição: colaboracao com nome de arquivo "key" eh retornadas
 * 
 * Input: ListColab*, char*
 * Output: Colab*
 */
Colab* checkIfColabExist (ListColab* lc, char* key);

/* EN
 * Pre-condition: file and list of colabs exist
 * Post-condition: file with colabs' file names and editors' names 
 * 
 * PT
 * Pré-condição: arquivo e lista de colaboracoes existe
 * Pós-condição: arquivo com nomes de arquivo e editores das colaboracoes da lista de colaboracoes
 * 
 * Input: FILE*, ListColab*
 * Output: void
 */
void showHistoryListColab (FILE* file, ListColab* lc);

/* EN
 * Pre-condition: file and list of colabs exist
 * Post-condition: copies colabs' content
 * 
 * PT
 * Pré-condição: arquivo e lista de colaboracoes existe
 * Pós-condição: copia conteudo das colaboracoes
 * 
 * Input: FILE*, ListColab*
 * Output: void
 */
void showListColab (FILE* file, ListColab* lc);

/* EN
 * Pre-condition: list of colabs exists and "key" is informed
 * Post-condition: if found colab with "key" file name, status is changed to 0
 * 
 * PT
 * Pré-condição: lista de colaboracoes existe e "key" eh informado
 * Pós-condição: se encontrado a colaboracao com o nome de arquivo "key", estado eh mudado para 0
 * 
 * Input: ListColab*, char*
 * Output: void
 */
void removeColab (ListColab* lc, char* key);

/* EN
 * Pre-condition: list of colabs exists 
 * Post-condition: memory allocated for list of colabs and all colabs is freed
 * 
 * PT
 * Pré-condição: lista de colaboracoes existe
 * Pós-condição: memoria alocada para lista de colaboracoes e todas as colaboracoes eh liberada
 * 
 * Input: ListColab*
 * Output: void
 */
void freeAllColab (ListColab* lc);


/* EN
 * Pre-condition: list of colabs exists 
 * Post-condition: memory allocated for list of colabs is freed
 * 
 * PT
 * Pré-condição: lista de colaboracoes existe
 * Pós-condição: memoria alocada para lista de colaboracoes eh liberada
 * 
 * Input: ListColab*
 * Output: void
 */
void freeListColab (ListColab* lc);

#endif