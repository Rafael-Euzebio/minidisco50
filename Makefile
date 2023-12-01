CFLAGS = -g -I ./include -I ./ext
DIRS=obj bin

minidisco50: ./obj/main.o ./obj/playback.o ./obj/input.o ./obj/actions.o
	gcc $(CFLAGS) ./obj/main.o ./obj/playback.o ./obj/input.o ./obj/actions.o ./ext/miniaudio/include/miniaudio.h -o minidisco50 -lpthread -lm -ldl -o ./bin/minidisco50

./obj/main.o: ./src/main.c
	gcc $(CFLAGS) -c ./src/main.c -o ./obj/main.o


./obj/playback.o: ./src/playback.c
	gcc $(CFLAGS) -c ./src/playback.c -o ./obj/playback.o

./obj/input.o: ./src/input.c
	gcc $(CFLAGS) -c ./src/input.c -o ./obj/input.o

./obj/actions.o: ./src/actions.c
	gcc $(CFLAGS) -c ./src/actions.c -o ./obj/actions.o

install: minidisco50
	mv -f ./bin/minidisco50 /usr/local/bin

clean:
	rm -rf ./obj/*.o ./bin/minidisco50

$(shell mkdir -p $(DIRS))
