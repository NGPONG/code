using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 使用委托求任意数组的最大值
{
    public delegate int DelMax(object max,object o1);

    public delegate int DelMaxPerson(object max,object o);
    class Program
    {
        static void Main(string[] args)
        {
            //object[] oint = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

            //object[] oString = { "asdasd", "qwdqidjoqiwd", "asdfkasd", "s'lfkqower01qweeqw" };
            //object result = GetMax(oString, (object max, object o1) =>
            //                         {
            //                              string n1 = (string)max;
            //                              string n2 = (string)o1;
            //                              return n1.Length - n2.Length;
            //                         });
            //Console.WriteLine(result);

            object[] objs = { new Person() { Name = "吴鹏", Age = 22 }, new Person() { Name = "张三", Age = 13 }, new Person() { Name = "李四", Age = 5 }, new Person() { Name = "王五", Age = 20 } };

            Person perResult = GetMaxClass(objs, delegate(object max, object o)
            {
                Person permax = max as Person;
                Person pero = o as Person;
                return permax.Age - pero.Age;
            });

            //Console.WriteLine(perResult.Name);


            List<int> list = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            //where() 括号里面放一个参数类型为我们所定义的泛型，返回值为bool的方法
            IEnumerable<int> nums = list.Where((int i) => { return i < 5; });

            foreach (var item in nums)
            {
                Console.WriteLine(item);
            }
            

            Console.ReadLine();
        }

        public static Person GetMaxClass(object[] objs, DelMaxPerson del) 
        {
            object max = objs[0];
            for (int i = 0; i < objs.Length; i++)
            {
                if (del(max, objs[i])<0) 
                {
                    max = objs[i];
                }
            }
            return (Person)max;
        }
        public static object GetMax(object[] objs,DelMax del) 
        {
            object max = objs[0];
            for (int i = 0; i < objs.Length; i++)
            {
                if (del(max, objs[i]) < 0) 
                {
                    max = objs[i];
                }
            }
            return max;
        }
    }
    public class Person 
    {
        public int Age { get; set; }
        public string Name { get; set; }
    }
}
