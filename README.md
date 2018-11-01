### pydtw
`pydtw` is a simple python wrapper of `libdtw`, which is a fast, dynamic time warping library based on the [UCR Suite](http://www.cs.ucr.edu/~eamonn/UCRsuite.html). 

Works for Python 3, but not for Windows, because I don't understand the Windows C compiler.


### Install

```bash
pip install -e .
```

### Usage

```python
import numpy as np
import dtw


data = np.cumsum(np.random.uniform(-0.5, 0.5, 1000000))
query = np.cumsum(np.random.uniform(-0.5, 0.5, 100))
results = dtw.query(data, query, r=0.05)
```

* input
  * `data`  : numpy.array of data
  * `query` : numpy.array of the pattern to be matched
  * `r`     : size of warping window
* result : `dict`
  * `results["index"]` : the index of the first element in the best matching sequence in the data. 
  * `results["value"]` : the DTW distance between the query and the matching sequence in the data.

