output: main.o evaluation.o map.o miscellaneous.o movement.o placement.o command_line_ui.o
	gcc -o output main.o evaluation.o map.o miscellaneous.o movement.o placement.o command_line_ui.o
	
main.o: evaluation.h map.h miscellaneous.h movement.h placement.h command_line_ui.h structures.h
	gcc -c main.c

command_line_ui.o: command_line_ui.h structures.h
	gcc -c command_line_ui.c

map.o: map.h structures.h
	gcc -c map.c

miscellaneous.o: miscellaneous.h structures.h
	gcc -c miscellaneous.c

movement.o: movement.h structures.h
	gcc -c movement.c

placement.o: placement.h structures.h
	gcc -c placement.c

clean:
	rm *.o output

