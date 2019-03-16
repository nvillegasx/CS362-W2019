# CFLAGS= -Wall -fpic -coverage -lm -std=c99

# rngs.o: rngs.h rngs.c
# 	gcc -c rngs.c -g  $(CFLAGS)

# dominion.o: dominion.h dominion.c rngs.o
# 	gcc -c dominion.c -g  $(CFLAGS)

# playdom: dominion.o playdom.c
# 	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
# #To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
# testDrawCard: testDrawCard.c dominion.o rngs.o
# 	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

# badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
# 	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

# testBuyCard: testDrawCard.c dominion.o rngs.o
# 	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

# testAll: dominion.o testSuite.c
# 	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

# interface.o: interface.h interface.c
# 	gcc -c interface.c -g  $(CFLAGS)

# runtests: testDrawCard 
# 	./testDrawCard &> unittestresult.out
# 	gcov dominion.c >> unittestresult.out
# 	cat dominion.c.gcov >> unittestresult.out


# player: player.c interface.o
# 	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

# all: playdom player 

# clean:
# 	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

# CFLAGS = -Wall -fpic -coverage -lm -std=c99

# default: tests.out

# tests.out: unittest1.c unittest2.c unittest3.c unittest4.c unittest5.c bst.c compare.c
	
# 	echo "Result for running BST tests:" > tests.out
# 	echo "unittest1.c:" >> tests.out
# 	gcc -o unittest1 compare.c bst.c unittest1.c $(CFLAGS)
# 	./unittest1 >> tests.out
# 	gcov bst.c >> tests.out
	
# 	echo "unittest2.c:" >> tests.out
# 	gcc -o unittest2 compare.c bst.c unittest2.c $(CFLAGS)
# 	./unittest2 >> tests.out
# 	gcov bst.c >> tests.out
	
# 	echo "unittest3.c:" >> tests.out
# 	gcc -o unittest3 compare.c bst.c unittest3.c $(CFLAGS)
# 	./unittest3 >> tests.out
# 	gcov bst.c >> tests.out
	
# 	echo "unittest4.c:" >> tests.out
# 	gcc -o unittest4 compare.c bst.c unittest4.c $(CFLAGS)
# 	./unittest4 >> tests.out
# 	gcov bst.c >> tests.out
	
# 	echo "unittest5.c:" >> tests.out
# 	gcc -o unittest5 compare.c bst.c unittest5.c $(CFLAGS)
# 	./unittest5 >> tests.out
# 	gcov bst.c >> tests.out

# clean:
# 	rm tests.out

# cleanall: 
# 	rm tests.out unittest1 unittest2 unittest3 unittest4 unittest5 *.gcda *.gcno *.gcov

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

# add remaining
unitTest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
unitTest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)
unitTest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
unitTest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
	
unitTests: unitTest1 unitTest2 unitTest3 unitTest4

#add remaining
unittestresults: playdom player unitTests 
# unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
	./unittest1 >> unittesttests.out
	gcov dominion.c >> unittesttests.out
	./unittest2 >> unittesttests.out
	gcov dominion.c >> unittesttests.out
	./unittest3 >> unittesttests.out
	gcov dominion.c >> unittesttests.out
	./unittest4 >> unittesttests.out
	gcov dominion.c >> unittesttests.out


randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomTests: randomtestcard1 randomtestcard2 randomtestadventurer

randomtestresults: playdom player randomTests
	./randomtestcard1 >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	./randomtestcard2 >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	./randomtestadventurer >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out

all: playdom player unitTests unittestresults randomTests randomtestresults


clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
# add remaining unit tests and card tests
cleanTests:
	rm -f unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
