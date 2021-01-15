#ifndef EDITOR_H
#define EDITOR_H

#include <stdio.h>
#include "colab.h"

typedef struct editor Editor;

/* EN
 * Pre-condition: editor name exists
 * Post-condition: editor created with name and empty list of colabs
 * 
 * PT
 * Pré-condição: nome do editor existe
 * Pós-condição: editor criado com nome e lista vazia de colabs
 * 
 * Input: char*
 * Output: Editor*
 */
Editor* initEditor (char*);

/* EN
 * Pre-condition: editor exists, char* key is informed
 * Post-condition: function returns 1 if the same editor, 0 if not
 * 
 * PT
 * Pré-condição: editor existe, char* key eh informado
 * Pós-condição: funcao retorna 1 se eh o editor, 0 se nao
 * 
 * Input: Editor*, char*
 * Output: int
 */
int sameEditor(Editor*, char*);

/* EN
 * Pre-condition: editor and colab exists
 * Post-condition: colab added to editor's list of colab.
 * 
 * PT
 * Pré-condição: editor e colaboracao existem
 * Pós-condição: colaboracao eh adicinada a lista de colaboracoes do editor
 * 
 * Input: Editor*, Colab*
 * Output: void
 */
void addColabEditor (Editor*, Colab*);

/* EN
 * Pre-condition: editor exists and colab file name is informed
 * Post-condition: colab with file name that was informed is returned
 * 
 * PT
 * Pré-condição: editor existe e nome de arquivo de colab informado 
 * Pós-condição: colab com o nome de arquivo informado eh retornadp
 * 
 * Input: Editor*, char*
 * Output: Colab*
 */
Colab* checkColabInEditor(Editor* ed, char* fileName);

/* EN
 * Pre-condition: editor exists
 * Post-condition: all of the memory allocated for editor and their colabs is freed
 * 
 * PT
 * Pré-condição: editor existe
 * Pós-condição: toda memoria alocada do editor e suas colaboracoes eh liberada
 * 
 * Input: Editor*
 * Output: void
 */
void freeEditor (Editor*);

#endif