# Template para Projetos Baremetal na Beaglebone
Esta template de projeto está aqui para facilitar o desenvolvimento de software embarcado na Beaglebone Black em Baremetal na linguagem C.
Caso haja interesse em criar bibliotecas novas ou explorar as já existentes faça o seguinte:


## ***Como monto minhas libs aqui?***
* Coloque o arquivo .h de sua lib na pasta **inc/**
* Coloque o arquivo .c de sua lib na pasta **cfiles/**
* Para que o Makefile funcione corretamente, os arquivos .h e .c da sua lib devem ter o mesmo nome.
* Você não precisa modificar o Makefile para ele compilar a sua lib junto com o seu projeto. Apenas siga as regras listadas anteriormente.

## Funções Disponíveis
### UART0 
Esta é a UART ativa por padrão na Beaglebone, utilizada para aqueles que conectam o TTL nos "pinos independentes" da UART.
Aqui estou pressupondo que esta é a UART que você está usando para ver informações no seu monitor serial.

* void uart0_write(const char *str) - Imprime a string str na tela sem quebra de linha. 
* void uart0_writeln(const char *str) - Imprime a string str na tela com quebra de linha.
* char uart0_getch()                  - Recebe um char dado como input pelo usuário. 
* void uart0_getln(char* buffer)      - Recebe uma linha inteira dada como input pelo usuário.


### Timer
* begin_WMTIMER7(void) - Inicia o TIMER7 da Beaglebone (necessário para as funções abaixo funcionarem)
* _delay_us(unsigned int time) - Gera delay de ***time*** microssegundos
* _delay_ms(unsigned int time) - Gera delay de ***time*** milissegundos
* _delay_sec(unsigned int time) - Gera delay de ***time*** segundos

