using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Test_02;

namespace Test_07
{
    class Program
    {
        static void Main(string[] args)
        {
            CallContext.SetData("Person", new Person() { Name = "NGPONG" });
            CallContext.LogicalSetData("Person_Logic", new Person() { Name = "NGPONG_Logic" });

            Task.Run(()=> 
            {
                var per = CallContext.GetData("Person");
                var per_Logic = CallContext.LogicalGetData("Person_Logic");
            });

            Console.ReadLine();
        }
    }

    public class Person
    {
        public string Name { get; set; }
    }
}
