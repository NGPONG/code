using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Test_08
{
    class Program
    {
        List<string> strTags = new List<string>();

        static void Main(string[] args)
        {
            bool flag = true;
            Console.WriteLine("Begin Testing……");

            while (flag)
            {
                Task.Factory.StartNew(()=> 
                {
                    string threadId = Thread.CurrentThread.ManagedThreadId.ToString();
                    Console.WriteLine($"我是线程{threadId}");
                    if (CallContext.GetData($"Thread{threadId}") != null)
                    {
                        flag = false;
                        return;
                    }
                    CallContext.SetData($"Thread{threadId}", new object());
                });
            }

            Console.ReadLine();
        }
    }
}
