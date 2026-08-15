#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void)
{
    srand(time(NULL));

    printf("Linux IoT Sensor Simulator\n");
    printf("===========================\n");

    while (1)
    {
        float temperature = 20.0f + (rand() % 1500) / 100.0f;
        float humidity = 40.0f + (rand() % 5000) / 100.0f;

        printf("Temperature: %.2f C | Humidity: %.2f %%\n",
               temperature, humidity);

        sleep(2);
    }

    return 0;
}
