#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listPage.h"
#include "listColab.h"
#include "listEditor.h"
#include "page.h"
#include "colab.h"
#include "editor.h"
#include "wiked.h"
#define LIM 51

//-------Error messages------
/* EN - Possible errors:
 * Page already exists;
 * Page doesn't exist;
 * Page with file name already exists;
 * Editor already exists;
 * Editor doesn't exist;
 * Colab file doesn't exist;
 * Colab aready associated to an editor previously;
 * Colab not found in editor's colab list;
 * Colab aread exists in editor's colab list;
 * Direct link between 2 pages already exists;
 * Direct link doesn't exist between 2 pages.
 * 
 * PT - Erros possiveis:
 * Pagina ja existe;
 * Pagina nao existe;
 * Pagina com nome de arquivo ja existe;
 * Editor ja existe;
 * Editor nao existe;
 * Arquivo de colaboracao nao existe;
 * Colaboracao ja associada a um outro editor;
 * Colaboracao nao encontrada na lista de colaboracoes do editor;
 * Link direto entre 2 paginas ja existe;
 * Link direto nao existe entre 2 paginas.
 */ 

static void errorMessagePageExists (char* page) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: pagina %s já existe e não pode ser adicionada\n", page);
    fclose(log);
}

static void errorMessagePageDoesntExists (char* page) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: não existe a pagina %s\n", page);
    fclose(log);
}

static void erroMessaPageFileExists (char* page) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: já existe página com nome de arquivo %s\n", page);
    fclose(log);
}

static void errorMessageEditorExists (char* editor) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: editor %s já existe e não pode ser adicionado\n", editor);
    fclose(log);
}

static void errorMessageEditorDoesntExists (char* editor) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: não existe o editor %s\n", editor);
    fclose(log);
}

static void errorMessageColabFileDoesntExist (char* file) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: arquivo %s de contribuição não existe\n", file);
    fclose(log);
}

static void errorMessageColabAlreadyAddedEditor (char* file, char* editor) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: arquivo %s de contribuição já associado ao editor %s.\n", file, editor);
    fclose(log);
}

static void errorMessageNoColabInEditor (char* editor, char* colab) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: não existe um arquivo chamado %s associado ao editor %s\n", colab, editor);
    fclose(log);
}

static void errorMessageColabAlreadyAdded (char* colab, char* page) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: já existe uma colaboração %s na página %s\n", colab, page);
    fclose(log);
}

static void errorMessageLinkAlreadyExists (char* origin, char* destiny) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: já existe um link entre %s na página %s\n", origin, destiny);
    fclose(log);
}

static void errorMessageLinkDoesntExists (char* origin, char* destiny) {
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: não existe um link direto entre %s na página %s\n", origin, destiny);
    fclose(log);
}

//-------Instruction functions-------
void doInsertPage (FILE* file, ListPage* lp) {
    char pageName[LIM], pageFile[LIM];
    fscanf(file, "%s%*c", pageName);
    fscanf(file, "%s%*c", pageFile);

    Page* aux1 = checkIfPageExist(lp, pageName, samePage);
    Page* aux2 = checkIfPageExist(lp, pageFile, samePageFile);
    
    // checking errors
    // verificando erros
    if (aux1 != NULL) {
        errorMessagePageExists(pageName);
        return;
    } else if (aux2 != NULL) {
        erroMessaPageFileExists(pageFile);
        return;
    }

    aux1 = initPage(pageName, pageFile);
    addPageToListPage(lp, aux1);
}

void doRemovePage (FILE* file, ListPage* lp) {
    char pageName[LIM];
    fscanf(file, "%s%*c", pageName);

    Page* aux = checkIfPageExist(lp, pageName, samePage);

    // checking errors
    // verificando erros
    if (aux == NULL) {
       errorMessagePageDoesntExists(pageName);
        return;
    }

   removePage(lp, pageName);
}

void doInsertEditor (FILE* file, ListEditor* le) {
    char editorName[LIM];
    fscanf(file, "%s%*c", editorName);

    Editor* ed = checkIfEditorInList(le, editorName);

    // checking errors
    // verificando erros
    if (ed != NULL) {
        errorMessageEditorExists(editorName);
        return;       
    }

    ed = initEditor(editorName);
    addListEditor(le, ed);
}

