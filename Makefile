#------------------------------------------------------
# Autor: Gustavo Salgado
#------------------------------------------------------

CHAIN=arm-none-eabi
CFLAGS=-std=c99 -Wall
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/


# mude NOME_EXEC para mudar o nome do seu executável
NOME_EXEC = appGpio


all: app

app: start.o main.o 
	$(CHAIN)-ld $(OBJ)start.o $(OBJ)main.o -T $(SRC)memmap.ld -o $(OBJ)main.elf
	$(CHAIN)-objcopy $(OBJ)main.elf $(BIN)spl.boot -O binary
	cp $(BIN)spl.boot /srv/tftp/$(NOME_EXEC).bin
	echo 'setenv app "setenv autoload no;setenv ipaddr 10.8.3.2; setenv serverip 10.8.3.1; tftp 0x80000000 $(NOME_EXEC).bin;echo ***Booting to BareMetal ***;go 0x80000000"' > Comando.txt

start.o: $(SRC)start.s
	$(CHAIN)-as $(IPATH) $(SRC)start.s -o $(OBJ)start.o

main.o: $(SRC)main.c
	$(CHAIN)-gcc $(CFLAGS) $(IPATH) -c $(SRC)main.c -o $(OBJ)main.o
                                        
copy:
	cp $(BIN)spl.boot /srv/tftp/$(NOME_EXEC).bin

clean:
	rm -rf $(OBJ)*.o
	rm -rf $(OBJ)*.elf
	rm -rf $(BIN)*.boot

dump:
	$(CHAIN)-objdump -D $(OBJ)main.elf
