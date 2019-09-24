using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_07
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Person> people = new List<Person>()
            {
                new Person{ Name="NGPONG",Age = 18 },
                new Person{ Name="吴鹏",Age=22},
                new Person{ Name="傻逼",Age=100}
            };

            var query = from peo in people.AsEnumerable()
                        where peo.Age > 20
                        select peo.Name;

            foreach (var item in query)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }
    }

    public class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }
}
