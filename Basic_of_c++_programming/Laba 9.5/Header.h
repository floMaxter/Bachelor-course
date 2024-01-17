#pragma once

struct polynomial
{
	int deg;
	float* mas;
};

int getUserIput(struct polynomial* pol, int* deg);
int enter_the_array(struct polynomial* f, int len);
void init(struct polynomial* w, int n);
void destroy(struct polynomial* w);
int maxy(int a, int b);
struct polynomial sub(struct polynomial* w1, struct polynomial* w2);
struct polynomial sum(struct polynomial* w1, struct polynomial* w2);
int miny(int a, int b);
struct polynomial divide_remainder(struct polynomial* w1, struct polynomial* w2);
struct polynomial divide_partial_quotient(struct polynomial* w1, struct polynomial* w2);
struct polynomial multiplication(struct polynomial* w1, struct polynomial* w2);
void print(struct polynomial* fad, int len);
