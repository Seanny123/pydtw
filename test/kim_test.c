#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ucr_dtw.h"

// g++ is necessary, otherwise `sqrt` and `floor` aren't found
// Compile with g++ kim_test.c ../src/ucr_dtw.c ../src/deque.c -I ../src -o kim_test.o

int main()
{
    // TODO: make this actually match the Julia test
    double t[] = {5.0, 5.0, 4.0, 3.0, 3.5, 4.5, 2.5, -3, -2, 1, 3, 1, 0, 2.5, 1, 1.3, 0.7, 0.81,
                  5.0, 5.0, 4.0, 3.0, 3.5, 4.5, 2.5, -3, -2, 1, 3, 1, 0, 2.5, 1, 1.3, 0.7, 0.81};
    double q[] = {-0.740305, -0.345476, 0.444183, -0.345476, -1.52996, -1.92479, 0.246768, 1.03643, 0.641598, 0.444183, 0.839012, 1.23384};
    int m = 12;
    double lb = lower_bound_kim(t, q, 0, m, 1.875, 2.532, 0.0);
    printf("%f \n", lb);

    return 0;
}
