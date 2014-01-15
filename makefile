ProgramName = unix_signals_handeling_example
COMPILER = g++ -Wall

ALL : $(ProgramName).cxx  
	$(COMPILER) -o $(ProgramName).run $(ProgramName).cxx

clean :
	rm *".o" $(ProgramName).run
