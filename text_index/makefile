TARGET:= ../lib/libproject.so 
SRCS :=  text_index1.c
	
${TARGET}:${SRCS}

	gcc -fPIC -shared $^ -o $@
clean:
	rm -f ${TARGET}
