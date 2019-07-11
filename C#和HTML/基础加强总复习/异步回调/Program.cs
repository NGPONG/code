using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 异步回调
{
    public delegate string AsyncMethodCaller(out decimal time,int num);
    public delegate void AsyncMethodDemo(int num);
    class Program
    {
        static void Main(string[] args)
        {
            AsyncMethodDemo asyncCaller = new AsyncMethodDemo(AsyncMethodTest);
            IAsyncResult result = asyncCaller.BeginInvoke(1000, null, null);

            if (result.AsyncWaitHandle.WaitOne()) 
            {
                Thread.Sleep(3000);
                Console.WriteLine("委托：AsyncMethodDemo 所指向的函数执行完成！");
                for (int i = 0; i < 5; i++)
                {
                    Console.WriteLine("我是主线程，现在由我执行，我执行了{0}次", i + 1);
                    Thread.Sleep(1000);
                }
            }

            asyncCaller.EndInvoke(result);

            Console.ReadLine();
        }

        public static void AsyncMethodTest(int num) 
        {
            decimal time;
            AsyncMethodCaller caller = new AsyncMethodCaller(AsyncMethodDemoForTest);
            IAsyncResult result = caller.BeginInvoke(out time, num, new AsyncCallback(AsyncCallBackMethod), "AsycState:OK");

            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("我是委托：AsyncMethodDemo 所指向的函数，我只执行了{0}次", i + 1);
                Thread.Sleep(1000);
            }
        }

        public static string AsyncMethodDemoForTest(out decimal time, int num) 
        {
            time = 0;
            Stopwatch sw = new Stopwatch();
            sw.Start(); // 开始计时
            for (int i = 0; i < 5; i++)
            {
                Console.WriteLine("我是委托：AsyncMethodCaller 所指向的函数，我执行了{0}次", i + 1);
                Thread.Sleep(num);
            }
            sw.Stop(); // 结束计时
            time = sw.Elapsed.Seconds;
            return "It's ok！";
        }

        public static void AsyncCallBackMethod(IAsyncResult result) 
        {
            decimal time;

            AsyncMethodCaller handler = (AsyncMethodCaller)((AsyncResult)result).AsyncDelegate; // AsyncDelegate 属性可以强制转换为用户定义的委托的实际类。
            string strMethodResult = handler.EndInvoke(out time, result);

            Console.WriteLine("我是回调函数，我执行完了！委托：AsyncMethodCaller 所指向的函数返回的结果为：{0}，用时：{1}秒，我的AsycState为：{2}", strMethodResult, time, result.AsyncState.ToString());
        }

    }
}
