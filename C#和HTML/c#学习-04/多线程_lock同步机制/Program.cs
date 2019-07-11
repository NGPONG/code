using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程_lock同步机制
{
    class Program
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                MyClass cla = new MyClass();
                cla.LockTest();
            }

            Console.WriteLine("repeat complete");

            Console.ReadLine();
        }
    }

    public class MyClass
    {
        private static object objLock = new object();
        public async void LockTest()
        {
            await Task.Run(() =>
            {
                lock (objLock)
                {
                    Thread.Sleep(1000);
                    Console.WriteLine("My Name is [" + Thread.CurrentThread.ManagedThreadId + "]");
                }
            });
        }
    }
}
