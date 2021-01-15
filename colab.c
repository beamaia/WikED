#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listEditor.h"
#include "listColab.h"
#include "colab.h"
#define LIM 100

/* EN
 * Struct with editor's and colab's file name and 
 * 
 * PT
 * Estrutura com nome do editor e do arquivo de colaboracao
 */
struct colab {
    char* editor;
    char* fileName;
};

Colab* initColab (char* name, char* path) {
    Colab* colab = (Colab*) malloc(sizeof(Colab));

    colab->fileName = (char*) malloc(sizeof(char) * (strlen(path) + 1));
    strcpy(colab->fileName, path);
    colab->editor = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(colab->editor, name);

    return colab;
}

int sameColab (Colab* colab, char* key) {
    // Compares colab->fileName to key
    // Compara colab-fileName a "key"
    if (strcmp(colab->fileName, key) == 0)
        return 1;
    return 0;
}

void showEditorName(FILE* file, Colab* colab) {
    // Prints colab's editor's name in file
    // Imprime o nome do arquivo da colaboracao em "file"
    fprintf(file, "%s", colab->editor);
}

void showColabFile (FILE* file, Colab* colab) {
    // Prints colab's file name in file
    // Imprime nome de arquivo da colaboracao em "file"
    fprintf(file, "%s", colab->fileName);
}

void showColabHistory (FILE* file, Colab* colab) {
    // Writes editor's and colab's file name on file
    // Imprime nome do editor e do arquivo de colaboracao em "file"
    showEditorName(file, colab);
    fprintf(file, " ");
    showColabFile(file, colab);
}

void showColab (FILE* file, Colab* colab) {
    // Copies colab's file contant into file
    // Copia o conteudo do arquivo de colaboracao em "file"

    fprintf(file, "-------- ");
    showColabFile(file, colab);
    fprintf(file, " (");
    showEditorName(file, colab);
    fprintf(file, ") --------\n\n");

    FILE* aux = fopen(colab->fileName, "r");
    char aux_char;
    
    // Copies char per char
    // Copia caracter por caracter
    aux_char = fgetc(aux); 
    while (aux_char != EOF) { 
        fputc(aux_char, file);
        aux_char = fgetc(aux);
    }

    fclose(aux);
}

void freeColab (Colab* colab) {
    free(colab->editor);
    free(colab->fileName);
    free(colab);
}