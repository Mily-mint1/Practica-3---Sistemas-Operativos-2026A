#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int pid;

int main () {
    // Creamos una copia del programa original para iniciar el proceso hijo
    pid = fork(); 
    
    switch (pid)
    {
        case -1:
            // El sistema no pudo crear el nuevo proceso por algun error
            printf ("\nNo he podido crear el proceso hijo");
            break;
            
        case 0:
            // Aqui inicia el codigo que solo va a ejecutar el hijo
            printf ("\nSoy el hijo, mi PID es %d y mi PPID es %d", getpid(), getppid());
            break;
            
        default:
            // El padre se detiene a esperar que el hijo termine su tarea
            wait(NULL); 
            // Aqui inicia el codigo que solo va a ejecutar el padre
            printf ("\nSoy el padre, mi PID es %d y el PID de mi hijo es %d", getpid(), pid);
            break;
    }
    
    // Este mensaje final lo imprimen ambos procesos antes de cerrarse
    printf ("\nFinal de ejecución de %d \n", getpid());
    exit (0);
}