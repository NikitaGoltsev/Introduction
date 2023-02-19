format:
	clang-format -i *.c

run_cpu_dbl:
	
	pgcc maindbl.c -pg -o file.out
	./file.out
	gprof file.out

	pgcc maindbl.c -pg -ta=multicore -o file.out
	./file.out
	gprof file.out

run_gpu:
