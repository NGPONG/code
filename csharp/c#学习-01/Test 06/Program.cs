using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test_06
{
    class Program
    {
        static void Main(string[] args)
        {
            //Program pro = new Program();
            //pro.test();
            //int a = 4;
            //test(out a);
            //Console.ReadLine();

            //string str = "213";
            //int a;
            //int.TryParse(str,out a);
            //bool flag;
            //bool.TryParse("True",out flag);

            //string s = new string(new char[] { '1', '2' });

            //List<int> list = new List<int>();

            //ArrayList list = new ArrayList();
            //list.Add(12);
            //int a = 1;
            //int b = a + (int)list[0];
            //Console.ReadLine();

            //using (FileStream fsRead = new FileStream(@"C:\Users\Administrator\Desktop\bookName.txt", FileMode.OpenOrCreate, FileAccess.Read))
            //{
            //    byte[] byt = new byte[1024 * 1024 * 5];
            //    int i = fsRead.Read(byt, 0, byt.Length);
            //    byte[] byts = Encoding.UTF8.GetBytes(Encoding.UTF8.GetString(byt, 0, i));
            //    using (FileStream fsWrite = new FileStream(@"C:\Users\Administrator\Desktop\newbook.txt", FileMode.Create, FileAccess.Write))
            //    {
            //        fsWrite.Write(byts, 0, i);
            //    }
            //}


            //IWalkable walk = new Student();
            //walk.Walk();
            //(new Student()).Walk();
            //Console.ReadLine();

            //ttt test = new ttt() { Name = "吴鹏", Age = 21 };
            //test.SayHello();
            //Console.ReadLine();

            //using (FileStream fsRead = new FileStream(@"C:\Users\Administrator\Desktop\bookName.txt", FileMode.OpenOrCreate, FileAccess.Read)) 
            //{
            //    byte[] byts = new byte[1024 * 1024 * 5];
            //    int r = fsRead.Read(byts, 0, byts.Length);
            //    Console.WriteLine(Encoding.Default.GetString(byts));
            //}
            //Console.ReadLine();

            string str = "11121111";
            int i = str.LastIndexOf('2');
            Console.WriteLine(i);
            Console.ReadLine();
        }
        public static void test(ref int a) 
        {
            a = 3;

        }
    }

    public partial class ttt 
    {
        public int Age
        {
            get;
            set;
        }
        public string Name
        {
            get;
            set;
        }
    }

    public partial class ttt
    {
        public void SayHello() 
        {
            Console.WriteLine("我叫{0},今年{1}岁了",this.Name,this.Age);
        }
    }
    public class Person :IWalkable
    {

        public void Walk()
        {
            Console.WriteLine("12344");
        }
    }
    public class Student : Person 
    {
        public void Walk()
        {
            Console.WriteLine("12123124");
        }
    }

    public interface IWalkable 
    {
        void Walk();
    }
    class TestClass 
    {
        public void test() 
        {
        
        }
    }
    public class Son
    {
    }
}
