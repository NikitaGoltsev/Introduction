# Introduction

test for cpu
	pgcc file.c -pg -o file.out
	pgcc file.c -pg -ta=multicore -o file.out
	./file.out
	gprof file.out > text.txt

test for gpu
	pgcc file.c -acc -Minfo=accel -o file.out
	nvprof file.out
