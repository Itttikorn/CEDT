import numpy as np
def calculate():
    a = np.matmul(np.transpose(np.array([[1,3,-2],
                            [4,5,6],
                            [0,3,4]])),np.array([[1],
                                                [2],
                                                [3]]))

    b = np.matmul(np.array([[1,3],
                [4,5],
                [0,3]]), np.array([[1,3,-2],
                                [4,5,-1]])) 

    print(np.sum(a)+np.sum(np.diagonal(b)))
calculate()