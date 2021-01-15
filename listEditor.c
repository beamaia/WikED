#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listEditor.h"
#include "editor.h"

/* EN
 * Cell structure pointing to an editor and the next cell
 * 
 * PT
 * Estrutura de celula apontando para um editor e a proxima celula
 */ 
typedef struct cellEd CellEd;
struct cellEd {
    Editor* editor;
    CellEd* next;
};

/* EN
 * Structure pointing to fist and last cells
 * 
 * PT 
 * Estrutura apontando para primeira e ultima celulas
 */ 
struct listEditor {
    CellEd* first,
          * last;
};

ListEditor* initListEditor(void) {
    ListEditor* le = (ListEditor*) malloc(sizeof(ListEditor));
    le->first = le->last = NULL;
    return le;
}

Editor* checkIfEditorInList (ListEditor* le, char* name) {
    CellEd* aux;

    // Looks for editor in list with the same name as "name"
    // Procura por um editor na lista com o mesmo nome que "name"
    for(aux = le->first; aux != NULL; aux=aux->next) {
        if(sameEditor(aux->editor, name)==1)
            break;

    }
    
    if (aux == NULL) 
        return NULL;

    return aux->editor;
}

void addListEditor (ListEditor* le, Editor* ed) {
    CellEd* newCell = (CellEd*) malloc (sizeof(CellEd));
    
    newCell->editor = ed;
    newCell->next = le->first;
    le->first = newCell;

    // If the list is empty
    if (le->last == NULL) {
        le->last = newCell;
    }
}

void freeListEditor (ListEditor* le) {
    CellEd* aux1,* aux2;
    
    aux1 = le->first;

    while (aux1 != NULL) {
        freeEditor(aux1->editor);
        aux2 = aux1->next;
        free(aux1);
        aux1 = aux2;
    }

    free(le);
}