SHELL := /bin/zsh

Gomoku: main.cpp Makefile
	time g++ -Wextra main.cpp -o Gomoku
