using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test
{
    public class EventTest
    {
        private int value;

        public delegate void NumManipulationHandler();


        public event NumManipulationHandler ChangeNum;
        protected virtual void OnNumChanged()
        {
            if (ChangeNum != null)
            {
                ChangeNum(); /* 事件被触发 */
            }
            else
            {
                Console.WriteLine("event not fire");
                Console.ReadKey(); /* 回车继续 */
            }
        }


        public EventTest()
        {
            int n = 5;
            SetValue(n);
        }


        public void SetValue(int n)
        {
            if (value != n)
            {
                value = n;
                OnNumChanged();
            }
        }
    }


    /***********订阅器类***********/

    public class subscribEvent
    {
        public void printf()
        {
            Console.WriteLine("event fire");
            Console.ReadKey(); /* 回车继续 */
        }
    }

    /***********触发***********/
    public class MainClass
    {
        public static void Main()
        {
            EventTest e = new EventTest(); /* 实例化对象,第一次没有触发事件 */
            subscribEvent v = new subscribEvent(); /* 实例化对象 */
            e.ChangeNum += new EventTest.NumManipulationHandler(v.printf); /* 注册 */
            e.SetValue(7);
            e.SetValue(11);
        }
    }
}