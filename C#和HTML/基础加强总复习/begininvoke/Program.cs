using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace begininvoke
{
    public delegate string AsyncMethodCaller(out int number,int time);
    class Program
    {
        static void Main(string[] args)
        {
            int number;

            AsyncMethodCaller caller = new AsyncMethodCaller(CallBackMethod);
            IAsyncResult result = caller.BeginInvoke(out number, 600, null, null);

            // 在BeginInvoke至EndInvoke之间的代码块是不会发生线程的阻塞的

            // 使用BeginInvoke所返回的异步核心IAsyncResult中的IsCompleted属性来不断的获取异步调用是否完成的执行结果
            while (!result.IsCompleted) 
            {
                Console.WriteLine("线程还未完成！");
                Thread.Sleep(1000);
            }
            // 使用AsyncWaitHandle的WaitOne函数来阻塞当前线程的继续使用，直至异步调用的结束并返回相应的结果true
            if (result.AsyncWaitHandle.WaitOne()) 
            {
                Console.WriteLine("线程执行完成！");
                Thread.Sleep(1000);
            }

            // 阻塞调用BeginInvoke的线程，直至委托所指向的函数所使用的线程执行完成才会恢复阻塞
            string strResult = caller.EndInvoke(out number, result);
            Console.WriteLine("线程未执行完我不会执行哟");
        }

        public static string CallBackMethod(out int number, int time) 
        {
            number = 0;
            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(time);
                Console.WriteLine("循环的第{0}次", i + 1);
                number++;
            }
            return string.Format("线程执行完毕！循环了{0}次", number.ToString());
        }
    }
}
