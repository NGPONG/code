using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 用xml文档实现增删查改
{
    public class Users
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public char Gender { get; set; }
        public string PassWord { get; set; }

        public Users(int id, string name, int age, char gender, string password) 
        {
            this.ID = id;
            this.Name = name;
            this.Age = age;
            this.Gender = gender;
            this.PassWord = password;
        }

        
    }
}
