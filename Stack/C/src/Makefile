stack_project: main.c clean_comp node_obj stack_obj menu_obj
	gcc main.c stack.o node.o menu.o -o stack_project
menu_obj: menu.c menu.h
	gcc menu.c -c
stack_obj: stack.c stack.h
	gcc stack.c -c
node_obj: node.c node.h
	gcc node.c -c
clean_comp:
	rm -f *.o
	rm -f stack_project