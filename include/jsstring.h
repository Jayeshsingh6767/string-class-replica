#ifndef __JSSTRING__H
#define __JSSTRING__H
#include<iostream>
using namespace std;
class jsString
{
private:
char *ptr;
int size;
public:
jsString();
jsString(const char *ptr);
jsString & operator=(const jsString &other);
jsString & operator=(const char *ptr);
virtual ~jsString();
int operator<(const jsString &other);
int operator<=(const jsString &other);
int operator>(const jsString &other);
int operator>=(const jsString &other);
int operator==(const jsString &other);
int operator!=(const jsString &other);
void operator+=(const jsString &other);
void append(const jsString &other);
int Size();
jsString operator+(const jsString &other);
friend istream & operator>>(istream &is,jsString &jsString);
friend ostream & operator<<(ostream &out,jsString &jsString);
};
#endif