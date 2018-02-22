simple: HWK.o main.o neat.o
	compile HWK.o main.o neat.o  -o Cars

HWK.o:  HWK.c Homework3.h
	compile -c HWK.c

main.o: main.c Homework3.h
	compile -c main.c

neat.o: neat.c Homework3.h
	compile -c neat.c

clean:
	rm *.o Cars
        

