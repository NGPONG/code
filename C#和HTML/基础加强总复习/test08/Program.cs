using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace test08
{
    public delegate string SyncMethodCaller(int time);

    class Program
    {
        static void Main(string[] args)
        {
            SyncMethodCaller caller = new SyncMethodCaller(ThreadMethod);
            Console.WriteLine("现在开始同步调用函数");

            // 如果调用当前函数的线程未UI线程，则直接执行该函数，如果不是则切换至UI线程，使用UI线程执行委托所指向的函数，并阻塞当前线程直至UI线程执行完委托所指向的函数
            string str = caller.Invoke(300);

            Console.WriteLine("在同步调用未结束前，我是不会给显示");
            Console.WriteLine(str);
            Console.ReadLine();
        }

        public static string ThreadMethod(int time) 
        {
            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(time);
                Console.WriteLine("线程执行{0}次", i + 1);
            }

            return "执行完成";
        }
    }
}
