
all: server.bin client.bin

server.bin: server.c
	gcc -o $@ $^

client.bin: client.c
	gcc -o $@ $^
