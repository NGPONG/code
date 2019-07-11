using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataSet和DataTable的damo
{
    class Program
    {
        static void Main(string[] args)
        {
            //创建一个离线内存的数据集
            DataSet ds = new DataSet("ds");//构造函数为：定义数据集的名称

            //创建一张内存表
            DataTable dt = new DataTable("dt");//构造函数为：定义内存表的名称

            //创建列
            DataColumn dcName = new DataColumn("Name", typeof(string));
            DataColumn dcAge = new DataColumn("Age", typeof(int));
            DataColumn dcGender = new DataColumn("Gender", typeof(char));

            //把列添加入表中
            //dt.Columns获取表中列的集合
            dt.Columns.AddRange(new DataColumn[] { dcName, dcAge, dcGender });
            //dt.Columns[i] 获取第 i 列的内容
            dt.Columns[1].ToString();

            //创建行
            //DataRow类是受保护的，我们需要调用DataTable的NewRow函数来创建DataRow对象
            DataRow dr1 = dt.NewRow();
            //通过DataRows对象[列名]来赋值当前行所对应列的值
            dr1["Name"] = "吴鹏";
            dr1["Age"] = 12;
            dr1["Gender"] = '男';


            //把行添加入表中
            //dt.Rows获取表中行的集合
            dt.Rows.Add("吴鹏", 21, '男');
            dt.Rows.Add("李四", 20, '女');
            dt.Rows.Add("王五", 19, '男');
            //dt.Rows[i]["列名"] 获取第i行我们所指定列名的数据
            dt.Rows[0]["Name"].ToString();
            //dt.Rows[i][j] 获取表中第 i 行第 j 列的数据
            dt.Rows[0][0].ToString();

            //把表添加进数据集中
            //ds.Tables获取数据集中表的集合
            ds.Tables.Add(dt);
            //ds.Tables[下标]：通过下标获取放在DataSet中的内存表DataTable
            ds.Tables[0];
            //ds.Tables[内存表名]：通过自己定义的内存表DataTable的名字来获取在DataSet中的内存表DataTable
            ds.Tables["dt"];


            Console.ReadLine();
        }
    }
}
