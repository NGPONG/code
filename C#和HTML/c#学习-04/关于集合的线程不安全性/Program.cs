using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 关于集合的线程不安全性
{
    class Program
    {
        public static Queue<Person> myQueue = new Queue<Person>();
        static void Main(string[] args)
        {
            Task t1 = Task.Factory.StartNew(() =>
            {
                AddProducts();
            });
            Task t2 = Task.Factory.StartNew(() =>
            {
                AddProducts();
            });
            Task t3 = Task.Factory.StartNew(() =>
            {
                AddProducts();
            });
            Task t4 = Task.Factory.StartNew(() =>
            {
                AddProducts();
            });

            Task.WaitAll(t1, t2, t3, t4);
            Console.WriteLine($"队列中的元素数量应该是：{12000}个，然而普通的Queue不是线程安全的，所以实际数量为：{myQueue.Count}个");
            Console.ReadLine();
        }
        public static void AddProducts()
        {
            for (int i = 0; i < 3000; i++)
            {
                myQueue.Enqueue(new Person() { Name = "吴鹏", Age = 22 });
            }
        }
    }

    public class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }
}
