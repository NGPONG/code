using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test09
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = "3213123123123";
            byte[] buff = Encoding.Default.GetBytes(str);

            Console.WriteLine(buff.ToString());

            Console.ReadLine();
        }
    }
}
