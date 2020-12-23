using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 简单的工厂设计模式
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("你想要什么电脑");
            string need = Console.ReadLine();
            (GetNoteBook(need)).SayHello();
            Console.ReadLine();
        }
        public static NoteBook GetNoteBook(string need) 
        {
            NoteBook nb = null;
            switch (need) 
            {
                case "Asus":
                    nb = new Asus();
                    break;
                case "Samsung":
                    nb = new Samsung();
                    break;
                case "Apple":
                    nb = new Apple();
                    break;
                case "Intel":
                    nb = new Intel();
                    break;
            }
            return nb;
        }
    }
    public abstract class NoteBook 
    {
        public abstract void SayHello();
    }
    public class Asus:NoteBook
    {
        public override void SayHello()
        {
            Console.WriteLine("我是华硕");
        }
    }
    public class Samsung : NoteBook 
    {
        public override void SayHello()
        {
            Console.WriteLine("我是三星");
        }
    }
    public class Intel : NoteBook 
    {
        public override void SayHello()
        {
            Console.WriteLine("我是英特尔");
        }
    }
    public class Apple : NoteBook 
    {
        public override void SayHello()
        {
            Console.WriteLine("我是苹果");
        }
    }
}
