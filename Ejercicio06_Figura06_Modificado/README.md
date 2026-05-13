---
title: "3.2.1 Crear un proceso hijo que realice una tarea usando execl."
authors: Karen Tapia
format: 
  html:
    embed-resources: true
    theme: cozy
    toc: true
    title-block-banner: "#2c3e50" # Color de fondo oscuro
    title-block-banner-color: "white" # Color de la letra
    include-in-header:
      text: |
        <style>
        .quarto-title-block .quarto-title-banner {
          background-image: url("./Imagenes/logo.png");
          background-repeat: no-repeat;
          background-position: right 10px center;
          background-size: 60px;
        }
        </style>


    
---
## Ejercicio 2: Uso de EXCEC para crear procesos hijos
En este ejercicio se ha creado un programa en C que utiliza la función `exec` para crear un proceso hijo te tendrá la tarea de mostrar la fecha. El programa principal (padre) crea un proceso hijo utilizando `fork()`, y luego el proceso hijo ejecuta un nuevo programa utilizando `exec()`.

### Explicación del código

1. El programa comienza incluyendo las bibliotecas necesarias: `<stdio.h>`, `<stdlib.h>`, `<unistd.h>`, y `<sys/wait.h>`. 

![](./Imagenes/blibliotecas.png){fig-align="center" width="350px"}

2. Se crea una variable `pid` para almacenar el ID del proceso hijo.

3. Se crea prepara la identidad del proceso hijo mediante la construccion de la variable `char *args[]` que contiene el comando `date` y un puntero nulo al final. 

![](./Imagenes/date.png){fig-align="center" width="400px"}

4. Se utiliza `fork()` para crear un proceso hijo. Si `fork()` devuelve un valor negativo, significa que hubo un error al crear el proceso hijo, y se imprime un mensaje de error. 

![](./Imagenes/fork.png){fig-align="center" width="400px"}

5. Si `fork()` devuelve 0, significa que estamos en el proceso hijo, y se ejecuta el comando `date` utilizando `execvp()`. Si `execvp()` falla, se imprime un mensaje de error.

![](./Imagenes/cero.png){fig-align="center" width="400px"}

6. Si `fork()` devuelve un valor positivo, significa que estamos en el proceso padre, y se espera a que el proceso hijo termine utilizando `wait()`.

![](./Imagenes/positivo.png){fig-align="center" width="400px"}

7. Finalmente, el programa retorna 0 para indicar que ha terminado correctamente.

### Ejecución del programa
Una vez compilado el programa, se ejecuta en la terminal y se muestra la fecha actual, que es el resultado del comando `date` ejecutado por el proceso hijo.

![](./Imagenes/ejec.png){fig-align="center" width="400px"}
# Aqui ingresan la explicacion de sus modificaciones y muestran captura de pantalla de que ejecuto
