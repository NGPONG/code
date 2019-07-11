using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程的使用
{
    class Program
    {
        private static Test te = new Test();
        static void Main(string[] args)
        {
            Program pro = new Program();
            Program pro2 = new Program();
            Thread aThread = new Thread(pro.ThreadMethod);
            aThread.Name = "线程A";
            Thread bThread = new Thread(pro.ThreadMethod);
            bThread.Name = "线程B";

            aThread.Start();
            bThread.Start();

            Console.ReadLine();
        }

        public void ThreadMethod(object parameter)
        {
            lock (this) 
            {
                for (int i = 0; i < 5; i++)
                {
                    te.Age += i;
                    Console.WriteLine("我是【{0}】，我执行了{1}次", Thread.CurrentThread.Name, i + 1);
                    Thread.Sleep(300);
                }
                Console.WriteLine(te.Age);
            }
        }

        public static void ThreadMethod2(object parameter)
        {
            for (int i = 0; i < 7; i++)
            {
                te.Age += i * 2;
                Console.WriteLine("我是【{0}】，并且我是不同的function，我执行了{1}次", Thread.CurrentThread.Name, i + 1);
                Thread.Sleep(300);
            }
            Console.WriteLine(te.Age);
        }


        public class Test
        {
            public int Age;
        }
    }
}
