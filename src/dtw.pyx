import cython
cimport numpy as np
import numpy as np

ctypedef np.float32_t float32
ctypedef np.float64_t float64
ctypedef np.uint32_t uint32
ctypedef np.uint64_t uint64
ctypedef np.int32_t int
ctypedef np.int64_t int64

cdef extern from "ucr_dtw.h":
    int ucr_query(float64* q, int m, float64 r, float64* buffer, int buflen, ucr_index* result);
    struct ucr_index:
        float64 value
        int64   index

@cython.boundscheck(False)
@cython.wraparound(False)
#@cython.nonecheck(False)
def query(float64[::1] data not None, float64[::1] query not None, float64 r):
    cdef Py_ssize_t n_data
    cdef Py_ssize_t n_query
    cdef ucr_index result
    cdef int return_code
    n_data = data.shape[0]
    n_query= query.shape[0]
    return_code = ucr_query(&query[0], n_query, r, &data[0], n_data, &result)
    if return_code != 0:
        result.index = -1
    return result


