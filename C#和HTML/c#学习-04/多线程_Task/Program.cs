using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程_Task
{
    public delegate TResult MyDelegate<T,TResult>(T t1);
    class Program
    {
        static void Main(string[] args)
        {
            #region 创建Task的三种方式
            //// 1. 基础创建方式，当创建好Task的实例后，我们需要手动调用其实例的Start()函数开启任务的执行
            //Task taskDefault = new Task(() =>
            //{
            //    Console.WriteLine($"我是taskDefault，由线程【{Thread.CurrentThread.ManagedThreadId}】执行我");
            //});
            //taskDefault.Start();
            //// 2. 使用默认的任务工厂
            //Task taskFactory = Task.Factory.StartNew(() =>
            //{
            //    Console.WriteLine($"我是taskFactory，由线程【{Thread.CurrentThread.ManagedThreadId}】执行我");
            //});
            //// 3. 简化的方式
            //Task taskRun = Task.Run(() =>
            //{
            //    Console.WriteLine($"我是taskRun，由线程【{Thread.CurrentThread.ManagedThreadId}】执行我");
            //});
            //Console.WriteLine($"我是MainThread，由线程【{Thread.CurrentThread.ManagedThreadId}】执行我"); 
            #endregion

            #region 构建输入参数和输出参数

            //Task<string> myTask = Task<string>.Factory.StartNew((object state) =>
            //{
            //    Thread.Sleep(10000);
            //    return state.ToString();
            //}, "Hello,World!");

            //// 并获取Task的返回值，并阻塞当前线程的继续执行直至Task所指向的函数调用完毕
            //string resultStr = myTask.Result;

            #endregion

            #region 关于Task的状态分布

            // Cancled
            CancellationTokenSource cts = new CancellationTokenSource();
            Task task = Task.Run(() =>
            {
                while (true)
                {
                    if (cts.IsCancellationRequested)
                    {
                        cts.Token.ThrowIfCancellationRequested();
                    }
                }
            }, cts.Token);

            Thread.Sleep(1000);

            cts.Cancel();

            Thread.Sleep(1000);

            Console.WriteLine(task.Status.ToString());

            #endregion

            Console.ReadLine();
        }
    }
}
