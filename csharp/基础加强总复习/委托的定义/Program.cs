using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 委托的定义
{
    public delegate string DelProStr(string str);
    class Program
    {
        static void Main(string[] args)
        {
            string[] names = { "asdasd", "ASDASD", "aaaa" };

            ProString(names, (string name) =>
            {
                name = string.Format("\"{0}\"", name);
                return name;
            });

            for (int i = 0; i < names.Length; i++)
            {
                Console.WriteLine(names[i]);
            }

            Console.ReadLine();
        }

        public static void ProString(string[] names, DelProStr del) 
        {
            for (int i = 0; i < names.Length; i++)
            {
                names[i] = del(names[i]);
            }
        }
    }
}
