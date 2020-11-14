/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two.
 * At the end the source code  should compile without warnings to the variant selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
 
const char* s1 = R"foo"(
Hello
World
)"foo"
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return 1; /* Es una función VOID , no retorna ningun valor. Solucion: Eliminar el return o parar la ejecución del programa, con una instruccion exit(0)*/
  }
  buf[strlen(buf) - 1] = '\0';
}

const char *get_dirname(const char *pathname) {
  char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    *slash = '\0'; /* Undefined behavior */
  }
  return pathname;
}
 

void get_y_or_n(void) {  
	char response[8]; /*Solo es necesario reservar memoria para un caracter , de esta manera estamos reservando memoria demás sin ningún sentido. Solución: [1]*/

	printf("Continue? [y] n: ");  
	gets(response); /*gets no es considerado seguro y actualmente su uso no está aconsejado , no tiene en cuenta el tamaño del buffer , ya que no lo toma como parámetro , por tanto, es muy fácil que se produzca un desbordamiento del mismo.
                      Solución: Utilizar fgets , ya que si que recibe como parámetro el tamaño del buffer.*/

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char *ptr_char  = "new string literal";
    int size_array1 = strlen("аналитик");
    int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик";
   // char analitic2[size_array2]="аналитик";
    char analitic3[100]="аналитик";

    puts(get_dirname(__FILE__));

        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);/*Encontramos 2 errores, se quiere imprimir la longitud del array1 , por tanto deberiamos poner size_arrray1. Por otro lado, el primer parametro que recibe la función printf deberia ser %d ,
                           que se utiliza para mostrar números y no %s , que se utiliza para imprimir una cadena de caracteres*/
    printf ("\n");
    printf ("%s",array2);/*Encontramos 2 errores, se quiere imprimir la longitud del array1 , por tanto deberiamos poner size_arrray1. Por otro lado, el primer parametro que recibe la función printf deberia ser %d ,
                           que se utiliza para mostrar números y no %s , que se utiliza para imprimir una cadena de caracteres*/
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N';
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}