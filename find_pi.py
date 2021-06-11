from mpi4py import MPI
from numpy import arange
from math import sqrt

comm = MPI.COMM_WORLD
my_pe_num = comm.get_ran()

intervals = 0
if my_pe_num == 0:
  intervals = int(input("How many intervals? "))

intervals = comm.bcast(intervals, root=0)
mypi = 0
h = 2/intervals
start = (my_pe_num *2 / comm.Get_size()) -1
end = ((my_pe_num+1) *2 / comm.Get_size())-1

for x in arange(start,end,h):
  mypi = mypi + h*2*sqrt(1-x*x)

pi = comm.reduce(mypi, op = MPI.SUM, root=0)

if my_pe_num = 0:
  print("pi is about %f" % pi)
  print("Error is %f" % (pi-3.14159265358979323846)
       
   

       
