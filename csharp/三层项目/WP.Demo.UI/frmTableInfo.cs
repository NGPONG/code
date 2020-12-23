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
    public delegate void DelInitializeFrmTableInfoData(object sender, EventArgs e);
    public delegate void InitializeDataGridViewDel();
    public partial class frmTableInfo : Form
    {
        private static frmTableInfo _frmSingle = null; // 存储单例窗体的对象

        private TableInfoBLL objTableInfoBLL = new TableInfoBLL();
        private HallInfoBLL objHallInfoBLL = new HallInfoBLL();

        // 保存在本地的数据表
        private DataTable dtResult = null;
        // 刷新主界面信息的委托
        private DelInitializeFrmMainData delMain;
        // 刷新控件的一个委托
        private DelInitializeFrmTableInfoData del;
        // 告诉主窗体当前页面关闭的一个委托
        private InitializeDelInitializeFrmTableInfoData InitializeDel;
        // 刷新DataGridView的委托
        public InitializeDataGridViewDel InitializeDataGridViewDel;

        /// <summary>
        ///  私有构造函数，构造单例
        /// </summary>
        private frmTableInfo(DelInitializeFrmMainData del,InitializeDelInitializeFrmTableInfoData InitializeDel)
        {
            InitializeComponent();
            this.TopLevel = true;
            this.delMain = del;
            this.InitializeDel = InitializeDel;
            this.del = new DelInitializeFrmTableInfoData(this.frmTableInfo_Load);
            this.InitializeDataGridViewDel = this.InitializeDataGridView;
        }
        /// <summary>
        ///  获取单例对象
        /// </summary>
        /// <returns></returns>
        public static frmTableInfo GetSingleObject(DelInitializeFrmMainData del, InitializeDelInitializeFrmTableInfoData InitializeDel)
        {
            try
            {
                if (_frmSingle == null)
                {
                    _frmSingle = new frmTableInfo(del, InitializeDel);
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
        private void frmTableInfo_Load(object sender, EventArgs e)
        {
            try
            {
                // 初始化表格
                this.InitializeDataGridView();
                // 初始化下拉框
                this.InitializeComboBox();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  初始化下拉框
        /// </summary>
        private void InitializeComboBox()
        {
            try
            {
                DataTable dtResult = this.objHallInfoBLL.GetData();
                DataRow drTemp = dtResult.NewRow();
                drTemp["HId"] = string.Empty;
                drTemp["HTitle"] = string.Empty;
                dtResult.Rows.InsertAt(drTemp, 0);

                DataTable dtResult2 = new DataTable();
                dtResult2.Columns.AddRange(new DataColumn[] { new DataColumn("name"), new DataColumn("id") });
                DataRow drTemp2 = dtResult2.NewRow();
                drTemp2["name"] = string.Empty;
                drTemp2["id"] = string.Empty;
                dtResult2.Rows.Add(drTemp2);
                DataRow drTemp3 = dtResult2.NewRow();
                drTemp3["name"] = "使用中";
                drTemp3["id"] = "使用中";
                dtResult2.Rows.Add(drTemp3);
                DataRow drTemp4 = dtResult2.NewRow();
                drTemp4["name"] = "空闲";
                drTemp4["id"] = "空闲";
                dtResult2.Rows.Add(drTemp4);

                // 查询下拉框
                this.ddlHallSearch.DataSource = dtResult;
                this.ddlHallSearch.DisplayMember = "HTitle";
                this.ddlHallSearch.ValueMember = "HId";
                this.ddlHallSearch.SelectedValue = string.Empty;

                this.ddlFreeSearch.DataSource = dtResult2;
                this.ddlFreeSearch.DisplayMember = "name";
                this.ddlFreeSearch.ValueMember = "Id";
                this.ddlFreeSearch.SelectedValue = string.Empty;

                // 添加、修改下拉框
                this.ddlHallAdd.DataSource = new DataView(dtResult).ToTable(); ;
                this.ddlHallAdd.DisplayMember = "HTitle";
                this.ddlHallAdd.ValueMember = "HId";
                this.ddlHallAdd.SelectedValue = string.Empty;
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
                this.dtResult = this.objTableInfoBLL.GetData();
                this.dgvList.DataSource = this.dtResult;

                //this.ddlHallSearch.SelectedValue = string.Empty;
                //this.ddlFreeSearch.SelectedValue = string.Empty;
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
        ///  下拉框搜索选择改变
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ddlHallSearch_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlFreeSearch.Text)) && string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlHallSearch.Text))) // 如果两个控件为空则需要还原初始信息
                {
                    this.dgvList.DataSource = this.dtResult;
                }
                else
                {
                    DataView dvTemp = new DataView(this.dtResult);
                    dvTemp.RowFilter = "TIsFree like '" + ConvertWP.ToTrimString(this.ddlFreeSearch.SelectedValue) + "%' AND THallName like '" + ConvertWP.ToTrimString(this.ddlHallSearch.Text) + "%'";
                    this.dgvList.DataSource = dvTemp.ToTable();
                    dvTemp.Dispose();
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  下拉框搜索选择改变
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ddlFreeSearch_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlFreeSearch.Text)) && string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlHallSearch.Text))) // 如果两个控件为空则需要还原初始信息
                {
                    this.dgvList.DataSource = this.dtResult;
                }
                else
                {
                    DataView dvTemp = new DataView(this.dtResult);
                    dvTemp.RowFilter = "TIsFree like '" + ConvertWP.ToTrimString(this.ddlFreeSearch.SelectedValue) + "%' AND THallName like '" + ConvertWP.ToTrimString(this.ddlHallSearch.Text) + "%'";
                    this.dgvList.DataSource = dvTemp.ToTable();
                    dvTemp.Dispose();
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  显示全部，重置搜索
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSearchAll_Click(object sender, EventArgs e)
        {
            try
            {
                this.OnDataGridViewDataBusinese();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
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
                if (string.IsNullOrEmpty(this.txtTitle.Text))
                {
                    throw new Exception("请输入厅堂或包间名称");
                }
                if (string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlHallAdd.SelectedValue)))
                {
                    throw new Exception("请选择厅包");
                }

                TableInfoModel model = new TableInfoModel()
                {
                    TTitle = ConvertWP.ToTrimString(this.txtTitle.Text),
                    THallId = ConvertWP.ToTrimString(this.ddlHallAdd.SelectedValue),
                    TIsFree = this.rbFree.Checked ? "0" : "1"
                };

                if (this.btnSave.Text == "添加")
                {
                    if (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.objTableInfoBLL.CheckHaveSameTableTitle(model).Rows[0]["CharacterResult"])))
                    {
                        MessageBox.Show("已存在当前餐桌名称！请检查");
                        return;
                    }

                    if (this.objTableInfoBLL.AddTableInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtTTitle", model.TTitle);

                        MessageBox.Show("添加成功！");

                        // 刷新主界面信息
                        this.delMain();
                    }
                    else
                    {
                        MessageBox.Show("添加失败！");
                        return;
                    }
                }
                else if (this.btnSave.Text == "修改")
                {
                    model.TId = Convert.ToString(this.txtId.Text.ToString());

                    if (this.objTableInfoBLL.UpdateTableInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtTId", ConvertWP.ToTrimString(model.TId));

                        MessageBox.Show("修改成功！");

                        // 刷新主界面信息
                        this.delMain();
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
                this.txtId.Text = "添加时无编号";
                this.ddlHallAdd.SelectedValue = string.Empty;
                this.rbFree.Checked = true;
                this.txtTitle.Text = string.Empty;
                this.dgvList.Rows[0].Selected = true;

                this.btnSave.Text = "添加";
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  厅包管理
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnAddHall_Click(object sender, EventArgs e)
        {
            try
            {
                frmHallInfo frm = frmHallInfo.GetSingleObject(this.del,this.delMain);
                frm.Show();
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
                this.txtId.Text = Convert.ToString(dgvr.Cells["dgvtxtTId"].Value);
                this.txtTitle.Text = Convert.ToString(dgvr.Cells["dgvtxtTTitle"].Value);
                this.ddlHallAdd.Text = Convert.ToString(dgvr.Cells["dgvtxtTHallId"].Value);
                bool isFreeChecked = Convert.ToString(dgvr.Cells["dgvtxtTIsFree"].Value) == "空闲" ? true : false;
                if (isFreeChecked)
                {
                    this.rbFree.Checked = isFreeChecked;
                }
                else 
                {
                    this.rbUnFree.Checked = !isFreeChecked;
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  删除选中行数据
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

                TableInfoModel model = new TableInfoModel()
                {
                    TId = ConvertWP.ToTrimString(this.dgvList.CurrentRow.Cells["dgvtxtTId"].Value)
                };

                if (this.objTableInfoBLL.DeleteTableInfoDetail(model) <= 0)
                {
                    MessageBox.Show("删除失败，请检查数据的完整性");
                    return;
                }
                // 刷新明细
                OnDataGridViewDataBusinese();

                MessageBox.Show("删除成功!");

                // 刷新主界面信息
                this.delMain();
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
        private void frmTableInfo_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                _frmSingle = null;
                this.InitializeDel();
            }
            catch { }
        }

    }
}
