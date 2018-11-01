from setuptools import setup
from setuptools.extension import Extension

import numpy

ext_modules = [
    Extension("dtw",
              sources=["src/dtw.c", "src/ucr_dtw.c", "src/deque.c"],
              include_dirs=[numpy.get_include()],
              extra_compile_args=['-O2', '-Wall', '-fPIC', '-pedantic', '-Wextra'],
              libraries=["m"]
              ),
]

setup(
    name="dtw",
    install_requires=['numpy'],
    ext_modules=ext_modules
)
