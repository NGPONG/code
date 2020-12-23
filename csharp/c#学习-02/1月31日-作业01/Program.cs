using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1月31日_作业01
{
    class Program
    {
        static void Main(string[] args)
        {
            //定义父亲类Father(姓lastName,财产property,血型bloodType)
            //儿子Son类(玩游戏PlayGame方法),女儿Daughter类(跳舞Dance方法)
            //调用父类构造函数(:base())给子类字段赋值
            Father father = new Father("父亲", 50000, "o");
            father.sayHello();
            Son son = new Son("儿子",50000,"o");
            son.sayHello();
            son.playGame();
            Daughter daughter = new Daughter("女儿", 50, "o");
            daughter.sayHello();
            daughter.Dancer();
            Console.ReadLine();
        }
        public class Father 
        {
            private string _lastName;
            public string LastName 
            {
                get { return _lastName; }
                set { this._lastName = value; }
            }
            private int _property;
            public int Property 
            {
                get { return _property; }
                set { this._property = value; }
            }
            private string _bloodType;
            public string BloodType 
            {
                get { return _bloodType; }
                set { this._bloodType = value; }
            }

            public void sayHello() 
            {
                Console.WriteLine("我叫：{0}，我的财产为：{1}，我的血型为{2}",LastName,Property,BloodType);
            }
            public Father(string lastname, int property, string bloodtype) 
            {
                this.LastName = lastname;
                this.Property = property;
                this.BloodType = bloodtype;
            }
        }

        public class Son :Father
        {
            public Son(string lastname, int property, string bloodtype)
                : base(lastname, property, bloodtype) 
            {
                
            }

            public void playGame()
            {
                Console.WriteLine("我会玩游戏");
            }
        }

        public class Daughter :Father
        {
            public Daughter(string lastname, int property, string bloodtype)
                : base(lastname, property, bloodtype) 
            {
            
            }
            public void Dancer() 
            {
                Console.WriteLine("我会跳舞");
            }
        }
    }
}
