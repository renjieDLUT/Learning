#include"person.h"
#include </usr/include/python3.6m/Python.h> 

int fun(int x){
    Person person(01,"huangxuejuan", x);
    person.getId();
    person.getName();
    person.getAge();
    return 0;
}

PyObject* Wrappfun(PyObject* self, PyObject* args) 
{ 
    int x; 
    if (!PyArg_ParseTuple(args, "i", &x)) 
    { 
        return NULL; 
    } 
    return Py_BuildValue("i", fun(x)); 
    
} 

static PyMethodDef test_methods[] = { 
    {"fun", Wrappfun, METH_VARARGS, "something"},  {NULL}
}; 

extern "C"
void initfun1() 
{ 
    Py_InitModule("fun1", test_methods);    
}