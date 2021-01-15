#ifndef PAGE_H
#define PAGE_H
#include <stdio.h>
#include "colab.h"

typedef struct page Page;

/* EN
 * Pre-condition: name and file name are informed
 * Post-condition: page is created with name, file name and empty lists of colabs and links
 * 
 * PT
 * Pré-condição: nome e nome do arquivo informado
 * Pós-condição: pagina criada com nome, nome do arquivo e listas vazias de colaboracoes e links
 * 
 * Input: char*, char*
 * Output: Page*
 */
Page* initPage(char* name, char* fileName);

/* EN
 * Pre-condition: page exists and key is informed
 * Post-condition: returns 1 if page has the same name as key, 0 otherwise
 * 
 * PT
 * Pré-condição: pagina existe e "key" eh informado
 * Pós-condição: retorna 1 se pagina tem o mesmo nome de "key", 0 caso contrario
 * 
 * Input: Page*, char*
 * Output: int
 */
int samePage (Page* page, char* key);

/* EN
 * Pre-condition: page exists and key is informed
 * Post-condition: returns 1 if page has the same file name as key, 0 otherwise
 * 
 * PT
 * Pré-condição: pagina existe e "key" eh informado
 * Pós-condição: retorna 1 se pagina tem o mesmo nome de arquivo que "key", 0 caso contrario
 * 
 * Input: Page*, char*
 * Output: int
 */
int samePageFile (Page* page, char* key);

/* EN
 * Pre-condition: page exists
 * Post-condition: page's name is returned
 * 
 * PT
 * Pré-condição: pagina existe 
 * Pós-condição: nome da pagina eh retornado 
 * 
 * Input: Page*
 * Output: char*
 */
char* getPageName (Page* page);

/* EN
 * Pre-condition: page exists and key is informed
 * Post-condition: returns page from list of links with key name (if it doesn't exists, returns NULL)
 * 
 * PT
 * Pré-condição: pagina existe e "key" eh informada
 * Pós-condição: retorna pagina da lista de links com nome "key" (se nao existe, retorna NULL)
 * 
 * Input: Page*, char*
 * Output: Page*
 */
Page* checkIfLinkExists (Page* page, char* key);

/* EN
 * Pre-condition: page exists and file name is informed
 * Post-condition: returns colab from list of colabs with file name (if it doesn't exists, returns NULL)
 * 
 * PT
 * Pré-condição: pagina existe e
 * Pós-condição: retorna colab da lista de colaboracoes com nome "fileName" (se nao existe, retorna NULL)
 * 
 * Input: Page*, char*
 * Output: Colab*
 */
Colab* checkColabInPage(Page* p, char* fileName);

/* EN
 * Pre-condition: pages page and link exist
 * Post-condition: link added to page's list of link
 * 
 * PT
 * Pré-condição: pagina page e link existem
 * Pós-condição: link adicionado a lista de links de page
 * 
 * Input: Page*, Page*
 * Output: void
 */
void addLinkToPage (Page* page, Page* link);

/* EN
 * Pre-condition: pages page and link exist
 * Post-condition: link is removed from page's list of link
 * 
 * PT
 * Pré-condição: pagina page e link existem
 * Pós-condição: link eh removido da lista de links de page
 * 
 * Input: Page*, Page*
 * Output: void
 */
void removeLinkFromPage (Page* page, Page* link);

/* EN
 * Pre-condition: page and colab exist
 * Post-condition: colab is added to page's list of colabs
 * 
 * PT
 * Pré-condição: pagina e colaboracao existe, 
 * Pós-condição: colaboracoes eh adicionada para lista de colaboracoes de page
 * 
 * Input: Page*, Colab*
 * Output: void
 */
void addColabToPage (Page*, Colab*);

/* EN
 * Pre-condition: page and list of links exist and destiny is informed
 * Post-condition: returns 1 if link between page and destiny exist, otherwise returns 0
 * 
 * PT
 * Pré-condição: pagina e lista de links existe e destiny (destino) eh informado
 * Pós-condição: retorna 1 se link (direto ou indireto) existe entre pagina e desinty
 * 
 * Input: Page*, char*, void*
 * Output: int
 */
int checkLinkPage (Page* origin, char* destiny, void* links);

/* EN
 * Pre-condition: file and page exist
 * Post-condition: prints page's name onto file
 * 
 * PT
 * Pré-condição: arquivo e pagina existe 
 * Pós-condição: imprime nome da pagina em arquivo
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showPageName (FILE*, Page*);

/* EN
 * Pre-condition: file and page exist
 * Post-condition: prints page's file name onto file
 * 
 * PT
 * Pré-condição: arquivo e pagina existe 
 * Pós-condição: imprime nome do arquivo da pagina em arquivo
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showPageFile (FILE*, Page*);

/* EN
 * Pre-condition: file and page exist
 * Post-condition: prints page's colabs' name and file name onto file
 * 
 * PT
 * Pré-condição: arquivo e pagina existe 
 * Pós-condição: imprime nome da pagina e o nome do arquivo das colaboracoes em arquivo
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showPageColabs (FILE*, Page*);

/* EN
 * Pre-condition: file and page exist
 * Post-condition: prints page's name and file name onto file
 * 
 * PT
 * Pré-condição: arquivo e pagina existe 
 * Pós-condição: imprime o nome da pagina e o nome do arquivo da pagina em arquivo
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showLinksInfo (FILE*, Page*);

/* EN
 * Pre-condition: file and page exist
 * Post-condition: print links infos onto file
 * 
 * PT
 * Pré-condição: arquivo e pagina existe 
 * Pós-condição: imprime info dos link em arquivo
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showPageLinks (FILE*, Page*);

/* EN
 * Pre-condition: file and page exist
 * Post-condition: prints all of colabs contents onto page file
 * 
 * PT
 * Pré-condição: arquivo e pagina existe 
 * Pós-condição: imprime todos os conteudos das colaboracoes em arquivo
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showPageTexts (FILE*, Page*);

/* EN
 * Pre-condition: page exist
 * Post-condition: prints all of the pages infos
 * 
 * PT
 * Pré-condição: pagina existe 
 * Pós-condição: imprime todos as informacoes da pagina
 * 
 * Input: FILE*, Page*
 * Output: void
 */
void showPage (Page*);

/* EN
 * Pre-condition: page exists and key is informed
 * Post-condition: status of page with *key* name changed
 * 
 * PT
 * Pré-condição: pagina existe e key eh informado
 * Pós-condição: estado da pagina com nome *key* mudado
 * 
 * Input: FILE*, char*
 * Output: void
 */
void removeColabFromPage(Page* page, char* key);

/* EN
 * Pre-condition: page exists
 * Post-condition: memory allocated for page and it's content freed
 * 
 * PT
 * Pré-condição: pagina existe e key eh informado
 * Pós-condição: memoria alocada para pagina e seu conteudo liberado
 * 
 * Input: Page*
 * Output: void
 */
void freePage (Page*);

#endif