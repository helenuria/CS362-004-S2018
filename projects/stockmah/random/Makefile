CFLAGS := -Wall -Wextra -Werror -g -std=c99 -O3

run: testme
	./testme ; [ $$? = 200 ]

testme: testme.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f testme
