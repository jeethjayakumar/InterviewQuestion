1. Given a bound of N, output all the numbers of form 2^i*5^j in increasing order and without duplicates.

2. Given a 2D array of size MxN, how many ways are there to go from (0,0) to (M-1, 0) given available moves from (x,y) are
   (x+1,y+(1,0,-1))
   
   (0,N-1)(1,N-1)(2,N-1)......(M-1,N-1)
   ....................................
   (0,0)(1,0)(2,0...............(M-1,0)

3.  Let's assume that each computational job at Google requires a constant number
    of CPUs for a given constant duration. Each scheduled job can thus be represented as follows:

      class Job:
         start_time_ms = 0
         duration_ms = 0
         cpus = 0

      def __init__(self, start_time_ms, duration_ms, cpus):
         self.start_time_ms = start_time_ms
         self.duration_ms = duration_ms
         self.cpus = cpus


   Google's data centers have a limited amount of CPUs. Therefore, we must ensure
   that scheduled jobs don't use more CPUs than what is available at any point in
   time. We'd like you to design an algorithm to verify if a given schedule is
   valid or not. Inputs of the problem are:

   a positive integer max_cpu that represents the total amount of available CPUs
   an array of jobs scheduled at a given time.

   Your solution should return false if the schedule exceeds the CPUs limit at
   some point in time; it returns true otherwise.

      def check_schedule(jobs, max_cpu):
