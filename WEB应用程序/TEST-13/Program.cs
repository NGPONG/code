using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TEST_13
{
    class Program
    {
        static void Main(string[] args)
        {
            Thread worker = new Thread(()=> 
            {
                TestClass test = new TestClass();
                test.DoSomething();
            });

            worker.Start();
            Console.ReadLine();
        }
    }

    public class TestClass
    {
        int i = 0;
        public void DoSomething()
        {
            lock (this)
            {
                if (++i > 5)
                {
                    return;
                }
                Console.WriteLine("My Thread[" + Thread.CurrentThread.ManagedThreadId + "] the " + i + " invoke");
                DoSomething();
            }
        }
    }
}
