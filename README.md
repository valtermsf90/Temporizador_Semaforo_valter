Projeto: Semáforo com Raspberry Pi Pico

Descrição

Este projeto implementa um semáforo utilizando o Raspberry Pi Pico. O sistema controla três LEDs representando as cores do semáforo (vermelho, amarelo e verde) e alterna entre eles a cada 3 segundos. A troca de estados é feita por meio de um timer repetitivo.

Hardware Utilizado

Raspberry Pi Pico

LED vermelho (conectado ao pino 13)

LED azul (conectado ao pino 12)

LED verde (conectado ao pino 11)

Resistores 330Ω

Protoboard e jumpers

Biblioteca Necessárias

Este projeto utiliza as bibliotecas da Raspberry Pi Pico:

pico/stdlib.h

hardware/timer.h

Funcionamento

O programa inicia com o LED vermelho ligado. A cada 3 segundos, o estado do semáforo muda seguindo a sequência:

Vermelho (PARE)

Amarelo (ATENÇÃO)

Verde (SIGA)

As mudanças de estado são controladas pela função semaforo(), que é chamada periodicamente pelo timer.

Instalação e Execução

Configure o ambiente de desenvolvimento para Raspberry Pi Pico (SDK do Pico e compilador C/C++).

Compile o código e transfira o arquivo .uf2 para o Raspberry Pi Pico.

Conecte o Pico a um monitor serial para visualizar as mensagens de depuração.

Exemplo de Saída no Terminal

PARE
Respeite a sinalização.
Respeite a sinalização.
Respeite a sinalização.
ATENÇÃO
Respeite a sinalização.
Respeite a sinalização.
Respeite a sinalização.
SIGA
Respeite a sinalização.
Respeite a sinalização.
Respeite a sinalização.

Links

Repositório no GitHub: Temporizador Semáforo

Simulação no Wokwi: Projeto Wokwi

Autor

Valter Machado Silva Filho

