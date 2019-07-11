using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test5
{
    class Program
    {
        public int Age;
        public static int num = 3;
        static void Main(string[] args)
        {
            //Person per = new Person("父类", 99, 'x');
            //Son so = new Son("子类", 21, '男', 0423);
            //per.SayHello();

            //Console.WriteLine();
            //per = so;
            //per.SayHello();
            //Console.WriteLine();
            //(per as Son).SayHello();

            //Console.ReadLine();

            //30,1,9,6,25,14,97,88,36,52,61,37

            //int[] intArrary = new int[] { 30, 1, 9, 6, 25, 14, 97, 88, 36, 52, 61, 37 };//12
            //for (int n = 1; n < intArrary.Length; n++)
            //{
            //    for (int i = 0; i < intArrary.Length - n; i++)
            //    {
            //        if (intArrary[i] > intArrary[i + 1]) 
            //        {
            //            int temp = 0;
            //            temp = intArrary[i];
            //            intArrary[i] = intArrary[i + 1];
            //            intArrary[i + 1] = temp;
            //        }
            //    }
            //}
            //for (int i = 0; i < intArrary.Length; i++)
            //{
            //    Console.WriteLine(intArrary[i]);
            //}
            //Console.ReadLine();

            //List<int> list = new List<int>();
            //list.Add(1);
            //list.Add(2);
            //list.Add(3);
            //list[0] = list[2];
            //Console.ReadLine();

            //Dictionary<int, int> dic = new Dictionary<int, int>();
            //dic.Add(0, 1);
            //dic.Add(6, 2);
            //dic.Add(2, 3);
            //dic.Add(3, 4);
            //for (int i = 0; i < dic.Count; i++)
            //{
            //    Console.WriteLine(dic[i]);
            //}
            //Console.ReadLine();
            


        }
        public void Tst() 
        {
            
        }
    }
    class Person 
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public char Gender { get; set; }
        public void SayHello ()
        {
            Console.WriteLine("人类打招呼！我是父类！");
            Console.WriteLine("{0},{1},{2}",Name,Age,Gender);
        }
        public Person(string name, int age, char gender) 
        {
            this.Name = name;
            this.Age = age;
            this.Gender = gender;
        }
    }
    class Son : Person 
    {
        public Son(string name, int age, char gender, int id) 
            :base(name,age,gender)
        {
            this.ID = id;
        }
        public int ID { get; set; }
        public void SayHello() 
        {
            Console.WriteLine("儿子打招呼！我是儿子！");
            Console.WriteLine("{0},{1},{2},{3}",base.Name,base.Age,base.Gender,this.ID);
        }
    }
}
