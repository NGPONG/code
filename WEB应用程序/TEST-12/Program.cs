using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TEST_12
{
    class Program
    {
        static void Main(string[] args)
        {
            TestLock testlock = new TestLock();
            Thread th1 = new Thread(() =>
            {
                testlock.DoWorkWithLock();
            });
            th1.Start();

            Thread th2 = new Thread(()=>
            {
                testlock.MotherCallYouDinner();
                testlock.DoWorkWithLock();
            });
            th2.Start();

            Console.ReadLine();
        }
    }

    public class TestLock
    {
        public static readonly object objLock = new object();
        public string TestPropertity { get; set; }
        /// <summary>
        ///  该方法，希望某人在工作的时候，其它人不要打扰（希望只有一个线程在执行)
        /// </summary>
        /// <param name="methodIndex"></param>
        public void DoWorkWithLock()
        {
            //锁当前对象
            lock (this)
            {
                Console.WriteLine("lock this");
                int i = 0;
                while (true)
                {
                    Console.WriteLine("At work, do not disturb...,Thread id is " + Thread.CurrentThread.ManagedThreadId.ToString());
                    Thread.Sleep(1000);
                    if (i == 5)
                    {
                        break;
                    }
                    Console.WriteLine(i.ToString());
                    i++;
                }
            }
            Console.WriteLine("lock dispose");
        }
        public void MotherCallYouDinner()
        {
            Console.WriteLine("Your mother call you to home for dinner.");
        }
    }
}
