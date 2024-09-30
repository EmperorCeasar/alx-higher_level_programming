#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    if (!PyList_Check(p)) {
        printf("[.] Python list info\n");
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *item = PyList_GetItem(p, i);
        const char *type_name = Py_TYPE(item)->tp_name;
        printf("Element %zd: %s\n", i, type_name);

        if (PyBytes_Check(item)) {
            printf("[.] bytes object info\n");
            printf("  size: %zd\n", PyBytes_Size(item));
            printf("  trying string: %s\n", PyBytes_AsString(item));
            printf("  first %d bytes: ", (int)(PyBytes_Size(item) > 10 ? 10 : PyBytes_Size(item)));

            for (Py_ssize_t j = 0; j < (PyBytes_Size(item) > 10 ? 10 : PyBytes_Size(item)); j++) {
                printf("%02x", (unsigned char)PyBytes_AsString(item)[j]);
                if (j + 1 < (PyBytes_Size(item) > 10 ? 10 : PyBytes_Size(item))) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[.] bytes object info\n");
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    printf("[.] bytes object info\n");
    printf("  size: %zd\n", PyBytes_Size(p));
    printf("  trying string: %s\n", PyBytes_AsString(p));
    printf("  first %d bytes: ", (int)(PyBytes_Size(p) > 10 ? 10 : PyBytes_Size(p)));

    for (Py_ssize_t i = 0; i < (PyBytes_Size(p) > 10 ? 10 : PyBytes_Size(p)); i++) {
        printf("%02x", (unsigned char)PyBytes_AsString(p)[i]);
        if (i + 1 < (PyBytes_Size(p) > 10 ? 10 : PyBytes_Size(p))) {
            printf(" ");
        }
    }
    printf("\n");
}

void print_python_float(PyObject *p) {
    if (!PyFloat_Check(p)) {
        printf("[.] float object info\n");
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    double value = PyFloat_AsDouble(p);
    printf("[.] float object info\n");
    printf("  value: %f\n", value);
}

