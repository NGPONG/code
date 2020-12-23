using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SqlDataReaderDamon
{
    class Program
    {
        static void Main(string[] args)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    string sql = @"select CutomerID, CustomerName, CustomerAge, CustomerAddress from dbo.Customer";
                    cmd.CommandText = sql;
                    using (StreamWriter sw = new StreamWriter(@"C:\Users\Administrator\Desktop\SQLInfo.txt", true)) 
                    {
                        sw.Write("CustomerID\t\tCustomerName\t\tCustomerAge\t\tCustomerAddress\r\n");

                        //返回一个SqlDataReader对象
                        //该对象其实是指向所查询表 头行 的指针
                        //System.Data.CommandBehavior.CloseConnection：当SqlDataReader释放的使用，顺便把他的SqlConnection连接通道也释放了
                        using (SqlDataReader reader = cmd.ExecuteReader(System.Data.CommandBehavior.CloseConnection))
                        {
                            //每当我们执行一次Read()函数，指针就往下一行数据走
                            //当返回结果为False则代表指向的下一行没有数据
                            while (reader.Read())
                            {
                                string customerID = reader["CutomerID"].ToString();
                                string customerName = reader["CustomerName"].ToString();
                                string customerAge = reader["CustomerAge"].ToString();
                                string customerAddress = reader["CustomerAddress"].ToString();


                                string sqlrow = string.Format("{0}\t{1}\t{2}\t{3}\r\n", customerID, customerName, customerAge, customerAddress);
                                sw.Write(sqlrow);

                            }//End of While
                        }//End of Reader
                    }//End of StreamWriter
                }//End of SqlCommand
            }//End of SqlConnection

            Console.WriteLine("写入成功");

            Console.ReadLine();
        }
    }
}
