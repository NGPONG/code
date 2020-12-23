using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 匿名函数
{
    public delegate void DelSay(string name);
    class Program
    {
        static void Main(string[] args)
        {
            DelSay del = delegate(string name) 
            {
                Console.WriteLine("Hello"+name);
            };
            Say("吴鹏", delegate(string name)
            {
                Console.WriteLine("你好"+name);
            });

        }
        public static void Say(string name,DelSay del) 
        {
            del(name);
        }
    }
}
