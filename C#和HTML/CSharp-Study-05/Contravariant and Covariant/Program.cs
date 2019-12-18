using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Contravariant_and_Covariant
{
    public delegate void DelTest<T>(T value);

    class Program
    {
        static void Main(string[] args)
        {
            IPerson<string,object> personStr = new Student<string, object>();

            IPerson<object,string> personObj = new Student<object, string>();

            personStr = personObj;

            Console.ReadKey(true);
        }
    }

    public interface IPerson<in TIn,out TOut>
    {
        TOut Test(TIn value);
    }

    public class Student<TIn,TOut> : IPerson<TIn, TOut>
    {
        public TOut Test(TIn value)
        {
            return default(TOut);
        }
    }

}
