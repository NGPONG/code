using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace TEST_05
{
    public delegate void DelTest();
    class Program
    {
        private static event DelTest TestEvent;
        static void Main(string[] args)
        {
            TestEvent += TestMethod1;
            TestEvent += TestMethod2;
            TestEvent();
        }

        public static void TestMethod1()
        {
            string str = "321";
        }
        public static void TestMethod2()
        {
            string str = "321";
        }
    }
}
