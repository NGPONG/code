﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using WP.Demo.BLL;
using WP.Demo.Common;
using WP.Demo.Model;

namespace WP.Demo.UI
{
    public delegate void DelInitializeFrmDishInfoData(object sender, EventArgs e);
    public partial class frmDishInfo : Form
    {
        private static frmDishInfo _frmSingle = null; // 存储单例窗体的对象

        private DishTypeInfoBLL objDishTypeInfoBLL = new DishTypeInfoBLL();
        private DishInfoBLL objDishInfoBLL = new DishInfoBLL();

        // 保存在本地的数据表
        private DataTable dtResult = null;
        // 刷新控件的一个委托
        DelInitializeFrmDishInfoData del;
        /// <summary>
        ///  私有构造函数，构造单例
        /// </summary>
        private frmDishInfo()
        {
            InitializeComponent();
            //this.TopMost = true;
            this.TopLevel = true;
        }
        /// <summary>
        ///  获取单例对象
        /// </summary>
        /// <returns></returns>
        public static frmDishInfo GetSingleObject()
        {
            try
            {
                if (_frmSingle == null)
                {
                    _frmSingle = new frmDishInfo();
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
        private void frmDishInfo_Load(object sender, EventArgs e)
        {
            try
            {
                // 初始化表格
                this.InitializeDataGridView();
                // 初始化下拉框
                this.InitializeComboBox();
                this.del = new DelInitializeFrmDishInfoData(this.frmDishInfo_Load);
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
                DataTable dtResult = objDishTypeInfoBLL.GetData();
                DataRow drTemp = dtResult.NewRow();
                drTemp["DId"] = string.Empty;
                drTemp["DTitle"] = string.Empty;
                dtResult.Rows.InsertAt(drTemp, 0);

                DataTable dtResult2 = new DataView(dtResult).ToTable();

                // 查询下拉框
                this.ddlTypeSearch.DataSource = dtResult;
                this.ddlTypeSearch.DisplayMember = "DTitle";
                this.ddlTypeSearch.ValueMember = "DId";
                this.ddlTypeSearch.SelectedValue = string.Empty;

                // 添加、修改下拉框
                this.ddlTypeAdd.DataSource = dtResult2;
                this.ddlTypeAdd.DisplayMember = "DTitle";
                this.ddlTypeAdd.ValueMember = "DId";
                this.ddlTypeAdd.SelectedValue = string.Empty;
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
                this.dtResult = this.objDishInfoBLL.GetData();
                this.dgvList.DataSource = this.dtResult;

                this.txtTitleSearch.Text = string.Empty;
                this.ddlTypeSearch.SelectedValue = string.Empty;
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
        ///  文本改变进行模糊查询
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void txtTitleSearch_TextChanged(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtTitleSearch.Text) && string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlTypeSearch.Text))) // 如果两个控件为空则需要还原原来的信息
                {
                    this.dgvList.DataSource = this.dtResult;
                }
                else
                {
                    DataView dvTemp = new DataView(this.dtResult);
                    dvTemp.RowFilter = "DTitle like '" + ConvertWP.ToTrimString(this.txtTitleSearch.Text) + "%' AND DTypeTitle" + (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlTypeSearch.SelectedValue)) ? " = '" + ConvertWP.ToTrimString(this.ddlTypeSearch.Text) + "'" : " like '%'");
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
        private void ddlTypeSearch_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtTitleSearch.Text) && string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlTypeSearch.Text))) // 如果两个控件为空则需要还原原来的信息
                {
                    this.dgvList.DataSource = this.dtResult;
                }
                else
                {
                    DataView dvTemp = new DataView(this.dtResult);
                    dvTemp.RowFilter = "DTitle like '" + ConvertWP.ToTrimString(this.txtTitleSearch.Text) + "%' AND DTypeTitle" + (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlTypeSearch.SelectedValue)) ? " = '" + ConvertWP.ToTrimString(this.ddlTypeSearch.Text) + "'" : " like '%'");
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
        ///  添加/搜索
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnSave_Click(object sender, EventArgs e)
        {
            try
            {
                if (string.IsNullOrEmpty(this.txtTitleSave.Text))
                {
                    throw new Exception("请输入菜品名称");
                }
                if (string.IsNullOrEmpty(ConvertWP.ToTrimString(this.ddlTypeAdd.SelectedValue)))
                {
                    throw new Exception("请选择菜品类别");
                }
                if (string.IsNullOrEmpty(this.txtPrice.Text))
                {
                    throw new Exception("请输入价格");
                }

                DishInfoModel model = new DishInfoModel()
                {
                    DTitle = ConvertWP.ToTrimString(this.txtTitleSave.Text),
                    DTypeId = ConvertWP.ToTrimString(this.ddlTypeAdd.SelectedValue),
                    DPrice = ConvertWP.ToTrimString(this.txtPrice.Text),
                    DChar = ConvertWP.ToTrimString(this.txtChar.Text)
                };

                if (this.btnSave.Text == "添加")
                {
                    if (!string.IsNullOrEmpty(ConvertWP.ToTrimString(this.objDishInfoBLL.CheckHaveSameDishTitle(model).Rows[0]["CharacterResult"])))
                    {
                        MessageBox.Show("已存在当前菜品！请检查");
                        return;
                    }

                    if (this.objDishInfoBLL.AddDishInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtdTitle", model.DTitle);

                        MessageBox.Show("添加成功！");
                    }
                    else
                    {
                        MessageBox.Show("添加失败！");
                        return;
                    }
                }
                else if (this.btnSave.Text == "修改")
                {
                    model.DId = Convert.ToString(this.txtId.Text.ToString());

                    if (this.objDishInfoBLL.UpdateDishInfoDetail(model) > 0)
                    {
                        this.OnDataGridViewDataBusinese();
                        // 修正选中的行
                        DataGridViewDefaultExtra.AmendmentSelectedRow(this.dgvList, "dgvtxtDId", ConvertWP.ToTrimString(model.DId));

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
        ///   输入菜品名称的时候，读出该菜品的拼音
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void txtTitleSave_TextChanged(object sender, EventArgs e)
        {
            try
            {
                string strConvert = ConvertWP.ToTrimString(this.txtTitleSave.Text);
                // 如果是英语，则不匹配，避免报错
                if (Regex.IsMatch(strConvert, @"[a-zA-Z]")) 
                {
                    return;
                }
                this.txtChar.Text = ChineseCharConvertHelper.GetTextInital(strConvert);
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  双击行修改
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
                this.txtId.Text = Convert.ToString(dgvr.Cells["dgvtxtDId"].Value);
                this.txtTitleSave.Text = Convert.ToString(dgvr.Cells["dgvtxtdTitle"].Value);
                this.txtPrice.Text = Convert.ToString(dgvr.Cells["dgvtxtDPrice"].Value);
                this.ddlTypeAdd.Text = Convert.ToString(dgvr.Cells["dgvtxtDTypeTitle"].Value);
                this.txtChar.Text = Convert.ToString(dgvr.Cells["dgvtxtDChar"].Value);
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  取消后，还原数据
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnCancel_Click(object sender, EventArgs e)
        {
            try
            {
                this.txtId.Text = "添加时无编号";
                this.ddlTypeAdd.SelectedValue = string.Empty;
                this.txtChar.Text = string.Empty;
                this.txtTitleSave.Text = string.Empty;
                this.txtPrice.Text = string.Empty;
                this.dgvList.Rows[0].Selected = true;
                this.btnSave.Text = "添加";
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

                DishInfoModel model = new DishInfoModel()
                {
                    DId =  ConvertWP.ToTrimString(this.dgvList.CurrentRow.Cells["dgvtxtDId"].Value)
                };

                if (this.objDishInfoBLL.DeleteDishInfoDetail(model) <= 0)
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
        ///  菜品类型管理
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnAddType_Click(object sender, EventArgs e)
        {
            try
            {
                frmDishTypeInfo frm = frmDishTypeInfo.GetSingleObject(this.del);
                frm.Show();
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
        private void frmDishInfo_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                _frmSingle = null;
            }
            catch { }
        }

    }
}
