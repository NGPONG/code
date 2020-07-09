using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DataGuridView
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string connectionStr = ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString;
            using (SqlConnection conn = new SqlConnection(connectionStr)) 
            {
                conn.Open();
                string sql = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo";
                using (SqlDataAdapter sda = new SqlDataAdapter(sql, conn)) 
                {
                    DataSet ds = new DataSet();
                    DataTable dt = new DataTable("dt1");
                    ds.Tables.Add(dt);//把表添加进DataSet中

                    sda.Fill(ds, "dt1");//添加指定数据至DataSet数据集中指定表名的内存表当中
                    dataGridView1.DataSource = ds.Tables["dt1"];//通过DataSet的Tables属性的下标来访问DataTable表
                }
            }
        }
    }
}
