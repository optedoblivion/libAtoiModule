#include <Python.h>

/*
 * Function to convert a string to integer
 * This function will be called by a python app
 */
static PyObject *py_stringToInteger(PyObject *self, PyObject *args){
    
    // Setup vars
    int i = 0;
    int val = 0;
    int digit = 0;
    char c;
    char *string;

    // Parse function args
    PyArg_ParseTuple(args, "s", &string);

    // Do work for conversion
    for (i=0;i<sizeof(string);i++){
        c = string[i];
        if (c >= '0' && c <= '9'){
            digit = (int) (c - '0');
        } else {
            continue;
        }
        val = (val*10) + digit;
    }
    
    // Return back to python
    return PyLong_FromLong(val);
}

/*
 * Define method dict for the module definition
 */ 
static PyMethodDef libAtoiModule_methods[] = {
    {"stringToInteger", py_stringToInteger, METH_VARARGS},
    {NULL, NULL}
};

/*
 * Define the module
 */
static PyModuleDef libAtoiModule = {
    {},
    "libAtoiModule", // name
    0,
    0,
    libAtoiModule_methods, //methods
    0,
    0,
    0,
    0
};

/*
 * Needed PyInit function for loading the module
 */
PyObject *PyInit_libAtoiModule(){
    return PyModule_Create(&libAtoiModule);
}

/*
 * C main function
 */
int main(int argc, char *argv[]){
    PyImport_AppendInittab("libAtoiModule", PyInit_libAtoiModule);
    Py_Initialize();
    return 0;
}
