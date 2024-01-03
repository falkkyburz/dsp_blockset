all: clean run

dsp_blockset_test: dsp_blockset_test.c
	gcc -Wall -mwin32 -o $@ $^

run: dsp_blockset_test
	./$^

clean:
	rm -f dsp_blockset_test.exe
