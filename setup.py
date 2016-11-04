#from distutils.core import setup
#from distutils.extension import Extension
#from Cython.Build import cythonize
from setuptools import setup
from setuptools.extension import Extension

import numpy
import os

ext_modules=[
    Extension("dtw",
              sources=["src/dtw.c", "src/ucr_dtw.c", "src/deque.c"],
              #sources=["dtw.pyx", "ucr_dtw.c", "deque.c"],
              include_dirs=[numpy.get_include()],
              extra_compile_args=['-O2', '-Wall', '-fPIC', '-pedantic', '-Wextra'],
              libraries=["m"]
    ),
]

setup(
  name = "dtw",
  #ext_modules = cythonize(ext_modules)
  ext_modules = ext_modules
)

