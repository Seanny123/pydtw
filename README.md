### pydtw
pydtw is a simple python wrapper of libdtw, which is a fast, dynamic time warping library based on the [UCR Suite](http://www.cs.ucr.edu/~eamonn/UCRsuite.html). 
It provides a single egg file which is easy to deploy

### Building

    python setup.py bdist_egg

### Usage

    import dtw
    r=0.05
    results=dtw.query(data, query, r)

* data  : numpy.array of data
* query : numpy.array of the pattern to be matched
* r     : size of warping window

* result : dict
* results[index] : the index of the first element in the best matching sequence in the data. 
* resulss[value] : the DTW distance between the query and the matching sequence in the data.
