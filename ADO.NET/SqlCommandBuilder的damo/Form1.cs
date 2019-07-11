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

namespace SqlCommandBuilder的damo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GetTable();
        }

        public void GetTable() 
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString))
            {
                conn.Open();
                string sql = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo";
                using (SqlCommand selectCommand = new SqlCommand(sql, conn))
                {
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand))
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);
                        dgvUserInfo.DataSource = dt;
                    }
                }
            }
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            GetTable();
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                string selectSqlStr = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime from dbo.UserInfo";
                using (SqlDataAdapter adapter = new SqlDataAdapter(selectSqlStr, conn)) 
                {
                    DataTable dt = dgvUserInfo.DataSource as DataTable;

                    using (SqlCommandBuilder scb = new SqlCommandBuilder(adapter)) 
                    {
                        adapter.DeleteCommand = scb.GetDeleteCommand();
                        adapter.InsertCommand = scb.GetInsertCommand();
                        adapter.UpdateCommand = scb.GetUpdateCommand();
                        adapter.Update(dt);
                    }
                }
            }

            MessageBox.Show("保存成功");
        }
    }
}
