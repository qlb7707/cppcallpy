CC = g++
CFLAGS = -I../include
CFLAGS += -I/usr/include/python2.7
CFLAGS += -g -pipe -W -fPIC -std=c++11 -pthread
LDFLAGS = -L/usr/local/lib -lglog
OBJS = main.o util.o 
BIN = main
main:$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

#main.o:main.cpp util.o
#	$(CC) $(CFLAGS) -c $< -o $@
#
#util.o:util.cpp
#	$(CC) $(CFLAGS) -c $< -o $@
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BIN)
	rm -f ./*.o
