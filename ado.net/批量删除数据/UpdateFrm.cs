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
    public delegate void DelLoadDate();
    public partial class UpdateFrm : Form
    {
        //public event DelLoadDate DelLoadDateEvent;

        private MainFrm _mainfrm;
        public UpdateFrm(MainFrm mainfrm)
        {
            InitializeComponent();
            this._mainfrm = mainfrm;
        }

        public void GetTxtString(string ID,string UserName,string UserPassWord,string ErrorTime,string ErrorEndDateTime,string DelFlag) 
        {
            this.txtID.Text= ID;
            this.txtUserName.Text = UserName;
            this.txtUserPwd.Text = UserPassWord;
            this.txtErrorTime.Text = ErrorTime;
            this.txtErrorEndTime.Text = ErrorEndDateTime;
            this.txtDelFlag.Text = DelFlag;
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            using (SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["SqlConnection"].ConnectionString)) 
            {
                conn.Open();
                using (SqlCommand cmd = conn.CreateCommand()) 
                {
                    string sql = @" update dbo.UserInfo set UserName = @UserName,UserPassWord=@UserPassWord,ErrorTime=@ErrorTime,ErrorEndDateTime=@ErrorEndDateTime,DelFlag=@DelFlag where ID=@ID";

                    SqlParameter[] parameters = new SqlParameter[6];

                    parameters[0] = new SqlParameter("@ID", SqlDbType.Int);
                    parameters[0].Value = int.Parse(this.txtID.Text);

                    parameters[1] = new SqlParameter("@UserName", SqlDbType.NVarChar);
                    parameters[1].Value = this.txtUserName.Text;

                    parameters[2] = new SqlParameter("@UserPassWord", SqlDbType.NVarChar);
                    parameters[2].Value = this.txtUserPwd.Text;

                    parameters[3] = new SqlParameter("@ErrorTime", SqlDbType.Int);
                    parameters[3].Value = int.Parse(this.txtErrorTime.Text);

                    parameters[4] = new SqlParameter("@ErrorEndDateTime", SqlDbType.DateTime);
                    parameters[4].Value = DateTime.Parse(this.txtErrorEndTime.Text);

                    parameters[5] = new SqlParameter("@DelFlag", SqlDbType.Int);
                    parameters[5].Value = int.Parse(this.txtDelFlag.Text);

                    cmd.Parameters.AddRange(parameters);
                    cmd.CommandText = sql;

                    if (cmd.ExecuteNonQuery() > 0) 
                    {
                        MessageBox.Show("执行成功！");
                        //DelLoadDateEvent += this._mainfrm.GetSqlData;
                        //DelLoadDateEvent();
                        this.Close();
                    }
                    else 
                    {
                        MessageBox.Show("未知错误！");
                        return;
                    }
                }
            }
        }

        /// <summary>
        /// 在其他窗体中为按钮单击事件注册一个事件
        /// </summary>
        /// <param name="btnSavClick"></param>
        public void RegistBtnSaveClickEventMethod(EventHandler btnSavClick) 
        {
            this.btnSave.Click += btnSavClick;
        }

    }
}
