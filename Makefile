all: mpu-test

clean:
	rm -f mpu-test
	rm -rf obj/*
	rm -rf src/.*.swp

obj/:
	mkdir -p obj

obj/%.o: src/%.cpp obj/
	g++ -g -isystem src -std=c++14 -pthread -c -o $@ $<

mpu-test: obj/main.o obj/MPU9250Multi.o
	g++ -g -pthread $^ -o $@
