using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace test09
{
    class Program
    {
        public delegate void AsyncMethodCallerDemo();

        public delegate void AsyncMethodDemo();
        static void Main(string[] args)
        {
            AsyncMethodDemo async = new AsyncMethodDemo(MethodTest);
            IAsyncResult result = async.BeginInvoke(null, null);

            if (result.AsyncWaitHandle.WaitOne()) // 阻塞线程的执行，直至委托所指向的函数执行完成则恢复线程的使用并且返回true
            {
                for (int i = 0; i < 5; i++)
                {
                    Thread.Sleep(600);
                    Console.WriteLine("我是主线程，我需要测试下我是否会被阻塞");
                }
                async.EndInvoke(result);
            }

            Console.ReadLine();
        }

        public static void MethodTest() 
        {
            AsyncMethodCallerDemo caller = new AsyncMethodCallerDemo(MethodCallerDemo);
            caller.EndInvoke(caller.BeginInvoke(null, null));

            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(600);
                Console.WriteLine("我是AsyncMethodDemo中的线程，我被调用了{0}次，我需要测试我是否会被阻塞", i + 1);
            }
        }

        public static void MethodCallerDemo() 
        {
            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(600);
                Console.WriteLine("我是AsyncMethodCallerDemo中的线程，我被调用了{0}次", i + 1);
            }
        }
    }
}
