CMP = gcc
MAIN = fractalsmain
FUNC = fractalsfn
EXEC = $(MAIN)
FLAGS = -lm

$(EXEC): $(MAIN).o $(FUNC).o
	$(CMP) $(MAIN).o $(FUNC).o $(FLAGS) -o $(EXEC) -lX11

$(MAIN).o: $(MAIN).c $(FUNC).h
	$(CMP) -c $(MAIN).c

$(FUNC).o: $(FUNC).c
	$(CMP) -c $(FUNC).c

clean:
	rm *.o $(EXEC)
