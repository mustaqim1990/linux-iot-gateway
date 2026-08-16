#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t running = 1;

void handle_signal(int signal)
{
    running = 0;
}

int main(void)
{
    srand(time(NULL));

    printf("Linux IoT Sensor Simulator\n");
    printf("===========================\n");
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (running)
    {
        float temperature = 20.0f + (rand() % 1500) / 100.0f;
        float humidity = 40.0f + (rand() % 5000) / 100.0f;

        printf("Temperature: %.2f C | Humidity: %.2f %%\n",
               temperature, humidity);

        sleep(2);
    }
    printf("\nShutdown signal received.\n");
    printf("Sensor simulator stopped.\n" );
    return 0;
}
