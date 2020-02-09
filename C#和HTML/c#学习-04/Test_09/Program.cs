using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_09
{
    public class Person
    {


    }
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 32; i++)
            {
                Thread thread = new Thread(Fun_test);
                thread.IsBackground = true;
                thread.Start();
            }

            Console.ReadLine();
        }

        static void Fun_test() {

            long i = 10;
            Random rd = new Random();
            while (true)
            {
                i += 1;
                i *= rd.Next(0, 4);
            }
        }
    }
}
