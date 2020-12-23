using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程_ThreadPool
{
    class Program
    {
        static RegisteredWaitHandle _waitHandler = null;
        static void Main(string[] args)
        {
            // 设置线程池最大线程数
            ThreadPool.SetMaxThreads(10, 10);

            // 循环开启新的线程执行任务
            for (int i = 0; i < 10; i++)
            {
                Thread.Sleep(2000);
                ThreadPool.QueueUserWorkItem((object state) =>
                {
                    Console.WriteLine("I Am the QueueUserWorkItem\r\nThread ID [" + Thread.CurrentThread.ManagedThreadId + "]\r\n");
                });
            } 

            // 开启监听线程是否执行完毕
            Program._waitHandler = ThreadPool.RegisterWaitForSingleObject(new AutoResetEvent(false), (object state, bool timeout) =>
            {
                Console.WriteLine("I Am the RegisterWaitForSingleObject\r\nThread ID [" + Thread.CurrentThread.ManagedThreadId + "]\r\ntime out[" + timeout.ToString() + "]\r\n");

                int workerThreads = 0;
                int maxWordThreads = 0;
                int compleThreads = 0;
                ThreadPool.GetAvailableThreads(out workerThreads, out compleThreads);
                ThreadPool.GetMaxThreads(out maxWordThreads, out compleThreads);

                // 如果最大线程数和可用线程数相同，则证明所有线程执行完毕
                if (workerThreads == maxWordThreads)
                {
                    // 关闭定时器
                    Program._waitHandler.Unregister(null);
                    // 重置信息
                    Program._waitHandler = null;

                    Console.WriteLine("*******************************************************");
                    Console.WriteLine("*******************************************************");
                    Console.WriteLine("RegisterWaitForSingleObject is Closed!!!!!");
                }

            }, null, 500, false);

            Console.ReadLine();
        }
    }
}
