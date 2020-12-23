using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程_Task
{
    public delegate TResult MyDelegate<T, TResult>(T t1);
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
            //CancellationTokenSource cts = new CancellationTokenSource();
            //Task task = Task.Run(() =>
            //{
            //    while (true)
            //    {
            //        if (cts.IsCancellationRequested)
            //        {
            //            cts.Token.ThrowIfCancellationRequested();
            //        }
            //    }
            //}, cts.Token);
            //Thread.Sleep(1000);
            //cts.Cancel();
            //Thread.Sleep(1000);
            //Console.WriteLine(task.Status.ToString());


            // created
            //Task task = new Task(() =>
            //{
            //    Console.WriteLine("start!");
            //});

            //Console.WriteLine(task.Status.ToString());

            // Faulted
            //Task task = Task.Run(()=> 
            //{
            //    throw new Exception("exception!");
            //});
            //Thread.Sleep(2000);
            //Console.WriteLine(task.Status.ToString());

            // RanToCompletion
            //Task task = Task.Run(() => { });

            //task.Wait();
            //Console.WriteLine(task.Status.ToString());

            // Running
            //Task task = Task.Run(() => { Thread.Sleep(5000); });

            //// 等待一下，不然状态没及时更新过来
            //Thread.Sleep(1000);
            //Console.WriteLine(task.Status.ToString());

            //// WaitingForActivation
            //Task mainTask = new Task(() =>
            //{
            //    Thread.Sleep(50000);
            //});
            //mainTask.Start();

            //// 创建一个任务subTask依赖于主任务mainTask
            //Task subTask = mainTask.ContinueWith((t1) =>
            //{

            //});

            //Thread.Sleep(2000);
            //Console.WriteLine(subTask.Status.ToString());

            // WaitingToRun
            //Console.WriteLine(Task.Run(() =>
            //{
            //    Thread.Sleep(3000);
            //}).Status.ToString());

            #endregion

            #region Task的等待机制

            // WaitAll
            //Task.WaitAll(
            //Task.Run(() =>
            //{
            //    Thread.Sleep(2000);
            //    Console.WriteLine($"我是线程【{Thread.CurrentThread.ManagedThreadId}】我执行完毕");
            //}),
            //Task.Run(() =>
            //{
            //    Thread.Sleep(2000);
            //    Console.WriteLine($"我是线程【{Thread.CurrentThread.ManagedThreadId}】我执行完毕");
            //}),
            //Task.Run(() =>
            //{
            //    Thread.Sleep(2000);
            //    Console.WriteLine($"我是线程【{Thread.CurrentThread.ManagedThreadId}】我执行完毕");
            //}));

            //Console.WriteLine("我是MainThread!");

            // Wait
            //Task subTask = Task.Run(()=> 
            //{
            //    Thread.Sleep(2000);
            //    Console.WriteLine("我是子线程，我执行完了!");
            //});

            //subTask.Wait();

            //Console.WriteLine("只有当任务执行完才可以执行我哟");

            #endregion

            #region Task的取消

            //// 创建取消信号量
            //CancellationTokenSource cts = new CancellationTokenSource();

            //Task.Run(()=> 
            //{
            //    while (true)
            //    {
            //        // 当取消信号量调用了【Cancel()】函数后，则该方法会抛出TaskCanceledException
            //        cts.Token.ThrowIfCancellationRequested();
            //    }
            //},cts.Token);

            //Thread.Sleep(1000);

            //cts.Cancel();

            #endregion

            #region Task的延续

            //Task mainTask = new Task(()=> 
            //{
            //    Thread.Sleep(3000);
            //    Console.WriteLine("我是主线程，我开始执行了");
            //});

            //// 当任务【mainTask】执行完毕后才执行【subTask】，使【subTask】依赖于【MainTask】
            //Task subTask = mainTask.ContinueWith((t1) =>
            //{
            //    Thread.Sleep(3000);
            //    Console.WriteLine("我是子线程，我开始执行了");
            //});

            //mainTask.Start();


            #endregion

            #region 任务实例的一些属性

            Task task = Task.Run(() =>
            {
                Thread.Sleep(1000);
            });

            // 任务是否完成
            bool isComplete = task.IsCompleted;

            // 任务是否由信号标量取消，并抛出一个【TaskCanceledException】的异常
            bool isCanceled = task.IsCanceled;

            // 任务是否抛出了未知的异常
            bool isFaulted = task.IsFaulted;

            #endregion

            #region 长任务的创建

            //// 指定当前任务是一个【长任务】，通过这样的手段，该任务在调度的时候就不会抽取线程池中的线程来执行
            //Task.Factory.StartNew(() =>
            //{
            //    // 模拟阻塞耗时操作
            //    Thread.Sleep(10000);
            //}, TaskCreationOptions.LongRunning);

            #endregion

            #region 所依赖的任务不能出现异常

            Task mainTask = new Task(() =>
            {
                Thread.Sleep(1000);
                throw new Exception("主线程出错啦!");
            });

            // 当【mainTask】没有出现错误的时候【subTask】才继续执行
            Task subTask = mainTask.ContinueWith((t1) =>
            {
                Thread.Sleep(1000);
                Console.WriteLine("mainTask没有出现错误才会执行我哟!");
            }, TaskContinuationOptions.NotOnFaulted);

            mainTask.Start();

            #endregion

            Console.ReadLine();
        }
    }
}
