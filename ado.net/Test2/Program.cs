using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test2
{
    class Program
    {
        static void Main(string[] args)
        {
            string connStr = "server=(local);uid=sa;pwd=kissyou199;database=damon";
            SqlConnection conn = new SqlConnection();

            SqlConnection conn2 = new SqlConnection();
            conn2.ConnectionString = connStr;
            conn2.Open();

            string temp = string.Empty;
            //F:\c#\0001传智24期资料无密码版\02 数据库四天\2015-04-25 数据库03\资料\上课笔记.txt
            using (StreamReader sr = new StreamReader(@"F:\c#\0001传智24期资料无密码版\02 数据库四天\2015-04-25 数据库03\资料\上课笔记.txt", Encoding.Default))
            {
                while (!sr.EndOfStream)
                {
                    Console.WriteLine(sr.ReadLine());
                }

            }
            Console.ReadLine();
        }

    }
}
