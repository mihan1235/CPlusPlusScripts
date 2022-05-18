all:
 g++ example-0.cpp -o example-0 -g -Wall `pkg-config gtk+-3.0 --cflags --libs`
