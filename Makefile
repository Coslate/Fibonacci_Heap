
#declare variable
CC = g++
INCLUDE_FILES = ./include
INCLUDE_FLAGS = -I $(INCLUDE_FILES)
CFLAGS = -g -Wall -O3 
COMPILE_FLAGS = -c
MAIN_OBJECT_NAME_MAIN = Binomial_Heap_main
MAIN_OBJECT_SOURCE_MAIN = $(MAIN_OBJECT_NAME_MAIN).cpp
MAIN_OBJECT_EXEC_MAIN = $(MAIN_OBJECT_NAME_MAIN).o
MAIN_OBJECT_NAME = Binomial_Heap
MAIN_OBJECT_SOURCE = $(MAIN_OBJECT_NAME).cpp
MAIN_OBJECT_EXEC = $(MAIN_OBJECT_NAME).o
MAIN_OBJECT_EXEC_OUTPUT = ../exec_output/

all : clean Binomial_Heap all_file_tags
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC) $(MAIN_OBJECT_SOURCE_MAIN) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC_MAIN)
	${MAIN_OBJECT_EXEC_OUTPUT}$(MAIN_OBJECT_EXEC_MAIN)

Binomial_Heap : $(MAIN_OBJECT_SOURCE)
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) $(MAIN_OBJECT_SOURCE) $(INCLUDE_FLAGS) -o $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)

all_file_tags : 
	ctags -R ./*
	ctags -a $(INCLUDE_FILES)/*

clean :
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC)
	rm -rf $(MAIN_OBJECT_EXEC_OUTPUT)$(MAIN_OBJECT_EXEC_MAIN)
	rm -rf ./tags