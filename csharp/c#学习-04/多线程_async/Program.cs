using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 多线程_async
{
    class Program
    {
        static void Main()
        {
            MyAsyncMethod();
            string input = "";
            while ((input = Console.ReadLine()) != "q")
            {
                Console.WriteLine($"your input is {input}");
            }
        }

        static async void MyAsyncMethod()
        {
            Console.WriteLine("call MyAsyncMethod.....ThreadID["+Thread.CurrentThread.ManagedThreadId+"]");
            Task<int> calculateResult = CalculateAsync();
            Console.WriteLine("MyAsyncMethod was called.......ThreadID[" + Thread.CurrentThread.ManagedThreadId + "]");
            int result = await calculateResult;
            Console.WriteLine($"result is {result}");
        }

        static async Task<int> CalculateAsync()
        {
            Console.WriteLine("calculation begin.....ThreadID[" + Thread.CurrentThread.ManagedThreadId + "]");
            int t = await Task.Run(() => Calculate());
            Console.WriteLine("calculation complete.....ThreadID[" + Thread.CurrentThread.ManagedThreadId + "]");
            return t;
        }

        static int Calculate()
        {
            // Compute total count of digits in strings.
            int count = 5;
            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(500);
                Console.WriteLine($"calculating step {i + 1}");
            }
            Random random = new Random();
            return random.Next();
        }
    }
}
