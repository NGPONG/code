using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏_面向对象
{
    class Student
    {
        public Student() { }
        public Student(string name,char sex) 
        {
            this.name = name;
            this.sex = sex;
            this.age = 18;
        }
        public Student(string name,char sex,int age,int chinese,int math,int english)
        {
            this.name = name;
            this.sex = sex;
            this.Age = age;
            this.Chinese = chinese;
            this.Math = math;
            this.English = english;
        }

        private string name;
        public string Name 
        {
            get
            {
                return name;
            }
        }

        private char sex;
        public char Sex 
        {
            get 
            {
                return sex;
            }
        }

        public int age;
        public int Age 
        {
            get 
            {
                return age;
            }
            set 
            {
                if (value <= 0 || value >= 100)
                {
                    age = 0;
                }
                else 
                {
                    age = value;
                }
            }
        }

        private int chinese;
        public int Chinese 
        {
            get 
            {
                return chinese;
            }
            set 
            {
                if (value > 100 || value < 0)
                {
                    chinese = 0;
                }
                else 
                {
                    chinese = value;
                }
            }
        }

        private int math;
        public int Math 
        {
            get 
            {
                return math;
            }
            set 
            {
                if (value >= 0 && value <= 100)
                {
                    math = value;
                }
                else 
                {
                    math = 0;
                }
            }
        }

        private int english;
        public int English 
        {
            get 
            {
                return english;
            }
            set 
            {
                if (value >= 0 && value <= 100)
                {
                    english = value;
                }
                else 
                {
                    english = 0;
                }
            }
        }


        public void SayHello() 
        {
            Console.WriteLine("我叫{0}，今年{1}岁了，我是{2}同学",name,age,sex);
        }

        public void Score ()
        {
            int add = chinese + english + math;
            int average = add / 3;
            Console.WriteLine("我叫{0}，这次考试的总成绩为{1}分，平均分为{2}",name,add,average);
        }
    }
}
