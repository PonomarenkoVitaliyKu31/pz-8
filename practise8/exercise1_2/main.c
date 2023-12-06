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
    struct sigaction sa;

    // Встановлюємо обробник для SIGINT
    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    // Встановлюємо обробник для SIGTERM
    sa.sa_handler = handle_sigterm;
    sigaction(SIGTERM, &sa, NULL);

    // Встановлюємо обробник для SIGUSR1
    sa.sa_handler = handle_sigusr1;
    sigaction(SIGUSR1, &sa, NULL);

    // Сигнали SIGPROF і SIGHUP обробляються за замовчуванням (ігноруються і встановлюється стандартна обробка)
    signal(SIGPROF, SIG_DFL);
    signal(SIGHUP, SIG_IGN);

    // Безкінечний цикл для очікування сигналів
    while (1) {
        pause();
    }

    return 0;
}
