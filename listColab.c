#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listColab.h"
#include "colab.h"

/* EN
 * Cell structure pointing to a colab and the next cell. Also has a status indicator (used for pages)
 * 
 * PT
 * Estrutura de celula apontando para uma colaboracao e a proxima celula. Tambem tem um campo estado (usado para paginas)
 */ 
typedef struct cellColab CellColab;
struct cellColab {
    Colab* colab;
    CellColab* next;
    int status;
};

/* EN
 * Structure pointing to fist and last cells
 * 
 * PT 
 * Estrutura apontando para primeira e ultima celulas
 */ 
struct listColab {
    CellColab* first,
             * last;
};

ListColab* initListColab (void) {
    ListColab* lc = (ListColab*) malloc(sizeof(ListColab));
    lc->first = lc->last = NULL;
    return lc;
}

void addColabToListColab (ListColab* lc, Colab* colab) {
    CellColab* newCell = (CellColab*) malloc (sizeof(CellColab));
    
    newCell->colab = colab;
    newCell->next = NULL;

    // Status to 1 when used in page
    // Estado em 1 quando usado em pagina
    newCell->status = 1;

    if (lc->first == NULL) {
        lc->first = newCell;
    } else {
        lc->last->next = newCell;   
    }

    lc->last = newCell; 
}

Colab* checkIfColabExist (ListColab* lc, char* key) {
    CellColab* aux = NULL;

    // Search for colab with same file name as key
    // Procura colab com o mesmo nome de arquivo de key
    for(aux = lc->first; aux != NULL; aux=aux->next) {
        if (sameColab(aux->colab, key)) {
            break;
        }
    }

    // If no aux was found
    // Se nenhum aux foi encontrado
    if (aux == NULL)
        return NULL;

    // If it was found, but had no colab
    // Se foi encontrado, porem sem colab
    else if(aux->colab == NULL)
        return NULL;

    return aux->colab;
}

void showHistoryListColab (FILE* file, ListColab* lc) {
    CellColab* aux;
    // Prints list of colabs editor's and file name. If status = 0 (colab removed), prints "<<retirada>>"
    // Imprime nome do editor e doo arquivo de colaboracao. Se o estado == 0 (a colab foi retirada), imprime "<<retirada>>"
    for (aux = lc->first; aux != NULL; aux = aux->next) {
        showColabHistory(file, aux->colab);
        if(aux->status == 0)
            fprintf(file, " <<retirada>>");
        fprintf(file, "\n");
    }
}

void showListColab (FILE* file, ListColab* lc) {
    CellColab* aux;

    // prints colabs' file names
    // imprime nome dos arquivos das colaboracoes
    for (aux = lc->first; aux != NULL; aux = aux->next) {
        if(aux->status) {
            fprintf(file, "\n");
            showColab(file, aux->colab);
            fprintf(file, "\n");
        }
    }
}

void removeColab (ListColab* lc, char* key) {
    CellColab* aux;

    // changes status from 1 to 0
    // muda estado de 1 para 0
    for (aux = lc->first; aux != NULL; aux=aux->next) {
        if(sameColab(aux->colab, key)) {
            aux->status = 0; 
            break;
        }
    }
}

void freeAllColab (ListColab* lc) {
    CellColab* aux1,* aux2;
    
    aux1 = lc->first;

    // Free list of colabs and all colabs (used for editors)
    // Libera lista de colaboracoes e todas as colaboracoes (usado para editores)
    while (aux1 != NULL) {
        freeColab(aux1->colab);
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }

    free(lc);
}

void freeListColab (ListColab* lc) {
    CellColab* aux1,* aux2;
    
    aux1 = lc->first;

    // Free cells only
    // Libera celulas apenas
    while (aux1 != NULL) {
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }

    free(lc);
}
