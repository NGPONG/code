using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_01
{
    class Program
    {
        public static int v_Test = 0;
        static void Main(string[] args)
        {
            for (int i = 0; i < 5; i++)
            {
                Task.Run(FunTest);
            }

            Thread.Sleep(6000);

            Console.ReadLine();
        }

        static void FunTest()
        {
            int i = ++v_Test;
            Thread.Sleep(1000);
        }
    }
}
