using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 装箱和拆箱
{
    class Program
    {
        static void Main(string[] args)
        {
            //1. 以下代码发生了几次装箱？
            //答：三次
            //第一次为n值类型赋值给Object o引用类型
            //第二次和第三次为在字符串使用+号与任意类型的元素相连的时候，隐式调用了string.Concat()的方法
            //而相连元素中因为存在值类型，所以会默认匹配到使用Object类型作为参数的重载
            //这时候n为值类型，传给object发生了第二次，o强制转换成值类型，又赋值给Object发生了第三次
            //而字符串 “，”因为是引用类型，所以没有发生装箱
            int n = 10;
            object o = n;
            n = 100;
            Console.WriteLine(n + "," + (int)o);
            Console.ReadKey();

            //2. 以下代码发生了几次装箱？
            //答：三次
            //第一次为int类型10赋值给了Object o1
            //第二次和第三次为字符串使用+号与任意类型相连的时候，解析与上一题类似，也是调用了string.Concat()的方法
            //并且实参中存在值类型所以默认匹配到使用Object类型作为形参的重载，这时候：n1、d1都是值类型赋值给引用类型
            //所以发生了第二次和第三次装箱
            string s1 = "a";
            int n1 = 10;
            double d1 = 99.9;
            object o1 = 10;
            string s2 = "x";
            string s3 = s1 + n1 + d1 + o + s2;
            Console.WriteLine(s3);
            Console.ReadKey();

            //3. 以下代码发生了几次装箱？
            //答：1次
            //在n.GetType()的时候发生了装箱，因为n继承于Object类，并且GetType()的方法属于Object类，而int类中没有，所以调用的时候会把n作为object类型来调用GetType()的方法
            //而ToString()这个方法虽然也属于Object类，但是Int类型中存在该方法，所以不用当作Object类型来调用
            int n2 = 10;
            string s4 = n.ToString();
            string s5 = n.GetType().ToString();//由于GetType()不是虚方法子类没有重写，所以调用时需要通过object来调用，查看IL
            Console.WriteLine(s4 + "\t\t\t" + s5);
        }
    }
}
