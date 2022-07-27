1. The greatest common divisor (GCD), also called highest common factor (HCF) of N numbers is the largest positive integer that 
   divides all numbers without giving a remainder.
   Write an algorithm to determin the GCD of N positive integer.
   Input : num=5 , arr=[2,4,6,8,10] ; Output: 2

2. Given an array of the locations of N packing crates, implement an algorithm to find the locations of the M crates closest to
   the truck.

3. Amazon's AWS provides fast and efficient server solutions. The developers want to stress-test the quality of the servers' channels. They must enusre
   the following:
      a. Each of the packets must be sent via a single channel
      b. Each of the channels must transfer at least one packet
   The quality of the transfer for a channel is defined by the median of sizes of all the data packets sent through that channel.
   Note: The median of an array is the middle element if the array is sorted in non-decreasing order. If the number of elements in the array is even,
   the median is the average of the two middle elements.
   
   Find the maximum possible sum of the qualities of all channels. If the answer is a floating point value, round it to the next higher integer.
   Example: packets[] = {1,2,3,4,5}
   channel = 2
   output = 8
   Explantion = One maximal solution is to transfer packets {1,2,3,4} on channel 1 and {5} on channel 2
   Quality of channel 1 = 2.5
   Quality of channel 2 = 5
   Total Quality = 5 + 2.5 = 7.5 - rounding up to 8
   
4. Complete function findTotalPower(int power[n]) which accepts array of integers and returns the sum of power of all possible 
   contiguous groups of servers.
   Example: power[] = {2,1,3}
            output = 27
            Explanation: 
            power[0,0] = min([2]) * sum(2) = 2*2 = 4
            power[0,1] = min(2,1) * sum(2,1) = 1*3 = 3
            power[0,2] = min(2,1,3) * sum(2,1,3) = 1*6 = 6
            power[1,1] = min(1) * sum(1) = 1*1 = 1
            power[1,2] = min(1,3) * sum(1,3) = 1*4 = 4
            power[2,2] = min(3) * sum(3) = 3*3 = 9
            Overall sum = 4+3+6+1+4+9 = 27
