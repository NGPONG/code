using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 委托语法
{
    public delegate void DelSayHello(string name);
    class Program
    {
        static void Main(string[] args)
        {
            Test(englishSayHello);
            Console.ReadLine();
        }
        public static void Test(DelSayHello del) 
        {
            del("吴鹏");
        }
        public static void chineseSayHello(string name) 
        {
            Console.WriteLine("{0}说：你好",name);
        }
        public static void englishSayHello(string name) 
        {
            Console.WriteLine("{0}说：HELLO",name);
        }
    }
}
