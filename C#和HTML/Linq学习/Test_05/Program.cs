using System;
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

    public class Student
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public string Sex { get; set; }
        public string Address { get; set; }
    }
}
