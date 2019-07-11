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

namespace 批量删除数据
{
    public delegate void DelGetString(string ID, string UserName, string UserPassWord, string ErrorTime, string ErrorEndDateTime, string DelFlag);
    public partial class MainFrm : Form
    {
        public event DelGetString DelGetStringEvent;

        private UpdateFrm _updateFrm;
        public MainFrm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GetSqlData();
        }
            

        /// <summary>
        /// 刷新表
        /// </summary>
        public void GetSqlData() 
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand cmd = new SqlCommand(@"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime,DelFlag from dbo.UserInfo where DelFlag=0",conn)) 
                {
                    using (SqlDataAdapter adapter = new SqlDataAdapter(cmd)) 
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);

                        dgvData.DataSource = dt;
                    }
                }
            }

            dgvData.ClearSelection();
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if (dgvData.SelectedRows.Count <= 0) 
            {
                MessageBox.Show("请选择要删除的行");
                return;
            }

            if (MessageBox.Show("是否删除选中的数据", "提示", MessageBoxButtons.YesNo,MessageBoxIcon.Warning) != DialogResult.Yes) 
            {
                return;
            }


            DataGridViewSelectedRowCollection drc = dgvData.SelectedRows;
            List<int> numList = new List<int>();
            for (int i = 0; i < drc.Count; i++)
            {
                numList.Add(int.Parse(drc[i].Cells["ID"].Value.ToString()));
            }


            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    for (int i = 0; i < numList.Count; i++)
                    {
                        string sql = @"update dbo.UserInfo set DelFlag=1 where ID=@id" + i;
                        SqlParameter par = new SqlParameter("@id" + i, SqlDbType.Int);
                        par.Value = numList[i];
                        cmd.Parameters.Add(par);
                        cmd.CommandText = sql;
                        cmd.ExecuteNonQuery();
                    }
                    
                }
            }

            MessageBox.Show("删除成功！");
            GetSqlData();
        }

        private void btnShowUpdataFrm_Click(object sender, EventArgs e)
        {
            InsertFrm updateFrm = new InsertFrm();
            updateFrm.FormClosed += updateFrm_FormClosed;//添加UpdateFrm窗体关闭后的事件
            updateFrm.Show();

        }
        /// <summary>
        /// 窗体关闭后的事件，重新载入一次表格的内容
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void updateFrm_FormClosed(object sender, FormClosedEventArgs e)
        {
            GetSqlData();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.dgvData.SelectedRows.Count <= 0) 
            {
                MessageBox.Show("请选择行！！");
                return;
            }

            string ID = this.dgvData.SelectedRows[0].Cells["ID"].Value.ToString();
            string UserName = this.dgvData.SelectedRows[0].Cells["UserName"].Value.ToString();
            string UserPassWord = this.dgvData.SelectedRows[0].Cells["UserPassWord"].Value.ToString();
            string ErrorTime = this.dgvData.SelectedRows[0].Cells["ErrorTime"].Value.ToString();
            string ErrorEndDateTime = this.dgvData.SelectedRows[0].Cells["ErrorEndDateTime"].Value.ToString();
            string DelFlag = this.dgvData.SelectedRows[0].Cells["DelFlag"].Value.ToString();

            this._updateFrm = new UpdateFrm(this);
            DelGetStringEvent += _updateFrm.GetTxtString;//注册事件
            this._updateFrm.FormClosed += _updateFrm_FormClosed;//窗体关闭后发生的事件

            DelGetStringEvent(ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag);

            //调用UpdateFrm中的函数，该函数用于注册UpdateFrm中的Buttom按钮的点击事件
            this._updateFrm.RegistBtnSaveClickEventMethod(MainFrm_AfterEditFrmBtnSave_Click);

            this._updateFrm.Show();
        }

        /// <summary>
        /// UpdateFrm中的Button控件所注册的函数
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        public void MainFrm_AfterEditFrmBtnSave_Click(Object sender, EventArgs e) 
        {
            MessageBox.Show("这是在其他窗体中注册这个的Button的点击事件哟");
        }


        /// <summary>
        /// UpdateFrm窗体关闭后所发生的事件
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void _updateFrm_FormClosed(object sender, FormClosedEventArgs e)
        {
            DelGetStringEvent -= _updateFrm.GetTxtString;
            this._updateFrm = null;
            button1_Click_1(this, null);
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            #region 多条件查询字符串的拼接
            string sql = @"select ID, UserName, UserPassWord, ErrorTime, ErrorEndDateTime, DelFlag from dbo.UserInfo";

            List<string> listWhere = new List<string>();//记录 where 条件的集合
            List<SqlParameter> listParameters = new List<SqlParameter>();//记录 参数 的集合

            if (!string.IsNullOrEmpty(txtSearchUserName.Text))
            {
                string strWhere = @"  UserName like @userName ";
                SqlParameter parameter = new SqlParameter("@userName", SqlDbType.NVarChar);
                parameter.Value = @"%" + txtSearchUserName.Text + "%";

                listWhere.Add(strWhere);
                listParameters.Add(parameter);
            }

            if (!string.IsNullOrEmpty(txtSearchPwd.Text))
            {
                string strWhere = @" UserPassWord like @userPassWord ";
                SqlParameter parameter = new SqlParameter("@userPassWord", SqlDbType.NVarChar);
                parameter.Value = @"%" + txtSearchPwd.Text + "%";

                listWhere.Add(strWhere);
                listParameters.Add(parameter);
            }

            if (listWhere.Count > 0)
            {
                sql += " where" + string.Join("and", listWhere.ToArray());
            }
            #endregion

            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand selectCommand = new SqlCommand(sql, conn)) 
                {
                    selectCommand.Parameters.AddRange(listParameters.ToArray());
                    using (SqlDataAdapter adapter = new SqlDataAdapter(selectCommand)) 
                    {
                        DataTable dt = new DataTable();
                        adapter.Fill(dt);
                        this.dgvData.DataSource = dt;
                    }
                }
            }
        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            //获取当前活动的列 
            DataGridViewCell dgvc = dgvData.CurrentCell;

            //获取当前获得的行
            DataGridViewRow dgvr = dgvData.CurrentRow;

            //获取当前点击行的下标：第一种写法
            int index = dgvData.CurrentCell.RowIndex;

            //获取当前点击行的下标：第二种写法
            int index2 = dgvData.CurrentRow.Index;
        }

    }
}
