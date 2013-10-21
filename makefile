# edit this makefile so that running make compiles your enigma program
CXX := clang++
CXX_FLAGS := -std=c++11 -stdlib=libc++ 

MODS = Main components mappingComponent machine

enigma: $(addsuffix .o, $(MODS))
	$(CXX) $(CXX_FLAGS) -o $@ $^

Main.o: Main.cpp machine.o components.o mappingComponent.o
	$(CXX) $(CXX_FLAGS) -c Main.cpp -o Main.o

machine.o: machine.cpp components.o mappingComponent.o
	$(CXX) $(CXX_FLAGS) -c machine.cpp -o machine.o

components.o: components.cpp mappingComponent.o
	$(CXX) $(CXX_FLAGS) -c components.cpp -o components.o

mappingComponent.o: mappingComponent.cpp
	$(CXX) $(CXX_FLAGS) -c mappingComponent.cpp -o mappingComponent.o

clean:
	rm -rf $(addsuffix .o, $(MODS)) enigma

.PHONY: clean