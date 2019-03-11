#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ucr_dtw.h"


void print_array(double *arr, int len)
{
    int i;
    printf("[");
    for (i=0; i <= len; i++)
        printf("%f, ", arr[i]);
    
    printf("]\n");
}

// g++ is necessary, otherwise `sqrt` and `floor` aren't found
// Compile with g++ keogh_data_test.c ../src/ucr_dtw.c ../src/deque.c -I ../src -o keogh_data_test.o

// (
//     zeros(4),
//     Int32[3, 4, 1, 2],
//     [1.52128, -1.18322,  -0.507093, 0.169031],
//     [-1.18322, 0.2, -0.507093, -1.18322, -1.18322, 0.2, -0.507093, -1.18322],
//     [1.52128, 1.52128, 0.3, 1.52128, 1.52128, 1.52128, 0.3, 1.52128],
//     1,
//     3.875,
//     0.739509972887452,
//     [12.],
//     22.128,
//     [0., 0., 22.128, 0.]),
// (
//     zeros(4),
//     Int32[3, 4, 1, 2],
//     [1.5, -1.2, -0.507093, 0.169031],
//     [-1.18322, 0.2, -0.507093, -1.18322, 1., 0.2, -0.507093, -1.18322],
//     [1.52128, 1.52128, 1.52128, 1.2, 1.52128, 1.52128, 1.52128, 1.2],
//     1,
//     0.,
//     1.,
//     [.1],
//     4.93,
//     [0., 0., 0.09, 4.84])
// ]

// test_keogh_data(cb, order, ordered_query, 
//                 lb, ub, s_bound_off,
//                 run_mean, run_std, bsf, exp_lb, exp_cb)


int main()
{
    int order_1[] = {3, 4, 1, 2};
    double qo_1[] = {1.52128, -1.18322, -0.507093, 0.169031};
    double cb_1[] = {0., 0., 0., 0.};
    double l_1[] = {-1.18322, 0.2, -0.507093, -1.18322, -1.18322, 0.2, -0.507093, -1.18322};
    double u_1[] = {1.52128, 1.52128, 0.3, 1.52128, 1.52128, 1.52128, 0.3, 1.52128};


    double lb_keogh_1 = lower_bound_keogh_data(order_1, qo_1, cb_1,
                                               l_1, u_1, 4, 3.875, 0.739509972887452, 12.);
    printf("lb_keogh: %f\n", lb_keogh_1);
    print_array(cb_1, 4);

    int order_2[] = {3, 4, 1, 2};
    double qo_2[] = {1.5, -1.2, -0.507093, 0.169031};
    double cb_2[] = {0., 0., 0., 0.};
    double l_2[] = {-1.18322, 0.2, -0.507093, -1.18322, 1., 0.2, -0.507093, -1.18322};
    double u_2[] = {1.52128, 1.52128, 1.52128, 1.2, 1.52128, 1.52128, 1.52128, 1.2};
    double lb_keogh_2 = lower_bound_keogh_data(order_2, qo_2, cb_2,
                                               l_2, u_2, 4, 0., 1., 0.1);

    printf("lb_keogh: %f\n", lb_keogh_2);
    print_array(cb_2, 4);

    int order_3[] = {3, 4, 1, 2};
    double qo_3[] = {1.5, -1.2, -0.507093, 0.169031};
    double cb_3[] = {0., 0., 0., 0.};
    double l_3[] = {-1.18322, 0.2, -0.507093, -1.18322, 1., 0.2, -0.507093, -1.18322};
    double u_3[] = {1.52128, 1.52128, 1.52128, 1.2, 1.52128, 1.52128, 1.52128, 1.2};
    double lb_keogh_3 = lower_bound_keogh_data(order_3, qo_3, cb_3,
                                               l_3, u_3, 4, 0., 1., 100);

    printf("lb_keogh: %f\n", lb_keogh_3);
    print_array(cb_3, 4);

    return 0;
}
