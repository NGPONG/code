using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 数据导入
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnOpenFile_Click(object sender, EventArgs e)
        {
            openFileDialog1.Filter = @"文本文件|*.txt|所有文件|*.*";
            openFileDialog1.ShowDialog();
            txtFilePath.Text = openFileDialog1.FileName;

            using (SqlConnection conn = new SqlConnection())
            {
                conn.ConnectionString = ConfigurationManager.ConnectionStrings["sqlConnection"].ConnectionString;
                conn.Open();
                using (SqlCommand cmd = new SqlCommand())
                {
                    cmd.Connection = conn;
                    using (StreamReader sr = new StreamReader(txtFilePath.Text, Encoding.UTF8))
                    {
                        sr.ReadLine();//第一行数据不需要
                        while (!sr.EndOfStream)
                        {
                            string[] strTemps = sr.ReadLine().Split(new char[] { ',' }, StringSplitOptions.RemoveEmptyEntries);
                            string sql = string.Format(@"insert into dbo.Student( stuName, stuSex, stuBrithday, stuPhone) values(N'{0}',N'{1}','{2}','{3}')", strTemps[1], strTemps[2], strTemps[3], strTemps[4]);

                            cmd.CommandText = sql;
                            cmd.ExecuteNonQuery();
                        }//end of while
                    }//end of StreamReader
                }//end of SqlCommand
            }//end of SqlConnection

            MessageBox.Show("数据添加成功！");
        }


        private void openFileDialog1_FileOk(object sender, CancelEventArgs e)
        {


        }
    }
}
