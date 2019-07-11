using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace test01
{
    class Program
    {
        //00:00:00.0015094 --->值类型
        //00:00:00.0106101 --->引用类型

        static void Main(string[] args)
        {
            Stopwatch sp = new Stopwatch();
            Test t = null;
            sp.Start();
            for (int i = 0; i < 999999; i++)
            {
                t = new Test();
            }
            sp.Stop();
            Console.WriteLine(sp.Elapsed);
            Console.ReadLine();

            
        }
    }
    public class Test 
    {
        
    }
}
