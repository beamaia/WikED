#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "page.h"
#include "colab.h"
#include "listColab.h"
#include "listPage.h"
int numglobal = 0;

/* EN
 * Page structure
 * char* name: Page's name
 * char* fileName: Page's file name/file path
 * ListColab* listColab: List of colaborations related to page 
 * ListPage* listLink: List of pages accessible through this page (pages linked to this page)
 * 
 * PT
 * Estrutura da pagina
 * char* name: Nome da pagina
 * char* fileName: Caminho/nome do arquivo da pagina
 * ListColab* listColab: Lista de colaboracoes feita a pagina
 * ListPage* listLink: Lista de paginas acessiveis por esta pagina (paginas linkadas)
 */ 
struct page{
    char* name,
        * fileName;
    ListColab* listColab;
    ListPage* listLinks;
};

Page* initPage (char* name, char* fileName) {
    Page* page = (Page*) malloc(sizeof(Page));

    // Adding page's name
    // Adicionano nome da pagina
    page->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(page->name, name);
    
    // Adding page's file name (in case it'd be printed)
    // Adicionando nome do arquivo da pagina
    page->fileName = (char*) malloc(sizeof(char) * (strlen(fileName) + 1));
    strcpy(page->fileName, fileName);

    // Initializing empty lists of colabs and links
    // Inicializando listas vazias de colaboracoes e links
    page->listColab = initListColab();
    page->listLinks = initListPage();

    return page;
}

int samePage (Page* page, char* key) {
    // See if page name is the same as the key informed
    // If True, returns 1.
    // If False, returns 0.
    if(strcmp(page->name, key) == 0)
        return 1;
    return 0;
}

int samePageFile (Page* page, char* key) {
    // See if page file name is the same as the key informed
    // If True, returns 1.
    // If False, returns 0.
    if(strcmp(page->fileName, key) == 0)
        return 1;
    return 0;
}

char* getPageName (Page* page) {
    return page->name;
}

Page* checkIfLinkExists (Page* page, char* key) {
    if (page->listLinks == NULL)
        return NULL;

    // searches for a page within list of links with the name *key*
    // procura por uma pagina dentro da lista de links com o nome *key*
    Page* p = checkIfPageExist(page->listLinks, key, samePage);

    if(p != NULL)
        return p;
    return NULL;
}

Colab* checkColabInPage(Page* p, char* fileName){
    if (p->listColab == NULL)
        return NULL;
    
    // searches for colab within list of colabs with the same name as *fileName*
    // procura por colab dentro da lista de colabs com o mesmo nome que *fileName*
    Colab* aux = checkIfColabExist(p->listColab, fileName);
    
    if (aux == NULL)
        return NULL;
    return aux;
}

void addLinkToPage (Page* page, Page* link) {
    addPageToListPage(page->listLinks, link);
}

void removeLinkFromPage (Page* page, Page* link) {
    removeLink(page->listLinks, link->name);
}

void addColabToPage (Page* page, Colab* colab) {
    addColabToListColab (page->listColab, colab);
}

int checkLinkPage (Page* origin, char* destiny, void* links) {
    int status = 0;

    status = checkLinkList(origin->listLinks, destiny, links);

    return status;
}

void showPageName (FILE* file, Page* page) {
    // Prints on file the page's name
    fprintf(file, "%s", page->name);
}

void showPageFile (FILE* file, Page* page) {
    fprintf(file, "%s", page->fileName);
}

void showPageColabs (FILE* file, Page* page) {
    showHistoryListColab(file, page->listColab);
}

void showLinksInfo (FILE* file, Page* page) {
    showPageName(file, page);
    fprintf(file, " ");
    showPageFile(file, page);
    fprintf(file, "\n");
}

void showPageLinks (FILE* file, Page* page) {
    showListLinks(file, page->listLinks);
}

void showPageTexts (FILE* file, Page* page) {
    showListColab(file, page->listColab);
}

void showPage (Page* page) {
    // Generates file
    FILE* file = fopen(page->fileName, "w");

    // Prints everything needed in a page
    showPageName(file, page);
    fprintf(file, "\n\n");

    fprintf(file, "--> Historico de contribuicoes\n");
    showPageColabs(file, page);
    fprintf(file, "\n");

    fprintf(file, "--> Links\n");
    showPageLinks(file, page);
    fprintf(file, "\n");

    fprintf(file, "--> Textos\n");
    showPageTexts(file, page);

    fclose(file);
}

void removeColabFromPage(Page* page, char* key) {
    removeColab(page->listColab, key);
}

void freePage (Page* page) {
    free(page->name);
    free(page->fileName);
    freeListColab(page->listColab);
    freeListLink(page->listLinks);
    free(page);
}
