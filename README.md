🗣️ Minitalk
Este proyecto fue mi primera toma de contacto seria con las señales de UNIX. El objetivo es el siguiente: crear un programa de comunicación Cliente-Servidor, 
pero con una restricción importante, solo podía usar dos señales para transmitir toda la información (SIGUSR1 y SIGUSR2).

¿Cómo funciona?
Como no podía pasar cadenas de texto de la forma habitual, tuve que bajar al nivel binario. Básicamente, el cliente descompone cada carácter del mensaje en sus 8 bits correspondientes y los envía uno a uno al servidor usando las señales:

SIGUSR1 representa un 0.

SIGUSR2 representa un 1.

El servidor actúa como un receptor que reconstruye el byte bit a bit hasta formar el carácter completo y lo imprime. Parece simple, pero el reto real estuvo en la sincronización: asegurar que el servidor tiene tiempo de procesar una señal antes de que llegue la siguiente, sin perder datos por el camino.

Características clave
Comunicación bit a bit: Uso intensivo de operadores bitwise (bit a bit) como >>, &, |.

Soporte Unicode: Funciona con caracteres especiales y emojis (👍), no se rompe con ASCII extendido.

Gestión de procesos: Uso de getpid() y kill() para manejar los PIDs.

Sin leaks: He tenido mucho cuidado con la gestión de memoria.

Cómo probarlo
El proyecto incluye un Makefile para compilar todo rápido.

Compila el proyecto:
make

Inicia el servidor:
./server (Verás que imprime su PID en la terminal. Cópialo).

Lanza el cliente (en otra terminal): Pásale el PID del servidor y el mensaje que quieras enviar.

./client [PID_DEL_SERVER] "Hola mundo 👋"
