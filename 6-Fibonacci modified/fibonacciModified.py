from decimal import Decimal, getcontext     # 7/10 tests
def fibonacciModified(t1, t2, n):   
    getcontext().prec = 10000  
    
    t1 = Decimal(t1)
    t2 = Decimal(t2)
    
    for _ in range(3, n + 1):
        tn = t1 + t2 * t2
        t1, t2 = t2, tn

    return tn
    
    
import sys                                  # 10/10 tests
sys.set_int_max_str_digits(0)
def fibonacciModified(t1, t2, n):
    sys.int_max_str_digits = 0
    for x in range(n-2):
        tn=t1+t2**2
        t1=t2
        t2=tn
    return tn