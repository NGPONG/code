using Ninject.Activation;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_05
{
    class Program
    {
        static void Main(string[] args)
        {
            InterTest1 interTest1 = new Student();
            interTest1.TestMethod1();
            InterTest2 interTest2 = new Student();
            interTest2.TestMethod1();

            ArrayList arrayList = new ArrayList();
            IQueryable<string>
            List<Student> children = new List<Student>()
            {
                new Student(){ Name="NGPONG",Age = 18 },
                new Student(){ Name="吴鹏",Age = 22 },
                new Student(){ Name="傻逼",Age = 10 },
                new Student(){ Name="明珠",Age = 30 },
                new Student(){ Name="深圳啊",Age = 100 }
            };

            var query = Enumerable
                        .Where<Student>(children, stu =>
                        {
                            return stu.Age > 20;
                        })
                        .Select(stu =>
                        {
                            return stu.Name;
                        });

            foreach (var item in query)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }
    }

    public class Student: InterTest1
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string Sex { get; set; }
        public string Address { get; set; }

        void InterTest1.TestMethod1()
        {
            Console.WriteLine("I'am InterTest1");
        }

        void InterTest2.TestMethod1()
        {
            Console.WriteLine("I'am InterTest2");
        }
    }

    public interface InterTest1 : InterTest2
    {
        void TestMethod1();
    }

    public interface InterTest2
    {
        void TestMethod1();
    }
}
