# dps-lab-1
Laboratory 1


Para la realización de la práctica, he utilizado mi equipo personal , con SO Windows 10.
Para poder compilar el programa utilizando GCC , e instalado MinGW y la extensión de GCC. Una vez realizada la intalación, desde un CMD , he clonado el repositorio de GitHub a una carpeta de mi equipo y a continuación he ido realizando las siguientes compilaciones, obteniendo las diferentes salidas:


## Compilacion con gcc sin estandares
```
***gcc -Wall exampleStrings.c***

La salida obtenida es la siguiente:


exampleStrings.c: In function 'gets_example_func':
exampleStrings.c:32:16: warning: 'return' with a value, in function returning void [-Wreturn-type]
   32 |         return 1;
      |                ^
exampleStrings.c:28:6: note: declared here
   28 | void gets_example_func(void) {
      |      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function 'main':
exampleStrings.c:73:10: warning: unused variable 'analitic3' [-Wunused-variable]
   73 |     char analitic3[100]="ð░ð¢ð░ð╗ð©Ð          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable 'size_array2' [-Wunused-variable]
   69 |     int size_array2 = 100;
      |         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable 'size_array1' [-Wunused-variable]
   68 |     int size_array1 = strlen("ð░ð¢ð░ð╗ð©Ð


```
A continuación,he realizado la compilación con el estandar c99 y c11 , las salidas de compilación son las siguientes:


## Salida de compilación con el estándar c99 - ***gcc -Wall -std=c99***
```
Salida:

exampleStrings.c:22:19: warning: missing terminating " character
   22 | const char* s1 = R"foo(
      |                   ^
exampleStrings.c:22:19: error: missing terminating " character
   22 | const char* s1 = R"foo(
      |                   ^~~~~
exampleStrings.c:22:18: error: 'R' undeclared here (not in a function)
   22 | const char* s1 = R"foo(
      |                  ^
exampleStrings.c:23:1: error: expected ',' or ';' before 'Hello'
   23 | Hello
      | ^~~~~
exampleStrings.c:25:5: warning: missing terminating " character
   25 | )foo";
      |     ^
exampleStrings.c:25:5: error: missing terminating " character
   25 | )foo";
      |     ^~
exampleStrings.c: In function 'gets_example_func':
exampleStrings.c:32:16: warning: 'return' with a value, in function returning void [-Wreturn-type]
   32 |         return 1;
      |                ^
exampleStrings.c:28:6: note: declared here
   28 | void gets_example_func(void) {
      |      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function 'main':
exampleStrings.c:94:11: error: 's2' undeclared (first use in this function); did you mean 's1'?
   94 |     puts (s2);
      |           ^~
      |           s1
exampleStrings.c:94:11: note: each undeclared identifier is reported only once for each function it appears in
exampleStrings.c:73:10: warning: unused variable 'analitic3' [-Wunused-variable]
   73 |     char analitic3[100]="ð░ð¢ð░ð╗ð©Ð          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable 'size_array2' [-Wunused-variable]
   69 |     int size_array2 = 100;
      |         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable 'size_array1' [-Wunused-variable]
   68 |     int size_array1 = strlen("ð░ð¢ð░ð╗ð©Ð         ^~~~~~~~~~~


## Salida de compilación con el estándar c11 - ***gcc -Wall -std=c11***
```

Salida:

exampleStrings.c:22:19: warning: missing terminating " character
   22 | const char* s1 = R"foo(
      |                   ^
exampleStrings.c:22:19: error: missing terminating " character
   22 | const char* s1 = R"foo(
      |                   ^~~~~
exampleStrings.c:22:18: error: 'R' undeclared here (not in a function)
   22 | const char* s1 = R"foo(
      |                  ^
exampleStrings.c:23:1: error: expected ',' or ';' before 'Hello'
   23 | Hello
      | ^~~~~
exampleStrings.c:25:5: warning: missing terminating " character
   25 | )foo";
      |     ^
exampleStrings.c:25:5: error: missing terminating " character
   25 | )foo";
      |     ^~
exampleStrings.c: In function 'gets_example_func':
exampleStrings.c:32:16: warning: 'return' with a value, in function returning void [-Wreturn-type]
   32 |         return 1;
      |                ^
exampleStrings.c:28:6: note: declared here
   28 | void gets_example_func(void) {
      |      ^~~~~~~~~~~~~~~~~
exampleStrings.c: In function 'main':
exampleStrings.c:94:11: error: 's2' undeclared (first use in this function); did you mean 's1'?
   94 |     puts (s2);
      |           ^~
      |           s1
exampleStrings.c:94:11: note: each undeclared identifier is reported only once for each function it appears in
exampleStrings.c:73:10: warning: unused variable 'analitic3' [-Wunused-variable]
   73 |     char analitic3[100]="ð░ð¢ð░ð╗ð©Ð          ^~~~~~~~~
exampleStrings.c:69:9: warning: unused variable 'size_array2' [-Wunused-variable]
   69 |     int size_array2 = 100;
      |         ^~~~~~~~~~~
exampleStrings.c:68:9: warning: unused variable 'size_array1' [-Wunused-variable]
   68 |     int size_array1 = strlen("ð░ð¢ð░ð╗ð©Ð         ^~~~~~~~~~~


```
En mi caso , he decidido solucionar los errores para el caso de compilacion con GCC y estándar C99. En el archivo exampleStrings_warnings, se muestra en el código el porqué de los fallos , con un comentario en la linea de código correspondiente. En el archivo exampleStrings_corregido.c se muestra el código ya corregido sin warnings tras la compilación.


##Reglas CMU-Cert que incumple el código:
```
* STR31-C: Guarantee that storage for strings has sufficient space for character data
and the null terminator --> Línea 51
* MSC34-C: Do not use deprecated or obsolescent functions --> Línea 51
* MEM35-C. Always allocate sufficient memory for an object --> Líneas 17,18,61
* STR30-C: Do not attempt to modify String literals --> Línea 101
* ARR02-C. Explicitly specify array bounds, even if implicitly defined by an initializer --> Línea 18



