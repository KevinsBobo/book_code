include ../Make.defines

PROGS =	cmd_client

all:	${PROGS}

cmd_client:	cmd_client.o
		${CC} ${CFLAGS} -o $@ cmd_client.o ${LIBS}


clean:
		rm -f ${PROGS} ${CLEANFILES}
