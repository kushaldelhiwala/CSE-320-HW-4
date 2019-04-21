progfib:
	gcc part_2/hw4_1.c part_2/defs.c -o hw4_progfib -lpthread -lm

progcnt:
	gcc part_2/hw4_2.c part_2/defs.c -o hw4_progcnt -lpthread

progqsort:
	gcc part_2/hw4_3.c part_2/defs.c -o hw4_progqsort -lpthread

prevhw:
	gcc part_3/hw4_part3.c part_3/defs.c -o hw4_prevhw -lpthread

museum_overseer:
	gcc part_4/hw4_part4.c part_4/defs.c -o hw4_museum -lpthread
