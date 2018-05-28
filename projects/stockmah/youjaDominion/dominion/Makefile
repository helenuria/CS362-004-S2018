CFLAGS = -fpic -coverage -lm -g -std=c99
LINK = gcc -o $@ $^ $(CFLAGS)

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS)

rngs.o: rngs.h

dominion.o: dominion.h rngs.h

playdom.o: dominion.h

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
playdom: playdom.o dominion.o rngs.o
	$(LINK)

test-helpers.o: test-helpers.h dominion.h rngs.h

testSuiteDrawCard: testDrawCard.o dominion.o rngs.o
	$(LINK)

badTestDrawCard: badTestDrawCard.o dominion.o rngs.o
	$(LINK)

testBuyCard: testDrawCard.o dominion.o rngs.o
	$(LINK)

testAll: dominion.o testSuite.o
	$(LINK)

interface.o: interface.h

test-helpers.o: test-helpers.h test-helpers.c
	gcc -c -g test-helpers.c  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

rununittests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 
	./unittest1 &> unittestresults.out || true
	./unittest2 &>> unittestresults.out || true
	./unittest3 &>> unittestresults.out || true
	./unittest4 &>> unittestresults.out || true
	./cardtest1 &>> unittestresults.out || true
	./cardtest2 &>> unittestresults.out || true
	./cardtest3 &>> unittestresults.out || true
	./cardtest4 &>> unittestresults.out || true
	gcov dominion.c -fb >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

runrandomtestcard1: randomtestcard1
	./randomtestcard1 &> randomtestcard1.out || true
	gcov dominion.c -fb >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

runrandomtestcard2: randomtestcard2
	./randomtestcard2 &>> randomtestcard2.out || true
	gcov dominion.c -fb >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

runrandomtestadventurer: randomtestadventurer
	./randomtestadventurer &>> randomtestadventurer.out || true
	gcov dominion.c -fb >> randomtestadventurer.out
	cat dominion.c.gcov >> randomtestadventurer.out

randomtestcard1.o: dominion.h rngs.h

randomtestcard2.o: dominion.h rngs.h

randomtestadventurer.o: dominion.h rngs.h test-helpers.h

randomtestcard1: randomtestcard1.o dominion.o rngs.o
	$(LINK)

randomtestcard2: randomtestcard2.o dominion.o rngs.o
	$(LINK)

randomtestadventurer: randomtestadventurer.o dominion.o rngs.o test-helpers.o
	$(LINK)

player: player.o interface.o rngs.o dominion.o
	$(LINK)

all: playdom player 

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o test-helpers.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o test-helpers.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 randomtestcard1 randomtestcard2 runrandomtests cardtest1 cardtest2 cardtest3 cardtest4 randomtestadventurer
