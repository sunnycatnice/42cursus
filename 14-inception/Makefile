NAME = inception

all: start

host:
	@ echo "127.0.0.1 dmangola.42.fr" >> /etc/hosts

start: 
	@ docker-compose -f srcs/docker-compose.yml up --build

.PHONY: linux stop clean prune reload all