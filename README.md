# Small Campaign Example

In /harness you can find the persitent setup in order to fuzz
the toy software. The project includes another function which can
be fuzzed. Exercise is left to the reader

## Usage

```
# setup
make
make asan
screen -c screenrc

# minimize corpus for new run
./scripts/min.sh out/master/queue/ -- ./harness/harness

# analyse crash with asan
cat out/slave1/crashes/some_crash | ./harness/harness-asan
```

## Coverage Data

To generate coverage we added a new makefile rule to toyparser.
after compilation, you can run the binary with the inputs and then
generate a html file for visualisation.

```
COVFLAGS = -fprofile-arcs -ftest-coverage
cov: CFLAGS += $(COVFLAGS)
cov: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lgcov

```

Sample usage of using the corpus to get coverage

```
$ make clean 
$ rm -f main.o parser.o utils.o toyparser   *.gcda *.gcno *.gcov
$ make cov 
gcc -Wall -g -fprofile-arcs -ftest-coverage -c main.c
gcc -Wall -g -fprofile-arcs -ftest-coverage -c parser.c
gcc -Wall -g -fprofile-arcs -ftest-coverage -c utils.c
gcc -Wall -g -fprofile-arcs -ftest-coverage -o toyparser   main.o parser.o utils.o -lgcov
$ cd ..
$ ./scripts/cov.sh out/master/queue/*
$ open cov/cov/index.html

```