void doInsertColab (FILE* file, ListPage* lp, ListEditor* le) {
    char pageName[LIM], editorName[LIM], fileName[LIM];
    fscanf(file, "%s%*c", pageName);
    fscanf(file, "%s%*c", editorName);
    fscanf(file, "%s%*c", fileName);

    Page* page = checkIfPageExist(lp, pageName, samePage);
    Editor* ed = checkIfEditorInList(le, editorName);

    // checking errors
    // verificando erros
    if (page == NULL) {
        errorMessagePageDoesntExists(pageName);
        return;  
    } else if (ed == NULL) {
       errorMessageEditorDoesntExists(editorName);
        return;  
    }

    FILE* aux = fopen(fileName, "r");

    // checking errors
    // verificando erros
    if (aux == NULL) {
        errorMessageColabFileDoesntExist(fileName);
        return;
    }

    fclose(aux);
    Colab* col = checkColabInEditor(ed, fileName);

    // checking errors
    // verificando erros
    if (col != NULL) {
        errorMessageColabAlreadyAddedEditor(fileName, editorName);
        return;
    }
    
    col = checkColabInPage(page, fileName);

    // checking errors
    // verificando erros
    if (col != NULL) {
        errorMessageColabAlreadyAdded(fileName, pageName);
        return;
    }

    Colab* colab = initColab(editorName, fileName);
    
    addColabEditor(ed, colab);
    addColabToPage(page, colab);
}

void doRemoveColab (FILE* file, ListPage* lp, ListEditor* le) {
    char pageName[LIM], editorName[LIM], fileName[LIM];
    fscanf(file, "%s%*c", pageName);
    fscanf(file, "%s%*c", editorName);
    fscanf(file, "%s%*c", fileName);

    Page* page = checkIfPageExist(lp, pageName, samePage);
    Editor* ed = checkIfEditorInList(le, editorName);

    // checking errors
    // verificando erros
    if (page == NULL) {
        errorMessagePageDoesntExists(pageName);
        return;  
    } else if (ed == NULL) {
        errorMessageEditorDoesntExists(editorName);
        return;  
    }

    Colab* colab = checkColabInEditor(ed, fileName);

    // checking errors
    // verificando erros
    if (colab == NULL) {
        errorMessageNoColabInEditor(editorName, fileName);
        return;
    }

    removeColabFromListPage(page, fileName);
}

void doInsertLink (FILE* file, ListPage* lp) {
    char pageOrigin[LIM], pageDestiny[LIM];

    fscanf(file, "%s%*c", pageOrigin);
    fscanf(file, "%s%*c", pageDestiny);

    Page* origin = checkIfPageExist(lp, pageOrigin, samePage);
    Page* destiny = checkIfPageExist(lp, pageDestiny, samePage);

    // checking errors
    // verificando erros
    if (origin == NULL) {
        errorMessagePageDoesntExists(pageOrigin);
        return;
    } else if (destiny == NULL) {
        errorMessagePageDoesntExists(pageDestiny);
        return;
    }

    Page* link = checkIfLinkExists(origin, pageDestiny);

    // checking errors
    // verificando erros
    if (link != NULL) {
        errorMessageLinkAlreadyExists(pageOrigin, pageDestiny);
        return;
    }

    addLinkToPage(origin, destiny);
}

void doRemoveLink (FILE* file, ListPage* lp) {
    char pageOrigin[LIM], pageDestiny[LIM];

    fscanf(file, "%s%*c", pageOrigin);
    fscanf(file, "%s%*c", pageDestiny);

    Page* origin = checkIfPageExist(lp, pageOrigin, samePage);
    Page* destiny = checkIfPageExist(lp, pageDestiny, samePage);

    // checking errors
    // verificando erros
    if (origin == NULL) {
        errorMessagePageDoesntExists(pageOrigin);
        return;
    } else if (destiny == NULL) {
        errorMessagePageDoesntExists(pageDestiny);
        return;
    }

    Page* link = checkIfLinkExists(origin, pageDestiny);

    // checking errors
    // verificando erros
    if (link == NULL) {
        errorMessageLinkDoesntExists(pageOrigin, pageDestiny);
        return;
    }

    removeLinkFromPage(origin, destiny);
}

void doFindPath(FILE* file, ListPage* lp) {
    char pageOrigin[LIM], pageDestiny[LIM];

    fscanf(file, "%s%*c", pageOrigin);
    fscanf(file, "%s%*c", pageDestiny);

    Page* origin = checkIfPageExist(lp, pageOrigin, samePage);
    Page* destiny = checkIfPageExist(lp, pageDestiny, samePage);

    // checking errors
    // verificando erros
    if (origin == NULL) {
        errorMessagePageDoesntExists(pageOrigin);
        return;
    } else if (destiny == NULL) {
        errorMessagePageDoesntExists(pageDestiny);
        return;
    }

    FILE* log = fopen("log.txt", "a");

    ListPage* links = initListPage();
    addPageToListPage(links, origin);
    changeStatusToOne(links);

    int status = checkLinkPage (origin, pageDestiny, links);

    if (status) {
        fprintf(log, "HA CAMINHO DA PAGINA %s PARA %s\n", pageOrigin, pageDestiny);
    } else {
        fprintf(log, "NAO HA CAMINHO DA PAGINA %s PARA %s\n", pageOrigin, pageDestiny);
    }

    freeListLink(links);

    fclose(log);
}

