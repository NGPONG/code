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

namespace WP.Demo.UI
{
    public partial class frmOrderDish : Form
    {
        private DishInfoBLL objDishInfoBLL = new DishInfoBLL();
        private DishTypeInfoBLL objDishTypeInfoBLL = new DishTypeInfoBLL();

        private static frmOrderDish _frmSingle = null; // 存储单例窗体的对象

        // 保存在本地的数据表
        private DataTable dtResult = null;

        /// <summary>
        ///  私有构造函数，构造单例
        /// </summary>
        private frmOrderDish()
        {
            InitializeComponent();
            this.TopLevel = true;
        }
        /// <summary>
        ///  获取单例对象
        /// </summary>
        /// <returns></returns>
        public static frmOrderDish GetSingleObject()
        {
            try
            {
                if (_frmSingle == null)
                {
                    _frmSingle = new frmOrderDish();
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
        private void frmOrderDish_Load(object sender, EventArgs e)
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
                DataTable dtResult = this.objDishTypeInfoBLL.GetData();
                DataRow drTemp = dtResult.NewRow();
                drTemp["DId"] = string.Empty;
                drTemp["DTitle"] = string.Empty;
                dtResult.Rows.InsertAt(drTemp, 0);
                this.ddlType.DataSource = dtResult;
                this.ddlType.DisplayMember = "DTitle";
                this.ddlType.ValueMember = "DId";
                this.ddlType.SelectedValue = string.Empty;
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
                this.dgvAllDish.AutoGenerateColumns = false;
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
        ///  加载数据源
        /// </summary>
        private void OnDataGridViewDataBusinese()
        {
            try
            {
                this.dtResult = this.objDishInfoBLL.GetData();
                this.dgvAllDish.DataSource = this.dtResult;
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
        ///  下拉框选择改变
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void ddlType_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtTitle.Text) && string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlType.Text))) // 如果两个控件为空则需要还原原来的信息
                {
                    this.dgvAllDish.DataSource = this.dtResult;
                }
                else
                {
                    DataView dvTemp = new DataView(this.dtResult);
                    dvTemp.RowFilter = "DChar like '" + ConvertWP.ToTrimString(this.txtTitle.Text.ToUpper()) + "%' AND DTypeTitle" + (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlType.SelectedValue)) ? " = '" + ConvertWP.ToTrimString(this.ddlType.Text) + "'" : " like '%'");
                    this.dgvAllDish.DataSource = dvTemp.ToTable();
                    dvTemp.Dispose();
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  文本改变
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void txtTitle_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtTitle.Text) && string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlType.Text))) // 如果两个控件为空则需要还原原来的信息
                {
                    this.dgvAllDish.DataSource = this.dtResult;
                }
                else
                {
                    DataView dvTemp = new DataView(this.dtResult);
                    dvTemp.RowFilter = "DChar like '" + ConvertWP.ToTrimString(this.txtTitle.Text.ToUpper()) + "%' AND DTypeTitle" + (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlType.SelectedValue)) ? " = '" + ConvertWP.ToTrimString(this.ddlType.Text) + "'" : " like '%'");
                    this.dgvAllDish.DataSource = dvTemp.ToTable();
                    dvTemp.Dispose();
                }
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
        private void frmOrderDish_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                _frmSingle = null;
                frmMain.IsShowOrderDishForm = false;
            }
            catch { }
        }

    }
}
