target1 [target2 ...]: [pre-req-1 pre-req-2 ...]
    [command1
     command2
     .......]
     
phony targets:
    a target that does not represent a file is called a phony target
    all, clean, install
    
$@: the target filename
$*: the target filename without the file extension
$<: the first prerequisite filename
$^: the filenames of all the prerequisites, separated by spaces, discard duplicates.
$+: similar to $^, but includes duplicates
$?: the names of all prerequisites that are newer than the garget, separated by spaces.

VPATH:  to specify the directory to search for dependencies and target files.
    VPATH = src include
    
vpath: to be more precise about the file type and its search directory
    vpath %.c src
    vpath %.h include
    
Pattern Rules:
    use pattern matching character % as the filename, can be applied to create a target, if there is no explicit rule
    %.o: %.c
        $(COMPILE.c) $(OUTPUT_OPTION) $<
    %:%.o
        $(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@






all: hello.exe

hello.exe: hello.o
    gcc -o $@ $<
    
hello.o: hello.c
    gcc -c $<
    
clean:
    rm hello.o hello.exe
    


     
     
