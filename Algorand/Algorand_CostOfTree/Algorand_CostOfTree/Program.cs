using System;

namespace Algorand_CostOfTree
{
    internal class Program
    {
        public static int calculateCost(List<int> arr)
        {
            if (arr.Count < 2 || arr.Count > 50)
                return 0;

            int output = 0;

            while(arr.Count > 1)
            {
                var idx = arr.IndexOf(arr.Min());
                if ((idx > 0) && (idx < (arr.Count - 1)))
                {
                    output += arr[idx] * Math.Min(arr[idx - 1], arr[idx + 1]);
                }
                else if(idx == 0)
                {
                    output += arr[idx] * arr[idx + 1];
                }
                else
                {
                    output += arr[idx] * arr[idx - 1];
                }
                arr.RemoveAt(idx);
            }
            return output;
        }

        public static void displayInputOutput(List<int> arr, int output)
        {
            Console.Write("Input: ");
            foreach(var num in arr)
                Console.Write("{0} ", num);
            Console.WriteLine("\nOutput: {0}", output);
        }

        static void Main(string[] args)
        {
            List<int> inputArr = new List<int>();
            inputArr.Add(2);
            inputArr.Add(1);
            displayInputOutput(inputArr, calculateCost(inputArr));
            inputArr.Clear();
            inputArr.Add(5);
            inputArr.Add(3);
            inputArr.Add(1);
            displayInputOutput(inputArr, calculateCost(inputArr));
            inputArr.Clear();
            inputArr.Add(1);
            inputArr.Add(5);
            inputArr.Add(3);
            displayInputOutput(inputArr, calculateCost(inputArr));
            inputArr.Clear();
        }
    }
}