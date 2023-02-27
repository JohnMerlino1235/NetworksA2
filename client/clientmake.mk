CC = g++
CFLAGS = -g -Wall

client: mydriver.o mylink.o mytransport.o mysocket.o app_client.o
	$(CC) $(CFLAGS) mydriver.o mylink.o mytransport.o mysocket.o app_client.o -o client

mydriver.o: mydriver.cpp mydriver.h
	$(CC) $(CFLAGS) -c mydriver.cpp

mylink.o: mylink.cpp mylink.h
	$(CC) $(CFLAGS) -c mylink.cpp

mytransport.o: mytransport.cpp mytransport.h
	$(CC) $(CFLAGS) -c mytransport.cpp

mysocket.o: mysocket.cpp mysocket.h
	$(CC) $(CFLAGS) -c mysocket.cpp

app_client.o: app_client.cpp
	$(CC) $(CFLAGS) -c app_client.cpp

clean:
	rm *.o client
