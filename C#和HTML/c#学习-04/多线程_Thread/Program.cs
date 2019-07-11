using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程_Thread
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread myThread = new Thread((object obj) =>
            {
                try
                {
                    for (int i = 0; i < 10; i++)
                    {
                        Console.WriteLine("The [" + (i + 1) + "] way to invoke For Thread,This's My Receive Message[" + obj.ToString() + "]");
                        Thread.Sleep(500);
                    }
                }
                catch (ThreadAbortException ex)
                {
                    string message = ex.Message;
                    // 恢复最近一次被终止的线程
                    Thread.ResetAbort();
                }
            });

            myThread.Start("Hello Pong");

            // 阻塞指定毫秒调用当前函数的线程的继续调用，直至join()函数的线程实例所指向的方法执行完毕或超过指定毫秒才恢复调用当前函数的线程的继续调用
            myThread.Join(3000);

            //// 设置线程名称
            //myThread.Name = "My Thread";

            //// 指定线程执行优先级
            //myThread.Priority = ThreadPriority.Highest;

            //// 指定线程是否为后台线程，默认为false
            //// 后台线程：当程序结束的时候，所运行中的线程也随之销毁
            //// 前台线程：当程序结束的时候，所运行中的线程也不会跟着销毁
            //myThread.IsBackground = true;



            
            //// 暴力销毁线程，并且在线程执行方法中抛出一个 ThreadAbortException 的异常
            //myThread.Abort();

            Console.WriteLine("This is the main thread to invoke");
            Console.ReadLine();
        }
    }
}
