using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_01
{
    namespace TEST_TEST {

        public class Class2 {

            int a = 10;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TestTask();
        }
        private static async void TestTask()
        {
            Console.WriteLine("step1,线程ID:{0}", System.Threading.Thread.CurrentThread.ManagedThreadId);


            AsyncDemo demo = new AsyncDemo();
            //var result = demo.AsyncSleep().Result;//Result会阻塞当前线程直到AsyncSleep返回
            demo.AsyncSleep().Wait();   //Wait会阻塞当前线程直到AsyncSleep返回
                                        //Console.WriteLine(result);
                                        //demo.AsyncSleep();//不会阻塞当前线程

            Console.WriteLine("step5,线程ID:{0}", System.Threading.Thread.CurrentThread.ManagedThreadId);
            Console.ReadLine();
        }
    }

    public class AsyncDemo
    {
        public async Task<string> AsyncSleep()
        {
            Console.WriteLine("step2,线程ID:{0}", System.Threading.Thread.CurrentThread.ManagedThreadId);


            //await关键字表示“等待”Task.Run传入的逻辑执行完毕，此时(等待时)AsyncSleep的调用方能继续往下执行（准确地说，是当前线程不会被阻塞）
            //Task.Run将开辟一个新线程执行指定逻辑
            var result = "";
            result = await Task.Run(() => Sleep(10)).ConfigureAwait(false);
            //await Task.Run(() => Sleep(10));
            Console.WriteLine("step4,线程ID:{0}", System.Threading.Thread.CurrentThread.ManagedThreadId);

            return result;
        }

        private string Sleep(int second)
        {
            Console.WriteLine("step3,线程ID:{0}", System.Threading.Thread.CurrentThread.ManagedThreadId);


            Thread.Sleep(second * 1000);
            return "sleep";
        }
    }
}
