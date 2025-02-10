#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/uart.h"

// Definindo os pinos
#define LED_RGB_PIN_R 11    // Pino para o LED RGB Vermelho
#define LED_RGB_PIN_G 12    // Pino para o LED RGB Verde
#define LED_RGB_PIN_B 13    // Pino para o LED RGB Azul
#define BUTTON_A_PIN 5      // Pino do botão A
#define BUTTON_B_PIN 6      // Pino do botão B
#define LED_PIN 7           // Pino de controle da matriz 5x5 WS2812

// Variáveis para controle de LEDs
bool ledRGBVerdeEstado = false;
bool ledRGBAzulEstado = false;
unsigned long lastDebounceTimeA = 0;
unsigned long lastDebounceTimeB = 0;
int lastButtonStateA = 1;  
int lastButtonStateB = 1;  
int buttonStateA = 1;      
int buttonStateB = 1;      

// Função de setup
void setup() {
  // Inicializando os pinos de GPIO
  gpio_init(LED_RGB_PIN_R);
  gpio_set_dir(LED_RGB_PIN_R, GPIO_OUT);
  gpio_init(LED_RGB_PIN_G);
  gpio_set_dir(LED_RGB_PIN_G, GPIO_OUT);
  gpio_init(LED_RGB_PIN_B);
  gpio_set_dir(LED_RGB_PIN_B, GPIO_OUT);
  
  gpio_init(BUTTON_A_PIN);
  gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
  gpio_pull_up(BUTTON_A_PIN);  // Habilita o pull-up para o botão A

  gpio_init(BUTTON_B_PIN);
  gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
  gpio_pull_up(BUTTON_B_PIN);  // Habilita o pull-up para o botão B

  // Inicializando a comunicação serial
  stdio_init_all();
  
  // Exibindo uma mensagem inicial
  printf("Projeto RP2040\n");
}

// Função de loop
void loop() {
  // Monitorando os botões para interrupções de estado
  buttonStateA = gpio_get(BUTTON_A_PIN);
  buttonStateB = gpio_get(BUTTON_B_PIN);

  // Verificando o botão A (LED RGB Verde)
  if (buttonStateA == 0 && lastButtonStateA == 1 && (time_us_32() - lastDebounceTimeA) > 50000) { // 50ms de debounce
    ledRGBVerdeEstado = !ledRGBVerdeEstado;
    if (ledRGBVerdeEstado) {
      gpio_put(LED_RGB_PIN_G, 1);  // Acende o LED Verde
      printf("LED Verde Ligado\n");
    } else {
      gpio_put(LED_RGB_PIN_G, 0);   // Desliga o LED Verde
      printf("LED Verde Desligado\n");
    }
    lastDebounceTimeA = time_us_32();
  }

  // Verificando o botão B (LED RGB Azul)
  if (buttonStateB == 0 && lastButtonStateB == 1 && (time_us_32() - lastDebounceTimeB) > 50000) { // 50ms de debounce
    ledRGBAzulEstado = !ledRGBAzulEstado;
    if (ledRGBAzulEstado) {
      gpio_put(LED_RGB_PIN_B, 1);  // Acende o LED Azul
      printf("LED Azul Ligado\n");
    } else {
      gpio_put(LED_RGB_PIN_B, 0);   // Desliga o LED Azul
      printf("LED Azul Desligado\n");
    }
    lastDebounceTimeB = time_us_32();
  }

  // Atualizando a matriz de LEDs (apresentando números de 0 a 9)
  if (uart_is_readable(uart0)) {  // Verifica se há dados para ler na UART
    char incomingChar = uart_getc(uart0); // Lê o caractere da UART
    printf("Recebido: %c\n", incomingChar);

    // Simulando a matriz de LEDs (apenas exemplo simples)
    int number = incomingChar - '0';
    if (number >= 0 && number <= 9) {
      // Aqui você pode implementar a lógica para a matriz de LEDs
      printf("Simulando LED %d\n", number);
    }
  }

  lastButtonStateA = buttonStateA;
  lastButtonStateB = buttonStateB;
}

int main() {
  setup();

  while (true) {
    loop();
  }

  return 0;
}
