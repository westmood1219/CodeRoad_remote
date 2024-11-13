#pragma once

#include <stdio.h>

float add(int x, float y);
float substract(int x, float y);
float multiply(float x, int y);
float divide(float x, int y);
int modulus(int a, int b);
float absolute(float x);

int MaxAddr(int *arr, int sz);

int month(int input);
int day(int input, int m);
int week(int input);