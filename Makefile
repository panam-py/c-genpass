CC=gcc
CFLAGS=-g -Wall -Wextra -Werror -pthread -Iinclude

TARGET=passgen

all: $(TARGET)

# $(TARGET): $(OBJ)
# 	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJ)

passgen: src/passgen.c src/main.c
	$(CC) $(CFLAGS) -o $(TARGET) src/passgen.c src/main.c

test: tests/test_passgen.c src/passgen.c
	$(CC) $(CFLAGS) -o test_passgen tests/test_passgen.c src/passgen.c

# benchmark: benchmarks/benchmark_passgen.c src/kvstore.c
# 	$(CC) $(CFLAGS) -o benchmark_kvstore benchmarks/benchmark_kvstore.c src/kvstore.c

clean:
	rm -f $(TARGET) test_passgen