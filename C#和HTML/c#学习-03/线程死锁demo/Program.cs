using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        public static object lock_A = new object();
        public static object lock_B = new object();

        static void Main(string[] args)
        {
            Program pro = new Program();
            Thread.CurrentThread.Name = "主线程";
            Thread threadA = new Thread(pro.DeadLockTest);
            threadA.Start();

            lock (lock_B) // 独占lock_B的资源
            {
                Thread.Sleep(500);
                Console.WriteLine("我是{0}，我正在都长lock_B的资源", Thread.CurrentThread.Name);

                lock (lock_A) // 独占lock_A的资源
                {
                    Console.WriteLine("没出现这句话就表示死锁了");
                }
            }

            Console.ReadLine();
        }

        public void DeadLockTest()
        {
            lock (lock_A) // 独占lock_A的资源
            {
                //Thread.Sleep(1000);

                Console.WriteLine("我是{0}，我正在占用lock_A的资源", Thread.CurrentThread.Name);
                lock (lock_B) // 独占lock_B的资源
                {
                    Console.WriteLine("如果我没有被输出，就证明发生了死锁");
                }
            }
        }
    }
}