void doShowPage (FILE* file, ListPage* lp) {
    char pageName[LIM];
    fscanf(file, "%s%*c", pageName);

    Page* page = checkIfPageExist(lp, pageName, samePage);

    // checking errors
    // verificando erros
    if (page == NULL) {
        errorMessagePageDoesntExists(pageName); 
        return; 
    }

    showPage(page);
}

void doShowWiki (FILE* file, ListPage* lp) {
    showListPage(lp);
}

void doErrorMessage (FILE* file, char* function) {
    char line[LIM];
    fscanf(file, "%[^\n]%*c", line);
    
    FILE* log = fopen("log.txt", "a");
    fprintf(log, "ERRO: Função %s ainda não suportada nesta versão da WikED!\n", function);
    fclose(log);
}

static int getFunctionID (char* function) {    
    if (strcmp(function, "INSEREPAGINA") == 0)
        return 1;
    else if (strcmp(function, "RETIRAPAGINA") == 0)
        return 2;
    else if (strcmp(function, "INSEREEDITOR") == 0)
        return 3;
    else if (strcmp(function, "INSERECONTRIBUICAO") == 0)
        return 4;
    else if (strcmp(function, "RETIRACONTRIBUICAO") == 0)
        return 5;
    else if (strcmp(function, "INSERELINK") == 0)
        return 6;
    else if (strcmp(function, "RETIRALINK") == 0)
        return 7;
    else if (strcmp(function, "CAMINHO") == 0)
        return 8;
    else if (strcmp(function, "IMPRIMEPAGINA") == 0)
        return 9;
    else if (strcmp(function, "IMPRIMEWIKED") == 0)
        return 10;
    else if (strcmp(function, "FIM") == 0)
        return 11;
    else {
        return 0;
    }
}

void doInstruction (FILE* file, int id, ListPage* lp, ListEditor* le) {
    switch (id) {
        case 1: doInsertPage(file, lp);
                break;
        case 2: doRemovePage(file, lp);
                break;
        case 3: doInsertEditor(file, le);
                break;
        case 4: doInsertColab(file, lp, le);
                break;
        case 5: doRemoveColab(file, lp, le);
                break;
        case 6: doInsertLink(file, lp);
                break;
        case 7: doRemoveLink(file, lp);
                break;
        case 8: doFindPath(file, lp);
                break;
        case 9: doShowPage(file, lp);
                break;
        case 10: doShowWiki(file, lp);
                 break;
        default: doErrorMessage(file, "NOME DESCONHECIDO");
                 break;
    }
}


//-------Funtions for opening and closing WikEd-------
void wiked (FILE* file, ListPage* lp, ListEditor* le) {
    openWiked(file, lp, le);
    closeWiked(lp, le);
}

void openWiked (FILE* file, ListPage* lp, ListEditor* le) {
    char instruction[LIM];
    int id;

    if (lp == NULL || le == NULL) {
        FILE* log = fopen("log.txt", "a");
        fprintf(log, "ERRO: listas não iniciadas\n");
        fclose(log);
        fclose(file);
        exit(1);
    }

    while(fscanf(file, "%s%*c", instruction)) {
        id = getFunctionID(instruction);
        if (id == 11)
            break;

        if (id == 0) {
            doErrorMessage(file, instruction);
            continue;
        }
        doInstruction(file, id, lp, le);
    }
}

void closeWiked (ListPage* lp, ListEditor* le) {
    freeListPage(lp);
    freeListEditor(le);
}


//-------Functions for checking arguments-------
static void checkArguments(FILE * log, int argc, char* filePath) {
    if (argc == 1) {
        fprintf(log, "ERRO: arquivo de entrada não informado.\n");
        fclose(log);
        exit(1);
    } else if (argc > 2) {
        fprintf(log, "ERRO: mais que um arquivo informado para entrada.\n");
        fclose(log);
        exit(1);        
    }

    FILE* aux = fopen(filePath, "r");
    if (aux == NULL) {
        fprintf(log, "ERRO: arquivo de entrada não existe.\n");
        fclose(log);
        exit(1);     
    }

    fclose(aux);
}

static void checkTxt (FILE* log, char* filePath){
    char txt[] = ".txt";
    int isNotTxt = 0;
    for(int i = strlen(filePath) - 4, j = 0; i < strlen(filePath) - 1; i++, j++) {
        if(filePath[i] != txt[j]) {
            isNotTxt = 1;
            break;
        }
    }

    if (isNotTxt) {
        fprintf(log, "ERRO: arquivo de entrada não é .txt!\n");
        fclose(log);
        exit(1);
    }
}

void checkInput(FILE * log, int argc, char* filePath) {
    checkArguments(log, argc, filePath);
    //checkTxt(log, filePath);
}