.SILENT:
.PHONY: dir bin cln tst demo edit doc dbg

NOCOLOR?=false

ifeq (${NOCOLOR},true)
DEVNULL=> /dev/null
endif

all: demo

dir:
	mkdir -p bld doc

demo: dir
	gcc -Wall src/pinocchio.c tst/demo.c -Isrc -o ./bld/demo && ./bld/demo

tst: dir
	gcc -Wall -DNOCOLOR=${NOCOLOR} src/pinocchio.c tst/test.c tst/equal.c tst/test_pinocchio.c -Isrc -Itst -o ./bld/test && ./bld/test ${DEVNULL}

tstloop:
	gcc -Wall -DNOCOLOR=${NOCOLOR} src/pinocchio.c tst/test.c tst/equal.c tst/test_pinocchio.c -Isrc -Itst -o ./bld/test
	while true; do clear; ./bld/test; sleep 5; done

dbg:
	gcc -g -Wall src/pinocchio.c tst/test.c tst/equal.c tst/test_pinocchio.c -Isrc -Itst -o ./bld/test && lldb ./bld/test

cln:
	rm -rf bld doc

doc: dir
	echo "generating manpage"   ; pandoc README.md -s -f gfm -t man   -o doc/pinocchio.3
	echo "generating PDF"       ; pandoc README.md -s -f gfm -t pdf   -o doc/pinocchio.pdf
	echo "generating HTML"      ; pandoc README.md -s -f gfm -t html  -o doc/pinocchio.html --metadata title="Pinocchio"
	echo "generating Vim help"  ; pandoc README.md -f gfm -t etc/vimhelp.lua -o doc/pinocchio.txt

edit:
	# ${EDITOR} src/* tst/* &
	/Applications/MacVim.app/Contents/bin/mvim src/* tst/* &

