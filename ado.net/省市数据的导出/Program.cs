using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 省市数据的导出
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Area> list = new List<Area>();

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Administrator\Desktop\Area.txt", true)) 
            {
                using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["sqlConnection"].ConnectionString)) 
                {
                    //在连接池中寻找有没有内连接对象
                    //如果有直接拿来用，没有的话则创建一个
                    //当Close()的时候会把先前使用的内连接对象放回连接池中去
                    conn.Open();

                    using (SqlCommand cmd = conn.CreateCommand()) 
                    {
                        string sql = @"select AreaId, AreaName, AreaPid from dbo.AreaFull";
                        cmd.CommandText = sql;

                        //返回一个指向查询结果表的头行的指针
                        using (SqlDataReader reader = cmd.ExecuteReader()) 
                        {
                            //每当Read()一次，指针则往下一行数据走
                            while (reader.Read()) 
                            {
                                Area are = new Area();
                                are.AreaID = int.Parse(reader["AreaId"].ToString());
                                are.AreaName = reader["AreaName"].ToString();
                                are.AreaPid = int.Parse(reader["AreaPid"].ToString());
                                list.Add(are);
                            }//End of While
                        }//End of SqlDataReader
                    }//End of SqlCommand
                }//End of SqlConnection

                for (int i = 0; i < list.Count; i++)
                {
                    sw.Write("{0}\t\t\t\t{1}\t\t\t\t{2}\r\n", list[i].AreaID, list[i].AreaName, list[i].AreaPid);
                }

            }//End of StreamWriter

            Console.WriteLine("写入成功");
            Console.ReadLine();
        }
    }
}
