#include <Python.h>

static PyObject *py_stringToInteger(PyObject *self, PyObject *args){
    
    int i = 0;
    int val = 0;
    int digit = 0;
    char c;
    char *string;

    PyArg_ParseTuple(args, "s", &string);

    for (i=0;i<sizeof(string);i++){
        c = string[i];
        if (c >= '0' && c <= '9'){
            digit = (int) (c - '0');
        } else {
            continue;
        }
        val = (val*10) + digit;
    }
    return PyLong_FromLong(val);
}

static PyMethodDef libAtoiModule_methods[] = {
    {"stringToInteger", py_stringToInteger, METH_VARARGS},
    {NULL, NULL}
};

static PyModuleDef atoiModule = {
    {},
    "libAtoiModule",
    0,
    0,
    libAtoiModule_methods,
    0,
    0,
    0,
    0
};


PyObject *PyInit_libAtoiModule(){
    return PyModule_Create(&atoiModule);
}

int main(int argc, char *argv[]){
    PyImport_AppendInittab("libAtoiModule", PyInit_libAtoiModule);
    Py_Initialize();
    return 0;
}
