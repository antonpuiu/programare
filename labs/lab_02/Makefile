EXE=hello

build: $(EXE)

$(EXE): main.c
	gcc $^ -o $@ -lm

clean:
	rm -f $(EXE)
