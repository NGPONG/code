using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StringBuilder的效率
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = string.Empty;
            StringBuilder sb = new StringBuilder();
            Stopwatch sw = new Stopwatch();
            sw.Start();
            for (int i = 0; i <10000000 ; i++)
            {
                sb.Append(i);
            }
            sw.Stop();
            Console.WriteLine(sw.Elapsed);
            Console.ReadLine();
        }
    }
}
