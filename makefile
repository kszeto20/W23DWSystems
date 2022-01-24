all: client server

client: tcpclient.o tcping.o
	gcc -o client tcpclient.o tcping.o

server: tcpserver.o tcping.o
	gcc -o server tcpserver.o tcping.o

tcpclient.o: tcpclient.c tcping.h
	gcc -c tcpclient.c

tcpserver.o: tcpserver.c tcping.h
	gcc -c tcpserver.c

tcping.o: tcping.c tcping.h
	gcc -c tcping.c

clean:
	rm *.o
	rm *~
