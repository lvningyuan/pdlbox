.PHONY:all
all:server client 

server:tcp_socket.hpp   tcp_server.hpp    dict_server.cc 
	g++ $^ -o  $@  -g -pthread -std=c++11

client:tcp_socket.hpp   tcp_client.hpp    dict_client.cc 
	g++ $^ -o  $@  -g -pthread -std=c++11

.PHONY:clean
clean:
	rm server client
