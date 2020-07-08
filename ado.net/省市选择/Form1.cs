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

namespace 省市选择
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        List<AreaInfo> list = new List<AreaInfo>();
        private void Form1_Load(object sender, EventArgs e)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    string sql = @"select AreaId, AreaName, AreaPid from dbo.AreaFull where AreaPid = 0";
                    cmd.CommandText = sql;

                    using (SqlDataReader reader = cmd.ExecuteReader()) 
                    {
                        while (reader.Read()) 
                        {
                            AreaInfo area = new AreaInfo();
                            area.AreaId = int.Parse(reader["AreaId"].ToString());
                            area.AreaName = reader["AreaName"].ToString();
                            area.AreaPid = Convert.ToInt32(reader["AreaPid"].ToString());

                            cboProvince.Items.Add(area.AreaName);
                            list.Add(area);
                        }//End of While
                    }//End of SqlDataReader
                }//End of SqlCommand
            }//End of SqlConnection
            cboProvince.SelectedIndex = 0;
        }

        private void cboProvince_SelectedIndexChanged(object sender, EventArgs e)
        {
            cboCity.Items.Clear();

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    string sql = string.Format(@"select AreaId, AreaName, AreaPid from dbo.AreaFull where AreaPid = {0}", list[cboProvince.SelectedIndex].AreaId);
                    cmd.CommandText = sql;

                    using (SqlDataReader reader = cmd.ExecuteReader()) 
                    {
                        while (reader.Read()) 
                        {
                            cboCity.Items.Add(reader["AreaName"].ToString());
                        }//End of While
                    }//End of SqlDatReader
                }//End of SqlCommand
            }//End of SqlConnection
            cboCity.SelectedIndex = 0;
        }
    }
}
