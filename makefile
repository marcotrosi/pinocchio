.SILENT:
.PHONY: dir bin clean tst demo

all: demo

dir:
	mkdir -p build

demo: dir
	gcc -Wall src/pinocchio.c tst/demo.c -I src -o ./build/demo && ./build/demo

cln:
	rm -rf build 

