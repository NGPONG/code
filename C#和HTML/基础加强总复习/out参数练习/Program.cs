using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace out参数练习
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("请输入用户名");
            string userName = Console.ReadLine();
            Console.WriteLine("请输入密码");
            string userPwd = Console.ReadLine();
            bool flag;
            Console.WriteLine(IsLogin(userName, userPwd, out flag));
            Console.WriteLine(flag);
            Console.ReadLine();
        }
        public static string IsLogin(string userName,string userPwd,out bool flag) 
        {
            flag = true;
            if (userName == "admin" && userPwd == "88888888")
            {
                return "登陆成功";
            }
            else if (userName != "admin" && userPwd != "88888888")
            {
                flag = false;
                return "用户名和密码错误";
            }
            else if (userName != "admin")
            {
                flag = false;
                return "用户名错误";
            }
            else 
            {
                flag = false;
                return "密码错误";
            }
        }
    }
}
