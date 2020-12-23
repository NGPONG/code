using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int n = 0;
            for (int i = 0; i < list.Count; i++)
            {
                n += list[i + 1];
            }
            Console.WriteLine(n);
            Console.ReadLine();
        }
    }
}
