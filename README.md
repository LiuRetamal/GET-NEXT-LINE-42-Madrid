*Este proyecto ha sido creado como parte del currículo de 42 por <lretamal>.*

# Get Next Line

## Descripción
El objetivo de este proyecto es implementar la función `get_next_line`, que permite leer un archivo línea por línea de manera eficiente.  

La función se comporta de la siguiente manera:  

- Devuelve la siguiente línea disponible de un descriptor de archivo (`fd`) cada vez que se llama.  
- La línea devuelta termina con un salto de línea `\n`, excepto si se alcanza el final del archivo sin un salto de línea.  
- Devuelve `NULL` cuando no hay más líneas que leer o si ocurre un error durante la lectura.  
- Permite leer desde archivos normales y desde la entrada estándar (`stdin`).   

## Instrucciones de compilación
Para compilar el proyecto, se usan los siguientes comandos. Se puede compilar con o sin el indicador -D BUFFER_SIZE. Y el valor de BUFFER_SIZE se puede modificar:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_lext_line

Para compilar la parte del bonus se emplea del mismo modo pero con los archivos _bonus:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o get_lext_line_bonus

Para su ejecución, ejecuta:

./get_lext_line
./get_lext_line_bonus

## Algoritmo y Justificación
La función `get_next_line` se implementa usando un **buffer dinámico** de tamaño `BUFFER_SIZE`, que se define al compilar el programa con el flag `-D BUFFER_SIZE=n`.  

1. Se lee del descriptor de archivo en bloques de `BUFFER_SIZE` bytes.  
2. Se almacena cualquier contenido restante de lecturas anteriores en una **variable estática** para poder continuar leyendo la línea sin perder datos.  
3. Cuando se detecta un salto de línea `\n` en el buffer acumulado, se separa la línea completa y se devuelve.  
4. Si no se encuentra un salto de línea, se continúa leyendo hasta completarla o llegar al final del archivo.  

Este enfoque permite:  
- Leer el archivo **mínimamente**, sin cargarlo entero en memoria.  
- Manejar correctamente archivos de cualquier tamaño y con cualquier `BUFFER_SIZE`.  
- Mantener el estado entre llamadas sin usar variables globales.

## Recursos

- `get_next_line.c` : Contiene la función principal `get_next_line`.  
- `get_next_line_utils.c` : Funciones auxiliares necesarias para el manejo de strings y buffers.  
- `get_next_line.h` : Cabecera con el prototipo de la función y definiciones necesarias.
- `get_next_line_bonus.c` : Contiene la función principal del bonus.  
- `get_next_line_utils_bonus.c` : Funciones auxiliares necesarias para el bonus.  
- `get_next_line_bonus.h` : Definiciones necesarias para el bonus. 