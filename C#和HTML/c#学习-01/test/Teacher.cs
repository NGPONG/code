using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    class Teacher : Person
    {
        private int worktime;
        public int Worktime 
        {
            get { return worktime; }
            set { worktime = value; }
        }

        public void SayHello() 
        {
            Console.WriteLine("大家好，我是{0}老师，今年{1}岁了，由{2}年工作经验",Name,Age,Worktime);
        }
        
    }
}
