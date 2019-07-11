using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test02
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[] { 1, 5, 2, 7, 9, 4, 10, 8, 3 };

            for (int i = 1; i < nums.Length; i++)
            {
                for (int j = 0; j < nums.Length-i; j++)
                {
                    if (nums[j] < nums[j + 1]) 
                    {
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                    }
                }
            }
            Console.ReadLine();
        }
    }
}
