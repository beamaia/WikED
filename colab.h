#ifndef COLAB_H
#define COLAB_H

#include <stdio.h>

typedef struct colab Colab;

/* EN
 * Pre-condition: name and path file informed
 * Post-condition: colab created
 * 
 * PT
 * Pré-condição: nome e caminho do arquivo informado
 * Pós-condição: colab criada
 * 
 * Input: char*, char*
 * Output: Colab*
 */
Colab* initColab (char* name, char* path);

/* EN
 * Pre-condition: compares colab's file name to "path"
 * Post-condition: if they're the same, returns 1, otherwise returns 0
 * 
 * PT
 * Pré-condição: compara o nome do arquivo de colab para "path"
 * Pós-condição: se sao iguais, retorna 1, caso contrario retorna 0
 * 
 * Input: Colab*, char*
 * Output: int
 */
int sameColab (Colab* colab, char* key);

/* EN
 * Pre-condition: file exists and colab exists
 * Post-condition: written editor's name in file
 * 
 * PT
 * Pré-condição: arquivo e colab existem
 * Pós-condição: nome do editor eh escrito no arquivo
 * 
 * Input: FILE*, Colab*
 * Output: void
 */
void showEditorName(FILE* file, Colab* colab);

/* EN
 * Pre-condition: file exists and colab exists
 * Post-condition: written colab's file name in file
 * 
 * PT
 * Pré-condição: arquivo e colab existem
 * Pós-condição: nome do arquivo de colaboracao eh escrito no arquivo
 * 
 * Input: FILE*, Colab*
 * Output: void
 */
void showColabFile (FILE* file, Colab* colab);

/* EN
 * Pre-condition: file exists and colab exists
 * Post-condition: both editor and colab's file name are written in file
 * 
 * PT
 * Pré-condição: arquivo e colab existem
 * Pós-condição: nome do editor e do arquivo de colaboracao eh escrito no arquivo
 * 
 * Input: FILE*, Colab*
 * Output: void
 */
void showColabHistory (FILE* file, Colab* colab);

/* EN
 * Pre-condition: file exists and colab exists
 * Post-condition: copies colab's file content into file
 * 
 * PT
 * Pré-condição: arquivo e colab existem
 * Pós-condição: copia o conteudo do arquivo de colaboracao para "file"
 * 
 * Input: FILE*, Colab*
 * Output: void
 */
void showColab (FILE* file, Colab* colab);

/* EN
 * Pre-condition: colab exists
 * Post-condition: memory allocated for colab is freed 
 * 
 * PT
 * Pré-condição: arquivo e colab existem
 * Pós-condição: memoria alocada para colab eh liberada
 * 
 * Input: Colab*
 * Output: void
 */
void freeColab (Colab* colab);
#endif