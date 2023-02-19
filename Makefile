format:
	clang-format -i *.c

run_cpu_dbl:

	export PGI_ACC_TIME=1
	pgcc maindbl.c -pg -o file.out
	./file.out
	gprof file.out
	time ./file.out

	export PGI_ACC_TIME = 1
	pgcc maindbl.c -pg -ta=multicore -o file.out
	./file.out
	gprof file.out
	time ./file.out

run_cpu_flt:

	export PGI_ACC_TIME = 1
	pgcc maindflt.c -pg -o file.out
	./file.out
	gprof file.out
	time ./file.out

	export PGI_ACC_TIME = 1
	pgcc maindflt.c -pg -ta=multicore -o file.out
	./file.out
	gprof file.out
	time ./file.out

run_gpu_dbl:

	export PGI_ACC_TIME = 1
	pgcc prg_dbl_main.c -acc -Minfo=accel -o file.out
	nvprof file.out
	time ./file.out

run_gpu_flt:
	export PGI_ACC_TIME = 1
	pgcc prg_flt_mainf.c -acc -Minfo=accel -o file.out
	nvprof file.out
	time ./file.out
