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

int main (int argc, char *argv[]) {
    FILE* log,* input;    

    log = fopen("log.txt", "w");    

    checkInput(log, argc, argv[1]);

    input = fopen(argv[1], "r");

    ListPage* pages = initListPage();
    ListEditor* editors = initListEditor();

    wiked(input, pages, editors);
        
    fclose(log);
    fclose(input);

    return 0;
}