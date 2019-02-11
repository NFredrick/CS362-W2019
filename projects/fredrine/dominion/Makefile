CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe *.exe *gcov

unittestresults: dominion.o unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o cardtest4.o
	gcc -o unittest1.exe dominion.o unittest1.o rngs.o $(CFLAGS) -coverage
	gcc -o unittest2.exe dominion.o unittest2.o rngs.o $(CFLAGS) -coverage
	gcc -o unittest3.exe dominion.o unittest3.o rngs.o $(CFLAGS) -coverage
	gcc -o unittest4.exe dominion.o unittest4.o rngs.o $(CFLAGS) -coverage
	gcc -o cardtest1.exe dominion.o cardtest1.o rngs.o $(CFLAGS) -coverage
	gcc -o cardtest2.exe dominion.o cardtest2.o rngs.o $(CFLAGS) -coverage
	gcc -o cardtest3.exe dominion.o cardtest3.o rngs.o $(CFLAGS) -coverage
	gcc -o cardtest4.exe dominion.o cardtest4.o rngs.o $(CFLAGS) -coverage
	unittest1.exe > unittestresults.out
	unittest2.exe >> unittestresults.out
	unittest3.exe >> unittestresults.out
	unittest4.exe >> unittestresults.out
	cardtest1.exe >> unittestresults.out
	cardtest2.exe >> unittestresults.out
	cardtest3.exe >> unittestresults.out
	cardtest4.exe >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out
