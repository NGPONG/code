using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TEST_11
{
    public delegate void DelTest();
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("主线程："+Thread.CurrentThread.ManagedThreadId.ToString());

            DelTest del = new DelTest(TestMethod);
            del.BeginInvoke(AsyncCallBack, null);

            DelTest del2 = new DelTest(TestMethod);
            del.BeginInvoke(AsyncCallBack, null);

            Console.ReadLine();
        }

        static void TestMethod()
        {
            Console.WriteLine("子线程：" + Thread.CurrentThread.ManagedThreadId.ToString());
        }

        static void AsyncCallBack(IAsyncResult result)
        {
            DelTest handler = (DelTest)((AsyncResult)result).AsyncDelegate;
            handler.EndInvoke(result);
        }
    }
}
