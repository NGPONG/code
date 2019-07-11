using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataTable中的一些使用
{
    class Program
    {
        static void Main(string[] args)
        {
            DataTable dt = new DataTable();
            dt.Columns.AddRange(new DataColumn[] { new DataColumn("Name", typeof(string)), new DataColumn("Age", typeof(int)) });
            dt.Rows.Add("吴鹏", 22);
            dt.Rows.Add("c#", 100);

            // 根据指定表达式查询DataTable
            DataRow[] drItemArrary = dt.Select("Name like '%吴%'");

            // 复制当前表的所有结构（不包含数据），并返回一张新的内存表
            DataTable dtClone = dt.Clone();

            // 获取一个DataRow
            DataRow drItem = dt.Rows[0];

            // DataTable.ImportRow(DataRow drItem)：把drItem中的数据添加至DataTable中（需要存在相同列名才能够匹配）
            dtClone.ImportRow(drItem);

            // DataRow.ItemArrary：获取当前DataRow数据的一个object类型的集合
            dtClone.Rows.Add(drItem.ItemArray);

        }
    }
}
