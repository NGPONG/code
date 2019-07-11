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

namespace 分页查询的使用
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private int _pagesNumber;

        private int _EndPagesNumber;

        private int _HomePagesNumber = 1;
        private void Form1_Load(object sender, EventArgs e)
        {
            _pagesNumber = _HomePagesNumber;

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString))
            {
                conn.Open();
                using (SqlCommand selectCommand = conn.CreateCommand())
                {
                    selectCommand.CommandText = @"select * from (select *,row_number() over(order by ID) as rowNumer from dbo.UserInfo) as T where T.rowNumer between ((" + _pagesNumber + "-1)*3+1) and (" + _pagesNumber + "*3)";
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand))
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);

                        dataGridView1.DataSource = dt;
                    }
                    #region 判断最后一页是多少
                    selectCommand.CommandText = @"select count(1) from dbo.UserInfo";
                    int num = (int)selectCommand.ExecuteScalar();
                    int temp = num / 3;
                    if (num % 3 == 0)
                    {
                        this._EndPagesNumber = temp;
                    }
                    else
                    {
                        this._EndPagesNumber = temp + 1;
                    } 
                    #endregion
                }
            }
        }

        private void GetSqlData() 
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString))
            {
                conn.Open();
                using (SqlCommand selectCommand = conn.CreateCommand())
                {
                    selectCommand.CommandText = @"select * from (select *,row_number() over(order by ID) as rowNumer from dbo.UserInfo) as T where T.rowNumer between ((" + _pagesNumber + "-1)*3+1) and (" + _pagesNumber + "*3)";
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand))
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);

                        if (dt.Rows.Count <= 0)
                        {
                            MessageBox.Show("已经到最后一行啦!");
                            return;
                        }

                        dataGridView1.DataSource = dt;
                    }
                }
            }
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            _pagesNumber--;
            GetSqlData();
            if (this._pagesNumber < this._HomePagesNumber) 
            {
                this._pagesNumber = this._HomePagesNumber;
            }
        }

        private void btnLast_Click(object sender, EventArgs e)
        {
            _pagesNumber++;
            GetSqlData();
            if (this._pagesNumber > this._EndPagesNumber)
            {
                this._pagesNumber = this._EndPagesNumber;
            }
        }

        private void btnEnd_Click(object sender, EventArgs e)
        {
            this._pagesNumber = this._EndPagesNumber;
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString))
            {
                conn.Open();
                using (SqlCommand selectCommand = conn.CreateCommand())
                {
                    selectCommand.CommandText = @"select * from (select *,row_number() over(order by ID) as rowNumer from dbo.UserInfo) as T where T.rowNumer between ((" + this._EndPagesNumber + "-1)*3+1) and (" + this._EndPagesNumber + "*3)";
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand))
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);

                        if (dt.Rows.Count <= 0)
                        {
                            MessageBox.Show("已经到最后一行啦!");
                            return;
                        }

                        dataGridView1.DataSource = dt;
                    }
                }
            }
        }

        private void btnHome_Click(object sender, EventArgs e)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString))
            {
                conn.Open();
                using (SqlCommand selectCommand = conn.CreateCommand())
                {
                    selectCommand.CommandText = @"select * from (select *,row_number() over(order by ID) as rowNumer from dbo.UserInfo) as T where T.rowNumer between ((" + this._HomePagesNumber + "-1)*3+1) and (" + this._HomePagesNumber + "*3)";
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand))
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);

                        if (dt.Rows.Count <= 0)
                        {
                            MessageBox.Show("已经到最后一行啦!");
                            return;
                        }

                        dataGridView1.DataSource = dt;
                    }
                }
            }
        }
    }
}
