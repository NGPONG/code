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
