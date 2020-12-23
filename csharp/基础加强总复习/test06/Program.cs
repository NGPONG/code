using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace test06
{
    class Program
    {
        /// <summary>
        ///  键盘输入DLL引用
        /// </summary>
        /// <param name="bVk"></param>
        /// <param name="bScan"></param>
        /// <param name="dwFlags"></param>
        /// <param name="dwExtraInfo"></param>
        [DllImport("user32.dll", EntryPoint = "keybd_event", SetLastError = true)]
        public static extern void keybd_event(Keys bVk, byte bScan, uint dwFlags, uint dwExtraInfo);

        // 是否从终止线程中返回
        private static bool isAbortThread = false;

        private static bool isChildThreadUse = false;

        // 控制键盘输入的线程
        private static Thread thKeyDown;

        // E键输入次数
        private static int keyE = 0;

        // C键输入次数
        private static int keyC = 0;

        /// <summary>
        ///  主函数引用
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            Console.WriteLine("请输入F1 开始！");
            while (true)
            {
                ConsoleKeyInfo ck = Console.ReadKey(true);
                if (ck.Key.Equals(ConsoleKey.F1))
                {
                    Thread.Sleep(2000);
                    thKeyDown = new Thread(KeyDownMethod);
                    thKeyDown.IsBackground = true; // 后台线程
                    thKeyDown.Start();
                }
                else if (ck.Key.Equals(ConsoleKey.F2))
                {
                    break;
                }
            }
        }


        /// <summary>
        ///  监控键盘输入，如果是F1就开启，F2就关闭
        /// </summary>
        public static void MonitoringKeyDown()
        {
            //try
            //{
            //    while (true)
            //    {
            //ConsoleKeyInfo ck = Console.ReadKey(true);
            //if ((ck.Key == ConsoleKey.F1 || isAbortThread) && isChildThreadUse.Equals(false))
            //{
            thKeyDown = new Thread(KeyDownMethod);
            thKeyDown.IsBackground = true; // 后台线程
            thKeyDown.Start();
            //    }
            //    else if (ck.Key == ConsoleKey.F2) 
            //    {
            //        thKeyDown.Abort();
            //        Thread.CurrentThread.Join(500);
            //        thKeyDown = null;
            //        // 如果输入F2则暴力终止该线程
            //        Thread.CurrentThread.Abort();
            //    }
            //}
            //}
            //catch (ThreadAbortException objException) 
            //{
            //    // 当输入了F2 就开始停止调用线程，并且开始监听键盘的输入，如果输入F1则再次恢复调用
            //    while (true)
            //    {
            //        ConsoleKeyInfo ck = Console.ReadKey(true);
            //        if (ck.Key == ConsoleKey.F1)
            //        {
            //            isAbortThread = true;
            //            Thread.ResetAbort();
            //        }
            //    }
            //}
        }

        /// <summary>
        /// 键盘输入
        /// </summary>
        public static void KeyDownMethod()
        {
            try
            {

                while (true)
                {
                    while (true)
                    {
                        if (keyE < 5)
                        {
                            keybd_event(Keys.E, 0, 0, 0);

                            keyE++;
                            Thread.CurrentThread.Join(500);
                            continue;
                            break;
                        }
                        else
                        {
                            keyE = 0;
                            break;
                        }

                    }

                    while (true)
                    {

                        if (keyC < 5) // C键输入4次 
                        {

                            keybd_event(Keys.C, 0, 0, 0);
                            keyC++;
                            Thread.CurrentThread.Join(500);
                            continue;

                        }
                        else
                        {
                            keyC = 0;
                            break;
                        }
                    }
                }
            }
            catch (Exception objException)
            {
                //isChildThreadUse = false;
            }
        }


    }
}
