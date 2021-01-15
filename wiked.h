#ifndef WIKED_H
#define WIKED_H

#include <stdio.h>
#include "listPage.h"
#include "listColab.h"
#include "listEditor.h"
#include "page.h"
#include "colab.h"
#include "editor.h"

/* EN
 * Pre-condition:
 * Post-condition:
 * 
 * PT
 * Pré-condição
 * Pós-condição:
 * 
 * Input:
 * Output:
 */


/**********************************************
 *     Functions related to instructions      *
 **********************************************/ 

/* EN
 * Pre-condition: File and list of pages exist
 * Post-condition: info about page is read and then page is inserted into list of pages
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: info de pagina eh lida e pagina eh inserida em lista de paginas
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void doInsertPage (FILE* file, ListPage* lp);

/* EN
 * Pre-condition: File and list of pages exist
 * Post-condition: info about page is read and then page is removed from list of pages
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: info de pagina eh lida e pagina eh removida da lista de paginas
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void doRemovePage (FILE* file, ListPage* lp);

/* EN
 * Pre-condition: File and list of editors exist
 * Post-condition: info about editor is read and then editor is inserted into list of editors
 * 
 * PT
 * Pré-condição: arquivo e lista de editores existem
 * Pós-condição: info de editor eh lida e editor eh inserido na lista de editores
 * 
 * Input: FILE*, ListEditor*
 * Output: void
 */
void doInsertEditor (FILE* file, ListEditor* le);

/* EN
 * Pre-condition: File and list of pages and editors exist
 * Post-condition: info about colab is read and then colab is inserted into list of editors and the page it belongs to
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas e editores existem
 * Pós-condição: info da colaboracao eh lida e colaboracao eh inserido na lista de editores e na pagina a qual pertence
 * 
 * Input: FILE*, ListPage*, ListEditor*
 * Output: void
 */
void doInsertColab (FILE* file, ListPage* lp, ListEditor* le);

/* EN
 * Pre-condition: File and list of pages and editors exist
 * Post-condition: info about colab is read and then colab status turn 0 (is "removed" from page)
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas e editores existem
 * Pós-condição: info da colaboracao eh lida e estado da colaboracao eh modificado para 0 (eh "removido" da pagina)
 * 
 * Input: FILE*, ListPage*, ListEditor*
 * Output: void
 */
void doRemoveColab (FILE* file, ListPage* lp, ListEditor* le);

/* EN
 * Pre-condition: File and list of pages exist
 * Post-condition: info about pages is read and then link is inserted into page
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: info da paginas eh lida e link eh inserida em pagina
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void doInsertLink(FILE* file, ListPage* lp);

/* EN
 * Pre-condition: File and list of pages exist
 * Post-condition: info about pages is read and then link is removed (status = 0)
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: info da paginas eh lida e link eh removido (estado = 0)
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void doRemoveLink(FILE* file, ListPage* lp);

/* EN
 * Pre-condition: File and list of pages exist
 * Post-condition: info about what page will be printed and page file is created
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: info sobre qual pagina sera impressa e arquivo da pagina eh criado
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void doShowPage (FILE* file, ListPage* lp);

/* EN
 * Pre-condition: File and list of pages exist
 * Post-condition: create files for all wiked pages
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas existem
 * Pós-condição: cria arquivos de todas as paginas do wiked
 * 
 * Input: FILE*, ListPage*
 * Output: void
 */
void doShowWiki (FILE* file, ListPage* lp);

/* EN
 * Pre-condition: File and list of pages and editors exist, id funtion is informed 
 * Post-condition: calls a function based on its id
 * 
 * PT
 * Pré-condição: arquivo e lista de paginas e editores existem, id da funcao eh informada
 * Pós-condição: chama uma funcao com base no seu id
 * 
 * Input: FILE*, int,  ListPage*, ListEditor*
 * Output: void
 */
void doInstruction (FILE* file, int id, ListPage* lp, ListEditor* le);

/* EN
 * Pre-condition: File and function's name 
 * Post-condition: prints error message on log.txt
 * 
 * PT
 * Pré-condição: arquivo e nome da funcao
 * Pós-condição: imprime mensagem de erro no log.txt
 * 
 * Input: FILE*, char*
 * Output: void
 */
void doErrorMessage (FILE* file, char* function);

/**********************************************
 *   Functions related to run or free WikED   *
 ********w**************************************/ 

/* EN
 * Pre-condition: entrance file exists, list of pages and editors exist
 * Post-condition: starts wiked and executes all written instructions 
 * 
 * PT
 * Pré-condição: arquivo de entrada existe, lista de paginas e editores existem
 * Pós-condição: inicia wiked e executa todas instrucoes lida
 * 
 * Input: FILE*, ListPage*, ListEditor*
 * Output: void
 */
void openWiked(FILE* file, ListPage* lp, ListEditor* le);

/* EN
 * Pre-condition: list of pages and editors exist
 * Post-condition: closes wiked, freeing all allocated memory 
 * 
 * PT
 * Pré-condição: lista de paginas e editores existem
 * Pós-condição: fecha wiked, liberando toda memoria alocada
 * 
 * Input: ListPage*, ListEditor*
 * Output: void
 */
void closeWiked (ListPage* lp, ListEditor* le);

/* EN
 * Pre-condition: entrance file exists, list of pages and editors exist
 * Post-condition: starts and closes wiked 
 * 
 * PT
 * Pré-condição: arquivo de entrada existe, lista de paginas e editores existem
 * Pós-condição: inicia e fecha wiked
 * 
 * Input: FILE*, ListPage*, ListEditor*
 * Output: void
 */
void wiked (FILE* file, ListPage* lp, ListEditor* le);

/**********************************************
 *    Functions related to check input file   *
 **********************************************/ 

/* EN
 * Pre-condition: log file, quantity of arguments read on terminal and arguments exist
 * Post-condition: varifies if the number of arguments is valid or if file is .txt. If it's not, closes the program with error
 * 
 * PT
 * Pré-condição: arquvi log, quantidade de argumentos e argumentos lido na linha do terminal
 * Pós-condição: verifica se o numero de argumentos eh valido ou se arquivo eh .txt. Caso nao, termina o programa com erro
 * 
 * Input: FILE*, int, char*
 * Output: void
 */
void checkInput(FILE * log, int argc, char* filePath);

#endif
