JC = javac
JR = java
OBJS = Person.class Actors.class Directors.class Movies.class menu.class main.class

myApp: joao
	$(JR) main

joao: $(OBJS)

Person.class: Person.java
	$(JC) Person.java

Actors.class: Actors.java
	$(JC) Actors.java

Directors.class: Directors.java
	$(JC) Directors.java

Movies.class: Movies.java
	$(JC) Movies.java

menu.class: menu.java
	$(JC) menu.java

main.class: main.java
	$(JC) main.java

clean:
	rm -rf *.class joao