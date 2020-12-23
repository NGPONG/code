using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程lock
{
    class Program
    {
        public static object obj = new object();
        static void Main(string[] args)
        {
            ThreadClassTest tc = new ThreadClassTest();
            Thread th = new Thread(tc.ThreadMethod);
            th.Start();

            Thread.Sleep(1000);
            lock (obj) 
            {
                Console.WriteLine("如果我没有被输出，就证明obj已经被其他地方占用了");
            }

            Console.ReadLine();
        }
    }
    class ThreadClassTest 
    {
        public void ThreadMethod() 
        {
            lock (Program.obj) 
            {
                Thread.Sleep(10000);
            }
        }
    }
}
