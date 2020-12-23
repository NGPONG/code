using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 吴鹏_面向对象
{
    class Person
    {
        public string name;
        private int age;
        private char sex;

        public int Age
        {
            get
            {
                return age;
            }
            set
            {
                if (value >= 0)
                {
                    age = value;
                }
                else
                {
                    Age = 0;
                }
            }
        }
        public char Sex
        {
            set
            {
                if (value == '男' || value == '女')
                {
                    sex = value;
                }
                else
                {
                    sex = '0';
                }
            }
        }


        //public void Checksex(char checksex) 
        //{
        //    if (checksex == '男' || checksex == '女')
        //    {
        //        sex = checksex;
        //    }
        //    else 
        //    {
        //        sex = '0';
        //    }
        //}
        public void SayWord()
        {
            Console.WriteLine("我叫{0}，我是{1}性，我今年{2}岁", name, sex, Age);
        }
        public void Walk()
        {
            Console.WriteLine("我会行走");
        }


        public void SayHello() 
        {
            Console.WriteLine("11111");
        }


    }
}
