using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 以DOM方式读取XML文档对象_判断是否登陆成功
{
    public class Person
    {
        public string Name { get; set; }
        public string ID { get; set; }
        public string Gender { get; set; }
        public string Age { get; set; }

        public Person(string name, string id, string gender, string age) 
        {
            this.Name = name;
            this.ID = id;
            this.Gender = gender;
            this.Age = age;
        }
    }
}
