#ifndef LIST_EDITOR_H
#define LIST_EDITOR_H
#include "editor.h"

typedef struct listEditor ListEditor;

/* EN
 * Pre-condition: none
 * Post-condition: empty list of editors
 * 
 * PT
 * Pré-condição: nenhuma
 * Pós-condição: lista vazia de editores
 * 
 * Input: void
 * Output: ListEditor*
 */
ListEditor* initListEditor(void);

/* EN
 * Pre-condition: list of editors existes, key name is informed for the search
 * Post-condition: if editor with key name informed exists, returns editor, else returns NULL
 * 
 * PT
 * Pré-condição: lista de editores existe, nome chave eh informado para a busca
 * Pós-condição: se editor com o nome chave existe, o retorna, caso contrario retorna NULL
 * 
 * Input: ListEditor*, char*
 * Output: Editor*
 */
Editor* checkIfEditorInList (ListEditor* le, char* name);

/* EN
 * Pre-condition: list of editors and editor exists
 * Post-condition: editor added to list of editors
 * 
 * PT
 * Pré-condição: lista de editores e editor existe
 * Pós-condição: editor adicionada a lista de editor
 * 
 * Input: ListEditor*, Editor*
 * Output: void
 */
void addListEditor (ListEditor* le, Editor* ed);

/* EN
 * Pre-condition: list of editors exists
 * Post-condition: all of the memory allocated for list of editores and the editors is freed
 * 
 * PT
 * Pré-condição: lista de editores existe
 * Pós-condição: toda memoria alocada para lista de editores e os editores eh liberada
 * 
 * Input: ListEditor*
 * Output: void
 */
void freeListEditor (ListEditor* le);

#endif