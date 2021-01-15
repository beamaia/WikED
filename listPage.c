#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listColab.h"
#include "listPage.h"
#include "page.h"

/* EN
 * Cell structure pointing to a page and the next cell. Include status
 * 
 * PT
 * Estrutura de celula apontando para uma pagina e a proxima celula. Inclui estado
 */ 
typedef struct cellPG CellPG;
struct cellPG {
    Page* page;
    CellPG* next;
    int status;
};

/* EN
 * Structure pointing to fist and last cells
 * 
 * PT 
 * Estrutura apontando para primeira e ultima celulas
 */ 
struct listPage {
    CellPG* first,
          * last;
};

ListPage* initListPage (void) {
    ListPage* lp = (ListPage*) malloc(sizeof(ListPage));
    lp->first = lp->last = NULL;
    return lp;
}

void changeStatusToOne (ListPage* lp) {
    CellPG* aux;

    for (aux=lp->first; aux != NULL; aux=aux->next) {
        aux->status = 1;
    }
}

void addPageToListPage (ListPage* lp, Page* page) {
    CellPG* newCell = (CellPG*) malloc (sizeof(CellPG));

    newCell->status = 0;
    newCell->page = page;
    newCell->next = NULL;
    
    // If the list is empty
    // Se lista esta vazia
    if (lp->first == NULL) {
        lp->first = newCell;
    } else {
        lp->last->next = newCell;
    }

    lp->last = newCell;

}

Page* checkIfPageExist (ListPage* lp, char* key, int (*cmp)(Page*, char*)) {
    CellPG* aux;

    for(aux = lp->first; aux != NULL; aux=aux->next) {
        if (cmp(aux->page, key)) {
            break;
        }
    }

    if(aux == NULL)
        return NULL;
    return aux->page;
}

int checkLinkList (ListPage* list, char* name, ListPage* linksRead) {
    CellPG* aux;
    Page* auxPage;
    int status;    

    for (aux = list->first; aux != NULL; aux = aux->next) {

        auxPage = checkIfPageExist(linksRead, getPageName(aux->page), samePage);
        if (auxPage != NULL) {
            continue;
        } else if (samePage(aux->page, name)) {
            return 1;
        } else {
            addPageToListPage(linksRead, aux->page);
        }
    }

    for (aux = linksRead->first; aux != NULL; aux = aux->next) {
        if (aux->status == 1)
            continue;
        aux->status = 1;
        status = checkLinkPage(aux->page, name, linksRead);
        if (status == 1)
            return 1;
    }

    return 0;
}

void removePage (ListPage* lp, char* key) {
    CellPG* aux, * aux_before;
    int aux_pos;

    aux = lp->first;
    aux_before = NULL;
    aux_pos = 0;

    while (aux != NULL && (samePage(aux->page, key) == 0)) {
        aux_before = aux;
        aux = aux->next;
        aux_pos++;
    }

    if(aux == NULL) {
        return;
    }

    if (aux == lp->first && aux == lp->last) {
        lp->first = lp->last = NULL;
    } else if (aux == lp->first) {
        lp->first = aux->next;

    } else if (aux == lp->last) {
        lp->last = aux_before;
        lp->last->next = NULL; 
    } else {
        aux_before->next = aux->next;
    }
    
    freePage(aux->page);
    free(aux);

}

void removeLink (ListPage* lp, char* key) {
    CellPG* aux, * aux_before;
    int aux_pos;

    aux = lp->first;
    aux_before = NULL;
    aux_pos = 0;

    while (aux != NULL && (samePage(aux->page, key) == 0)) {
        aux_before = aux;
        aux = aux->next;
        aux_pos++;
    }

    if(aux == NULL) {
        return;
    }

    if (aux == lp->first && aux == lp->last) {
        lp->first = lp->last = NULL;
    } else if (aux == lp->first) {
        lp->first = aux->next;

    } else if (aux == lp->last) {
        lp->last = aux_before;
        lp->last->next = NULL; 
    } else {
        aux_before->next = aux->next;
    }
    
    free(aux);

}

void showListLinks (FILE* file, ListPage* lp) {
    CellPG* aux;

    for (aux = lp->first; aux != NULL; aux = aux->next) {
        showLinksInfo(file, aux->page);
    }
}

void showListPage (ListPage* lp) {
    CellPG* aux;

    for (aux = lp->first; aux != NULL; aux = aux->next) {
        showPage(aux->page);
    }
}

void removeColabFromListPage (Page* page, char* keyColab) {
    removeColabFromPage(page, keyColab);
}

void freeListPage (ListPage* lp) {
    CellPG* aux1,* aux2;
    
    aux1 = lp->first;

    while (aux1 != NULL) {
        // free page's contents
        // libera conteudo da pagina
        freePage(aux1->page);
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }

    free(lp);
}

void freeListLink (ListPage* lp) {
    CellPG* aux1,* aux2;
    
    aux1 = lp->first;

    while (aux1 != NULL) {
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }

    free(lp);
}
