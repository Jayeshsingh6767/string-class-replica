#include<jsString.h>
#include<stringutils.h>
#include<iostream>
using namespace std;
using namespace stringutils;
jsString::jsString()
{
this->ptr=NULL;
this->size=0;
}
jsString::jsString(const char *ptr)
{
this->ptr=NULL;
if(ptr==NULL)return;
this->size=stringLength(ptr);
this->ptr=new char(this->size+1);
stringCopy(this->ptr,ptr);
}
jsString & jsString::operator=(const jsString &other)
{
if(this->ptr)delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(other.ptr==NULL)return *this;
this->size=stringLength(other.ptr);
this->ptr=new char(this->size+1);
stringCopy(this->ptr,other.ptr);
return *this;
}
jsString & jsString::operator=(const char *ptr)
{
if(this->ptr)delete [] this->ptr;
this->ptr=NULL;
this->size=0;
if(ptr==NULL)return *this;
this->size=stringLength(ptr);
this->ptr=new char(this->size+1);
stringCopy(this->ptr,ptr);
return *this;
}
jsString::~jsString()
{
if(this->ptr)delete [] this->ptr;
}

int jsString::operator<(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 0;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 0;
return stringCompare(this->ptr,other.ptr)<0;
}
int jsString::operator<=(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 1;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 0;
return stringCompare(this->ptr,other.ptr)<=0;
}
int jsString::operator>(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 0;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 1;
return stringCompare(this->ptr,other.ptr)>0;
}
int jsString::operator>=(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 1;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 1;
return stringCompare(this->ptr,other.ptr)>=0;
}

int jsString::operator==(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 1;
if(this->ptr==NULL)return 0;
if(other.ptr==NULL)return 0;
return stringCompare(this->ptr,other.ptr)==0;
}
int jsString::operator!=(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return 0;
if(this->ptr==NULL)return 1;
if(other.ptr==NULL)return 1;
return stringCompare(this->ptr,other.ptr)!=0;
}
void jsString::operator+=(const jsString &other)
{
if(this->ptr==NULL && other.ptr==NULL)return;
if(other.ptr==NULL)return;
if(this->ptr==NULL)
{
(*this)=other;
return;
}
char *tmp=new char[this->size+other.size+1];
stringCopy(tmp,this->ptr);
stringConcatenate(tmp,other.ptr);
delete [] this->ptr;
this->ptr=tmp;
this->size=this->size+other.size;
}
void jsString::append(const jsString &other)
{
*this+=other;
}

jsString jsString::operator+(const jsString &other)
{
jsString k;
if(this->ptr==NULL && other.ptr==NULL)return k;
if(this->ptr==NULL)k=other;
else if(other.ptr==NULL)k=(*this);
else
{
k=(*this);
k+=other;
}
return k;
}
int jsString::Size()
{
return this->size;
}
istream & operator>>(istream &is,jsString &jsString)
{
char *c=new char[1000];
is>>c;
jsString=c;
delete[] c;
return is;
}

ostream & operator<<(ostream & out,jsString &jsString)
{
if(jsString.ptr==NULL)return out;
out<<jsString.ptr;
return out;
}