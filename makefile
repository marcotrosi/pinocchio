.SILENT:
.PHONY: bin tst demo

demo:
	gcc -Wall src/pinocchio.c tst/demo.c -I src -o demo && ./demo
	# gcc -Wall -E src/pinocchio.c -I src -o pino.p
	# gcc -Wall -E tst/demo.c -I src -o demo.p
