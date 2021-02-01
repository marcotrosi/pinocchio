.SILENT:
.PHONY: dir bin clean tst demo edit

all: demo

dir:
	mkdir -p build

demo: dir
	gcc -g -Wall src/pinocchio.c tst/demo.c -I src -o ./build/demo && ./build/demo
	# gcc -g -Wall src/pinocchio.c tst/demo.c -I src -o ./build/demo && lldb ./build/demo

cln:
	rm -rf build 

edit:
	/Applications/MacVim.app/Contents/bin/mvim src/* tst/* &
