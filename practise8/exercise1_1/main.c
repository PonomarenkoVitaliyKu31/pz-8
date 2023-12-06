#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Обробник для SIGINT
void handle_sigint(int signum) {
    printf("Споймано сигнал SIGINT. Процес продовжить виконання.\n");
}

// Обробник для SIGTERM
void handle_sigterm(int signum) {
    printf("Споймано сигнал SIGTERM. Процес продовжить виконання.\n");
}

// Обробник для SIGUSR1
void handle_sigusr1(int signum) {
    printf("Споймано сигнал SIGUSR1. Завершення роботи...\n");
    exit(0);
}

int main() {
    // Встановлюємо обробники сигналів
    signal(SIGINT, handle_sigint);
    signal(SIGTERM, handle_sigterm);
    signal(SIGUSR1, handle_sigusr1);

    // Сигнали SIGPROF і SIGHUP обробляються за замовчуванням (ігноруються і встановлюється стандартна обробка)
    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);

    // Безкінечний цикл для очікування сигналів
    while (1) {
        pause();
    }

    return 0;
}
