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
    public partial class frmMemberTypeInfo : Form
    {
        public MemberTypeInfoBLL objMemberTypeInfoBLL = new MemberTypeInfoBLL();

        public static frmMemberTypeInfo _frmSingle = null; // 存储单例窗体的对象

        private DelInitializeFrmMemberInfoData del;
        /// <summary>
        ///  私有构造函数，构造单例
        /// </summary>
        private frmMemberTypeInfo(DelInitializeFrmMemberInfoData del)
        {
            InitializeComponent();
            //this.TopMost = true;
            this.TopLevel = true;
            this.del = del;
        }
        /// <summary>
        ///  获取单例对象
        /// </summary>
        /// <returns></returns>
        public static frmMemberTypeInfo GetSingleObject(DelInitializeFrmMemberInfoData del)
        {
            try
            {
                if (_frmSingle == null)
                {
                    _frmSingle = new frmMemberTypeInfo(del);
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
        private void frmMemberTypeInfo_Load(object sender, EventArgs e)
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
                DataTable dtResult = this.objMemberTypeInfoBLL.GetData();
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
        ///  双击指定行
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
                this.txtTitle.Text = Convert.ToString(dgvr.Cells["dgvtxtMTitle"].Value);
                this.txtDiscount.Text = Convert.ToString(dgvr.Cells["dgvtxtMDiscount"].Value);
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  点击添加或修改
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtTitle.Text))
                {
                    throw new Exception("请输入折扣类型");
                }
                if (string.IsNullOrEmpty(this.txtDiscount.Text))
                {
                    throw new Exception("请输入折扣数额");
                }

                decimal discount;
                if (!(decimal.TryParse(ConvertWP.ToTrimString(this.txtDiscount.Text), out discount))) 
                {
                    throw new Exception("请输入正确的折扣数额！");
                }

                MemberTypeInfoModel model = new MemberTypeInfoModel()
                {
                    MTitle = this.txtTitle.Text,
                    MDiscount = this.txtDiscount.Text
                };
                if (this.btnSave.Text == "添加")
                {
                    if (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.objMemberTypeInfoBLL.CheckHaveSameDiscountTitle(model).Rows[0]["CharacterResult"])))
                    {
                        MessageBox.Show("已存在该折扣类型！请检查或修改");
                        return;
                    }

                    if (this.objMemberTypeInfoBLL.AddMemberTypeInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtMTitle", model.MTitle);

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
                    model.MId = this.txtId.Text.ToString();

                    if (this.objMemberTypeInfoBLL.UpdateMemberTypeInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtMid", ConvertWP.ToTrimString(model.MId));

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
        ///  取消
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                this.txtDiscount.Text = string.Empty;
                this.txtId.Text = "添加时无编号";
                this.txtTitle.Text = string.Empty;
                this.btnSave.Text = "添加";
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

                MemberTypeInfoModel model = new MemberTypeInfoModel()
                {
                    MId = ConvertWP.ToTrimString( this.dgvList.CurrentRow.Cells["dgvtxtMId"].Value)
                };

                if (this.objMemberTypeInfoBLL.DeleteMemberTypeInfoDetail(model) <= 0)
                {
                    MessageBox.Show("删除失败，请检查数据的完整性");
                    return;
                }

                MessageBox.Show("删除成功!");
                // 刷新明细
                OnDataGridViewDataBusinese();
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
        private void frmMemberTypeInfo_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                _frmSingle = null;
            }
            catch { }
        }
        /// <summary>
        ///  每当数据改变时候，刷新frmMemberInfo的数据
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void dgvList_DataBindingComplete(object sender, DataGridViewBindingCompleteEventArgs e)
        {
            try
            {
                this.del(null, null);
            }
            catch (Exception objException) 
            {
                MessageBox.Show(objException.Message);
            }
        }

    }
}
