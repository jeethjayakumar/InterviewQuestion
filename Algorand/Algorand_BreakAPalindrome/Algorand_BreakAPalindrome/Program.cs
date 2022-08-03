using System;

namespace Algorand_BreakAPalindrome // Note: actual namespace depends on the project name.
{
    internal class Program
    {
        public static string breakPalindrome(string palindromeStr)
        {
            string output = "IMPOSSIBLE";
            if ((!string.IsNullOrEmpty(palindromeStr)) && (palindromeStr.Length > 1))
            {
                char[] inpTmp = palindromeStr.ToCharArray();
                var inpLen = palindromeStr.Length;
                for (var i = 0; i < inpLen/2; i++)
                {
                    if (inpTmp[i] != 'a')
                    {
                        inpTmp[i] = 'a';
                        output = String.Join("", inpTmp);
                        return output;
                    }
                }
            }
            return output;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Input: bab");
            Console.WriteLine("Output: " + breakPalindrome("bab"));
            Console.WriteLine("Input: aaa");
            Console.WriteLine("Output: " + breakPalindrome("aaa"));
            Console.WriteLine("Input: acca");
            Console.WriteLine("Output: " + breakPalindrome("acca"));
        }
    }
}

