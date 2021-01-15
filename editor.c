#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listColab.h"
#include "editor.h"
#include "colab.h"

/* EN
 * char* name: editor's name
 * ListColab* listColab: list of colabs written by editor
 * 
 * PT
 * char* name: nome do editor 
 * ListaColab* listColab: lista de colaboracoes escrito pelo editor
 */ 
struct editor{
    char* name;
    ListColab* listColab;
};

Editor* initEditor (char* name) {
    Editor* ed = (Editor*) malloc(sizeof(Editor));

    ed->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(ed->name, name);

    ed->listColab = initListColab();

    return ed;
}

int sameEditor(Editor *ed, char* key) {
    if (strcmp(ed->name, key) == 0) 
        return 1;
    return 0;   
}

void addColabEditor (Editor* ed, Colab* colab) {
    addColabToListColab(ed->listColab, colab);
}

Colab* checkColabInEditor(Editor* ed, char* fileName){
    // If list of colab doesn't exist
    // Se lista de colaboracoes nao existe
    if (ed->listColab == NULL)
        return NULL;
    
    Colab* aux = checkIfColabExist(ed->listColab, fileName);
    
    if (aux == NULL)
        return NULL;
    return aux;
}

void freeEditor (Editor* ed) {
    freeAllColab(ed->listColab);
    free(ed->name);
    free(ed);
}