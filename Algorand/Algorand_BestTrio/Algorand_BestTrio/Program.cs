using System;

namespace Algorand_BestTrio
{
    internal class Program
    {
        public static int bestTrio(int friendNodes, List<int> friendsFrom, List<int> friendsTo)
        {
            Console.WriteLine("Inside bestTrio - Current friendNodes = {0}", friendNodes );
            if (friendNodes < 1 && friendNodes > 500)
                return -1;

            var friendsDegree = new int[friendNodes + 1];
            var friendsMatrix = new bool[friendNodes + 1, friendNodes+1];
            var output = 99999;
            for (int i = 0; i < friendsFrom.Count; i++)
            {
                friendsDegree[friendsFrom[i]] ++;
                friendsDegree[friendsTo[i]] ++;
                friendsMatrix[Math.Min(friendsFrom[i], friendsTo[i]), Math.Max(friendsFrom[i], friendsTo[i])] = true;
            }

            for (int i = 1; i <= friendNodes; i++)
            {
                if (friendsDegree[i] < 2)
                    continue;
                for (int j = i+1; j <= friendNodes; j++)
                {
                    if (friendsDegree[j] < 2 || !friendsMatrix[i, j])
                        continue;
                    for (int k = j+1; k <= friendNodes; k++)
                    {
                        if (friendsDegree[k] < 2)
                            continue;
                        if (friendsMatrix[j,k] && friendsMatrix[i,k])
                        {
                            output = Math.Min(output, friendsDegree[i]+friendsDegree[j]+friendsDegree[k]-6);
                        }
                    }
                }
            }

            return (output == 99999)? -1 : output;
        }

        static void displayInputOutput(List<int> friendsFrom, List<int> friendsTo, int output)
        {
            Console.Write("FriendsFrom: ");
            foreach(var friend in friendsFrom)
                Console.Write("{0} ", friend);
            Console.Write("\nFriendsTo: ");
            foreach(var friend in friendsTo)
                Console.Write("{0} ", friend);
            Console.WriteLine("\nfriendsFrom.Count() = {0}", friendsFrom.Count);
            Console.WriteLine("\nOutput: {0}",output);
        }

        static void Main(string[] args)
        {
            List<int> friendsFrom = new List<int>();
            List<int> friendsTo = new List<int>();
            int output;

            friendsFrom.Add(1);
            friendsFrom.Add(1);
            friendsFrom.Add(2);
            friendsFrom.Add(2);
            friendsFrom.Add(3);
            friendsFrom.Add(4);
            friendsTo.Add(2);
            friendsTo.Add(3);
            friendsTo.Add(3);
            friendsTo.Add(4);
            friendsTo.Add(4);
            friendsTo.Add(5);
            output = bestTrio(5, friendsFrom, friendsTo);
            displayInputOutput(friendsFrom, friendsTo, output);

            friendsFrom.Clear();
            friendsTo.Clear();
            friendsFrom.Add(2);
            friendsFrom.Add(3);
            friendsFrom.Add(5);
            friendsFrom.Add(1);
            friendsTo.Add(1);
            friendsTo.Add(6);
            friendsTo.Add(1);
            friendsTo.Add(7);
            output = bestTrio(7, friendsFrom, friendsTo);
            displayInputOutput(friendsFrom, friendsTo, output);

            Console.WriteLine("Hello World!");
        }
    }
}