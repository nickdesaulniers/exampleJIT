jit:
		clang jit.c -o jit

mul:
		clang -c mul.c -o mul.o

clean:
		rm mul.o a.out jit
