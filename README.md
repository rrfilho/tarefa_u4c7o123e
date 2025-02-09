# tarefa_u4c7o123e
Repositório da tarefa 7 (unidade 4, capítulo 7) do curso de capacitação em sistemas embarcados - embarcatech

Este projeto tem por objetivo apresentar os conceitos de PWM (Pulse Width Modulation), utilizando um LED (kit de desenvolvimento BitDogLab) e um servomotor (simulação).
Este código-fonte funciona tanto no ambiente simulado (Wokwi) como na no kit de desenvolvimento sem a necessidade de alteações: os dispositivos utilizam portas diferentes, logo ambas são configuradas ao mesmo tempo.

### pwm.h
Módulo responsável por configurar as portas da placa RaspberryPi Pico W como saída PWM. São inicializados as portas 12 (LED azul) e 22 (servomotor) como PWM com 50Hz de frequência (20ms). 
Para obter a frequência de 50Hz, foi mantida a frequência da placa em 125MHz, com divisor de frequência igual a 100.0 (sem parte fracional) e wrap de 25000.

A função pwmx_set_duty_cycle(float duty_cycle) recebe o duty cycle desejado e o PWM é alterado simultanemanete para o LED e o servomotor.

### main.c
Executa as operações inicias solicitadas na tarefa, configurando o duty cycle para 12,0% (180°), 7,35% (90°) e 2,5% (0°). 
Na sequência é realizado o movimento periódico, indo de 0° à 180 e retornando para 0°. Conforme a tarefa o incremento/decremento do duty cycle é de 2us que equivale a 0.025%.

