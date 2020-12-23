using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test03
{
    public delegate void DelTest();
    class Program
    {
        static void Main(string[] args)
        {
            DelTest del = methodDemo("吴鹏");
            del();
            Console.ReadLine();
        }

        public static DelTest methodDemo(string name)
        {
            return delegate()
                       {
                           Console.WriteLine(name);
                       };
        }
    }
}
