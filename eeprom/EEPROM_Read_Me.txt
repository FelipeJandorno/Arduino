CONTEÚDOS IMPORTANTES

1   EEPROM do Arduino

Todos os microcontroladores AVR possuem entre 64 bytes e 4096 bytes de memória EEPROM, isto é, memória que armazena dados mesmo após desconectar a fonte de alimentação do arduino.

Quando lemos valores da EEPROM, o CPU é "parado" por 4 clock cycles. Já quando escrevemos uma informação, o CPU é "parado" por 2 clock cycles.

1.1	Registradores relacionados à EEPROM

EEAR (EEPROM Adress Registers) - São os registradores os quais armazenarão os endereços que os valores armazenados estarão.

EEDR (EEPROM Data Register) - Armazena os dados tanto para a leitura quanto para a escrita nos endereços informados pelo EEAR.

EECR (EEPROM Control Register) - Define o modo de operação que será executado, isto é, leitura ou escrita na memória. É importante ressaltar que a ação é iniciada quando passamos o valor do EEPE para o EECR.

EEMPE (EEPROM Master Write Enable) - É o bit que determina se o EEPE está em nível lógico alto ou baixo. Quando o EEMPE é acionado, se ele estiver em nível lógico baixo, dentro de 4 clock cycles o EEPE escreverá os dados armazenados em um dado registrador, cujo endereço de memória é EEAR, na EEPROM. É válido saber que após 4 clock cycles o hardware passa o nível lógico do EEMPE para zero automaticamente, o que cessará a comunicação.

EEPE (EEPROM Prgram Enable) - Bit que informa se a leitura está finalizada ou não. Deve-se executar o seguinte passo a passo para realizar a leitura da EEPROM:
a) Esperar até que EEPE vire 0
b) Passar o EEMPE para nível lógico alto e passar o EEPE para zero no EECR
c) Após a escrita ser feita, passar o EEPE para nível lógico alto

EERE (EEPROM Read Enable) - o bit EERE precisa ser alterado para 1 a fim de se realizar a leitura da memória. Antes de realizar a leitura, é necessário verificar se existe alguma operação ocorrendo. Para isso, utiliza-se a seguinte linha de código while(EECR |= (1 << EEPE));


2   Operadores de Atribuição

|= (Atribuição com OR binário)
&= (Atribuição com AND binário)
^= (Atribuição com XOR binário)

REFERÊNCIAS

[01] Address modes in AVRs. Site. Disponível em: <http://www.avr-asm-tutorial.net/avr_en/beginner/addressing/addressing_eeprom.html>

[02] Datasheet Atmega328p. Microship. Disponível em: <https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>


