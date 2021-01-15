#ifndef LIST_PAGE_H
#define LIST_PAGE_H
#include <stdio.h>
#include "page.h"

typedef struct listPage ListPage;

/* EN
 * Pre-condition: none
 * Post-condition: empty list of pages
 * 
 * PT
 * Pré-condição: nenhuma
 * Pós-condição: lista de páginas vazia
 * 
 * Input: void
 * Output: ListPage*
 */
ListPage* initListPage (void);

/* EN
 * Pre-condition: lista of pages exists
 * Post-condition: pages' status changed to 1
 * 
 * PT
 * Pré-condição: lista de paginas existe
 * Pós-condição: estado das paginas mudado para 1
 * 
 * Input: ListPage*
 * Output: void
 */
void changeStatusToOne (ListPage* lp);

/* EN
 * Pre-condition: lista of pages and page exist
 * Post-condition: page added to list of pages
 * 
 * PT
 * Pré-condição: lista de paginas e pagina existem
 * Pós-condição: pagina adicionada a lista de paginas
 * 
 * Input: ListPage*, Page*
 * Output: void
 */
void addPageToListPage (ListPage* lp, Page* page);

/* EN
 * Pre-condition: list of pages exist and key and function are informed
 * Post-condition: returns page with *key* name
 * 
 * PT
 * Pré-condição: lista de paginas existe e *key* e a funcao que sera utilizada sao informadas
 * Pós-condição: retorna pagina com nome *key*
 * 
 * Input: ListPage*, char*, int (function)
 * Output: Page*
 */
Page* checkIfPageExist (ListPage* lp, char* key, int (*cmp)(Page*, char*));

/* EN
 * Pre-condition: list o f page and links exist and name is informed
 * Post-condition: returns 1 if page with *name* exists, otherwise returns 0
 * 
 * PT
 * Pré-condição: lista de paginas e links existem e *name* eh informado
 * Pós-condição: retorna 1 caso pagina com *nome* existe, caso contrario retorna 0
 * 
 * Input: ListPage* char*, ListPage*
 * Output: int
 */
int checkLinkList (ListPage* list, char* name, ListPage* linksRead);

/* EN
 * Pre-condition: list of pages exist and key is informed
 * Post-condition: removes page with *key* name from list of pages and free memory allocated by it
 * 
 * PT
 * Pré-condição: lista de paginas existe e *key* eh informado
 * Pós-condição: remove pagina com nome *key* da lista de paginas e libera memoria alocada por pagina
 * 
 * Input: ListPage*, char*
 * Output: void
 */
void removePage (ListPage* lp, char* key);

/* EN
 * Pre-condition: list of pages exist and key is informed
 * Post-condition: removes page with *key* name from list of pages
 * 
 * PT
 * Pré-condição: lista de paginas existe e *key* eh informado
 * Pós-condição: remove pagina com nome *key* da lista de paginas
 * 
 * Input: ListPage*, char*
 * Output: void
 */
void removeLink (ListPage* lp, char* key);

/* EN
 * Pre-condition: file and list of pages exist
 * Post-condition: prints pages' names and file names onto file
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: imprime nomes das paginas e dos arquivos das paginas
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void showListLinks (FILE* file, ListPage* lp);

/* EN
 * Pre-condition: list of pages exists
 * Post-condition: prints all pages' contents
 * 
 * PT
 * Pré-condição: lista de pagina existe
 * Pós-condição: imprime o conteudo de todas as paginas
 * 
 * Input: ListPage*
 * Output: void
 */
void showListPage (ListPage* lp);

/* EN
 * Pre-condition: page exists and keyColab is informed
 * Post-condition: colab *keyColab*'s status changed
 * 
 * PT
 * Pré-condição: pagina existe e keyColab eh informado
 * Pós-condição: estado de colaboracao *keyColab* mudado 
 * 
 * Input: ListPage*, char*
 * Output: void
 */
void removeColabFromListPage (Page* page, char* keyColab);

/* EN
 * Pre-condition: list of pages exist
 * Post-condition: memory allocated for list of pages and pages freed
 * 
 * PT
 * Pré-condição: lista de paginas existe
 * Pós-condição: memoria alocada para lista de paginas e todas as suas paginas liberada
 * 
 * Input: ListPage*
 * Output: void
 */
void freeListPage (ListPage* lp);

/* EN
 * Pre-condition: list of pages exist
 * Post-condition: memory allocated for list of pages freed
 *  
 * PT
 * Pré-condição: lista de paginas existe
 * Pós-condição: memoria alocada para lista de paginas liberada
 * 
 * Input: ListPage*
 * Output: void
 */
void freeListLink (ListPage* lp);

#endif