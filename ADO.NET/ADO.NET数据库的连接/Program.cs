using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ADO.NET数据库的连接
{
    class Program
    {
        public static int i;
        static void Main(string[] args)
        {
            // 连接数据库的一些基本信息：服务器、账号、密码、数据库名
            // windows身份验证：intergrated Security=true;
            // 设置连接池：Poling=true/false;Max Pool Size=100;Min Pool Size=0;
            // 登陆服务器名/实例：server="";
            // 设置账号密码：uid="";pwd="";
            // 设置连接的数据库：database="";
            string connStr = "server=(local);uid=sa;pwd=kissyou199;database=damon";

            // 通过SqlConnectionStringBuilder类也能设置连接数据库的一些基本信息 
            SqlConnectionStringBuilder scsb = new SqlConnectionStringBuilder();
            scsb.DataSource = ".";
            scsb.UserID = "sa";
            scsb.Password = "kissyou199";
            scsb.InitialCatalog = "damon";
            string connStr2 = scsb.ToString();

            //创建sqlconnection的对象，该对象负责建立跟数据库的连接
            SqlConnection conn = new SqlConnection(connStr);

            //连接数据库
            conn.Open();
            Console.WriteLine("数据库连接成功");
            
            //创建SQL命令对象cmd
            //通过using() 自动帮我们释放SqlCommand的资源
            using (SqlCommand cmd = new SqlCommand()) 
            {
                //通过SqlConnection的函数CreateCommand()
                SqlCommand cmd1 = conn.CreateCommand();

                //通过对Connection属性赋值，指定了cmd要在哪个数据库中操作
                //SqlCommand需要通过SqlConnection的对象去关联到数据库
                cmd.Connection = conn;

                //指定cmd操作的SQL脚本
                cmd.CommandText = @"insert into dbo.Customer(CustomerName,CustomerAge,CustomerAddress) values(N'吴鹏小写',22,N'深圳南山')";

                //ExecuteNonQuery：执行非查询的SQL语句
                //返回值为int类型，返回受影响的行数
                i = cmd.ExecuteNonQuery();

                //ExecuteScalar：执行我们所指定的一条SQL的查询语句
                //返回值为object类型，返回我们所查询到的表中的第一行第一列的数据
                object o = cmd.ExecuteScalar();

            }

            
            Console.WriteLine("操作成功，有{0}行受影响", i);

            //关闭数据库连接
            conn.Close();
            //释放资源
            conn.Dispose();
            Console.WriteLine("数据库关闭");

            Console.ReadKey(true);


        }
    }
}
