
help:
	@echo -e 'Instructions:\n- Run "make" or "make help" to be returned with this prompt\n- Run "make lin" to compile the linux binary\n- Run "make clean" to clean up and only be left with source files'

lin: pluto.cpp
	g++ pluto.cpp -o pluto -lyaml-cpp

clean:
	rm pluto
