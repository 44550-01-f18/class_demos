sequential: bitonic.c
	gcc $< -o $@

dumbthreaded: threaded_bitonic.c
	gcc $< -o $@ -lpthread

smarterthreaded: smarter_bitonic.c
	gcc $< -o $@ -lpthread
