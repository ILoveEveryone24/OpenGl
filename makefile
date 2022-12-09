##
#
#
# @file
# @version 0.1
openGlStart: openGlStart.cpp glad.o
	g++ -o openGlWindow openGlStart.cpp glad.o -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl

glad.o: glad.c
	g++ -c glad.c
# end
