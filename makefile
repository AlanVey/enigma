# edit this makefile so that running make compiles your enigma program
CXX := clang++
CXX_FLAGS := -std=c++11 -stdlib=libc++ 

MODS = Main utilities

enigma: $(addsuffix .o, $(MODS))
	$(CXX) $(CXX_FLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(addsuffix .o, $(MODS)) enigma

.PHONY: clean