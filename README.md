# Projeto RP2040 - Controle de LEDs RGB e Matriz WS2812 com Botões e UART

Este projeto foi desenvolvido para o microcontrolador RP2040 utilizando a biblioteca de hardware do Raspberry Pi Pico. Ele controla LEDs RGB e uma matriz de LEDs WS2812 com base em entradas de botões e dados recebidos via comunicação UART.

## Funcionalidades:

- **LEDs RGB:**  
  O projeto controla dois LEDs RGB (Verde e Azul) que podem ser ligados e desligados pressionando os botões conectados aos pinos GPIO 5 e 6.

- **Botões:**
  - **Botão A (Pino 5):** Controla o LED Verde.
  - **Botão B (Pino 6):** Controla o LED Azul.

- **Matriz de LEDs WS2812:**  
  O projeto pode receber dados via UART e exibir um número de 0 a 9 para simular o controle de uma matriz de LEDs.

## Requisitos:

- **Hardware:**
  - **RP2040 (Raspberry Pi Pico ou placa compatível)**
  - **2 Botões (A e B)**
  - **LED RGB (3 pinos para Red, Green, Blue)**
  - **Matriz de LEDs WS2812 (opcional, para simulação)**
  - **Cabo USB para conexão com o computador**

- **Software:**
  - **Pico SDK** (utilizado para a programação do RP2040)
  - **Ambiente de Desenvolvimento para RP2040** (como o Visual Studio Code com a extensão do Pico)

## Conexões de Hardware:

- **Botões:**
  - **Botão A:** Pino 5
  - **Botão B:** Pino 6
  - **Conexões dos botões:** Cada botão deve ser conectado entre o pino indicado e o GND, com um resistor pull-up habilitado no código.

- **LEDs RGB:**
  - **LED Vermelho:** Pino 11
  - **LED Verde:** Pino 12
  - **LED Azul:** Pino 13

- **Matriz de LEDs WS2812:**  
  O pino de controle da matriz (Pino 7) é utilizado para controlar a sequência de LEDs WS2812 (se desejado).

## Configuração e Uso:

1. **Configuração do ambiente de desenvolvimento:**
   - Certifique-se de ter o **Pico SDK** instalado e configurado no seu ambiente de desenvolvimento.
   - Se estiver utilizando o Visual Studio Code, instale a extensão do **Pico** para facilitar o desenvolvimento.

2. **Conecte os componentes de hardware:**
   - Conecte os LEDs RGB aos pinos 11, 12 e 13, conforme o código.
   - Conecte os botões aos pinos 5 e 6.
   - (Opcional) Conecte a matriz de LEDs WS2812 ao pino 7.

3. **Carregue o código no RP2040:**
   - Compile o código no seu ambiente de desenvolvimento e faça o upload para o RP2040 via USB.

4. **Teste os botões e LEDs:**
   - Pressione o **Botão A** para acender/desligar o LED verde.
   - Pressione o **Botão B** para acender/desligar o LED azul.
   - Observe a comunicação via UART no Serial Plotter.

5. **Verifique a UART:**
   - Utilize um software de terminal serial (como o **PuTTY** ou o **Tera Term**) para enviar números de 0 a 9 via UART.
   - O código irá simular a exibição desses números na matriz de LEDs (ou simplesmente imprimir no terminal).
  

  ##Link do wokwi: https://wokwi.com/projects/422468489507209217
  ##Link do vídeo: https://drive.google.com/file/d/1WdaTblJoqrvjNyMi5qUWMwgz4mAPNvMB/view?usp=sharing
