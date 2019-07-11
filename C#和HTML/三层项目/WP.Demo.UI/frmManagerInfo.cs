using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using WP.Demo.BLL;
using WP.Demo.Common;
using WP.Demo.Model;

namespace WP.Demo.UI
{
    public partial class frmManagerInfo : Form
    {
        private ManagerInfoBLL objManagerInfoBLL = new ManagerInfoBLL();
        public static frmManagerInfo _frmSingle = null; // 存储单例窗体的对象
        /// <summary>
        ///  私有构造函数，构造单例
        /// </summary>
        private frmManagerInfo()
        {
            InitializeComponent();
            //this.TopMost = true;
            this.TopLevel = true;
        }
        /// <summary>
        ///  获取单例对象
        /// </summary>
        /// <returns></returns>
        public static frmManagerInfo GetSingleObject() 
        {
            try
            {
                if (_frmSingle == null) 
                {
                    _frmSingle = new frmManagerInfo();
                }
                return _frmSingle;
            }
            catch (Exception objException) 
            {
                if (objException.InnerException != null) 
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  窗体加载
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ManagerInfoUI_Load(object sender, EventArgs e)
        {
            try
            {
                this.InitializeDataGridView();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  初始化表格
        /// </summary>
        private void InitializeDataGridView()
        {
            try
            {
                // 设置DataGridView是否自动生成绑定的数据源所具有的列
                this.dgvList.AutoGenerateColumns = false;
                // 加载数据源
                this.OnDataGridViewDataBusinese();
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  获取表格数据
        /// </summary>
        private void OnDataGridViewDataBusinese()
        {
            try
            {
                DataTable dtResult = this.objManagerInfoBLL.GetData();
                this.dgvList.DataSource = dtResult;
            }
            catch (Exception objException)
            {
                if (objException.InnerException != null)
                {
                    throw new Exception(objException.InnerException.Message);
                }
                throw new Exception(objException.Message);
            }
        }
        /// <summary>
        ///  添加/修改
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtName.Text))
                {
                    throw new Exception("请输入用户名");
                }
                if (string.IsNullOrEmpty(this.txtPwd.Text))
                {
                    throw new Exception("请输入密码");
                }

                ManagerInfoModel model = new ManagerInfoModel()
                {
                    MName = this.txtName.Text,
                    MPwd = this.txtPwd.Text,
                    MType = this.rbtEmployee.Checked ? "1" : "0"
                };

                if (this.btnSave.Text == "添加")
                {
                    if (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.objManagerInfoBLL.CheckHaveSameUserName(model).Rows[0]["CharacterResult"])))
                    {
                        MessageBox.Show("已存在用户名！请检查");
                        return;
                    }

                    if (this.objManagerInfoBLL.AddManagerInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtMName", model.MName);

                        MessageBox.Show("添加成功！");
                    }
                    else
                    {
                        MessageBox.Show("添加失败！");
                        return;
                    }
                }
                else // 修改
                {
                    model.MId = Convert.ToInt32(this.txtId.Text.ToString());

                    if (this.objManagerInfoBLL.UpdateManagerInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtMId", ConvertWP.ToTrimString(model.MId));

                        MessageBox.Show("修改成功！");
                    }
                    else 
                    {
                        MessageBox.Show("修改失败！");
                    }
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  删除
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnRemove_Click(object sender, EventArgs e)
        {
            try
            {
                if (MessageBox.Show("是否删除选中的明细", "警告", MessageBoxButtons.YesNo).Equals(DialogResult.No))
                {
                    return;
                }

                ManagerInfoModel model = new ManagerInfoModel()
                {
                    MId = int.Parse(this.dgvList.CurrentRow.Cells["dgvtxtMId"].Value.ToString())
                };

                if (this.objManagerInfoBLL.DeleteManagerInfoDetail(model) <= 0)
                {
                    MessageBox.Show("删除失败，请检查数据的完整性");
                    return;
                }
                // 刷新明细
                OnDataGridViewDataBusinese();

                MessageBox.Show("删除成功!");
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  双击表格
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dgvList_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            try
            {
                if (this.dgvList.Rows.Count <= 0)
                {
                    return;
                }

                this.btnSave.Text = "修改";

                // 添加数据
                DataGridViewRow dgvr = this.dgvList.CurrentRow;
                this.txtId.Text = Convert.ToString(dgvr.Cells["dgvtxtMId"].Value);
                this.txtName.Text = Convert.ToString(dgvr.Cells["dgvtxtMName"].Value);
                this.txtPwd.Text = "666666";
                if (Convert.ToString(dgvr.Cells["dgvtxtMType"].Value).Equals("经理"))
                {
                    this.rbtManager.Checked = true;
                }
                else
                {
                    this.rbtEmployee.Checked = true;
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  取消
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                this.txtName.Text = string.Empty;
                this.txtId.Text = "添加时无编号";
                this.txtPwd.Text = string.Empty;
                this.rbtManager.Checked = true;
                this.btnSave.Text = "添加";
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  关闭的时候还原单例对象
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void frmManagerInfo_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                _frmSingle = null;
            }
            catch { }
        }

    }
}
