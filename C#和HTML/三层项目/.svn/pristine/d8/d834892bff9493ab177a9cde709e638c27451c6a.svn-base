using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using WP.Demo.BLL;
using WP.Demo.Common;
using WP.Demo.Model;

namespace WP.Demo.UI
{
    /// <summary>
    ///  用于防止跨线程调用引发的异常
    /// </summary>
    public delegate void AsyncHallInfoMethodCaller();
    /// <summary>
    ///  用于防止跨线程调用引发的异常
    /// </summary>
    /// <param name="tpTemp"></param>
    public delegate void DelControlProperties(TabPage tpTemp);
    /// <summary>
    ///  用于刷新主界面信息的委托
    /// </summary>
    public delegate void DelInitializeFrmMainData();
    /// <summary>
    ///  用于初始化刷新TableInfo的委托
    /// </summary>
    public delegate void InitializeDelInitializeFrmTableInfoData();

    public partial class frmMain : Form
    {
        /// <summary>
        ///  用户级别
        /// </summary>
        public string UserTag { get; set; }

        private InitializeDataGridViewDel DelTableInfo = null;

        public static bool IsShowOrderDishForm = false;

        /// <summary>
        ///  构造函数
        /// </summary>
        public frmMain()
        {
            InitializeComponent();
        }
        /// <summary>
        ///  系统加载
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void frmMain_Load(object sender, EventArgs e)
        {
            try
            {
                // 判断用户级别
                if (this.UserTag == "0")
                {
                    this.menuManagerInfo.Visible = false;
                }

                Control.CheckForIllegalCrossThreadCalls = false;

                this.ThreadDynamicCreationHallInformation();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  调用线程的方法
        /// </summary>
        private void ThreadDynamicCreationHallInformation() 
        {
            try
            {
                AsyncHallInfoMethodCaller caller = new AsyncHallInfoMethodCaller(DynamicCreationHallInformation);
                IAsyncResult result = caller.BeginInvoke(new AsyncCallback(AsyncHallInfoMethodCallBack), "AsyncStat");
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
        ///  动态创建餐桌信息
        /// </summary>
        private void DynamicCreationHallInformation()
        {
            try
            {
                // 每次执行需要清空一次标签页，以免多次创建

                this.tcInfo.TabPages.Clear();
                HallInfoBLL objHallInfoBLL = new HallInfoBLL();
                TableInfoBLL objTableInfoBLL = new TableInfoBLL();
                DataTable dtTableInfo = objTableInfoBLL.GetData();
                DataTable dtHallInfo = objHallInfoBLL.GetData();
                for (int i = 0; i < dtHallInfo.Rows.Count; i++)
                {
                    string hallName = ConvertWP.ToTrimString(dtHallInfo.Rows[i]["HTitle"]);
                    // 创建标签页对象并指定名字
                    TabPage tpTemp = new TabPage(hallName);

                    // 创建ListView的一些信息
                    ListView lvTemp = new ListView(); // 创建ListView控件
                    lvTemp.DoubleClick += lvTemp_DoubleClick; // 注册双击事件
                    lvTemp.LargeImageList = this.imageList;
                    lvTemp.Dock = DockStyle.Fill;

                    DataRow[] drArrary = dtTableInfo.Select("THallName = '" + hallName + "'");
                    for (int j = 0; j < drArrary.Length; j++)
                    {
                        ListViewItem viewItem = new ListViewItem(ConvertWP.ToTrimString(drArrary[j]["TTitle"]), drArrary[j]["TIsFree"].ToString() == "空闲" ? 0 : 1);
                        lvTemp.Items.Add(viewItem);
                    }

                    // 为标签页对象里的容器添加控件
                    tpTemp.Controls.Add(lvTemp);

                    this.Invoke(new DelControlProperties(ModifyControl), tpTemp);
                }
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
        ///  双击listview
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void lvTemp_DoubleClick(object sender, EventArgs e)
        {
            try
            {
                if (!frmMain.IsShowOrderDishForm)
                {
                    frmMain.IsShowOrderDishForm = true;

                    // 获取当前点击的ListViewItem
                    ListViewItem viewItem = ((ListView)sender).SelectedItems[0];

                    if (viewItem.ImageIndex == 1)
                    {
                        MessageBox.Show(this, "当前餐桌为占用状态");
                        return;
                    }

                    // 获取餐桌名
                    string tableTitle = viewItem.Text;

                    // 修改使用状态
                    TableInfoBLL objTableInfoBLL = new TableInfoBLL();
                    objTableInfoBLL.UpdateTableInfoState(new TableInfoModel() { TTitle = tableTitle, TIsFree = "1" });

                    // 刷新图片
                    viewItem.ImageIndex = 1;

                    if (this.DelTableInfo != null)
                    {
                        // 刷新TableInfo窗体的数据
                        this.DelTableInfo();
                    }

                    // 弹出点菜窗体
                    frmOrderDish frm = frmOrderDish.GetSingleObject();
                    frm.Show();
                }
                else 
                {
                    MessageBox.Show("检测到存在正在执行点菜的任务，请结束后再进行下一桌的点菜功能！");
                    return;
                }
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        
        /// <summary>
        ///  修改控件属性，只能是主线程调用
        /// </summary>
        /// <param name="tpTemp"></param>
        private void ModifyControl(TabPage tpTemp)
        {
            try
            {
                // 为标签容器添加标签
                this.tcInfo.TabPages.Add(tpTemp);
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
        ///  回调函数：异步委托：动态创建餐桌信息
        /// </summary>
        /// <param name="result"></param>
        private void AsyncHallInfoMethodCallBack(IAsyncResult result)
        {
            try
            {
                AsyncHallInfoMethodCaller handler = (AsyncHallInfoMethodCaller)((AsyncResult)result).AsyncDelegate;
                handler.EndInvoke(result);
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  刷新委托
        /// </summary>
        private void InitializeTableInfoDel() 
        {
            this.DelTableInfo = null;
        }
        /// <summary>
        ///  退出系统
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menuQuit_Click(object sender, EventArgs e)
        {
            try
            {
                if (MessageBox.Show("是否要退出当前系统？", "提示", MessageBoxButtons.OKCancel) == DialogResult.Cancel)
                {
                    return;
                }
                System.Environment.Exit(0);
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  管理员菜单
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menuManagerInfo_Click(object sender, EventArgs e)
        {
            try
            {
                frmManagerInfo frm = frmManagerInfo.GetSingleObject();
                frm.Show();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  会员管理菜单
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menuMemberInfo_Click(object sender, EventArgs e)
        {
            try
            {
                frmMemberInfo frm = frmMemberInfo.GetSingleObject();
                frm.Show();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  菜品管理
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menuDishInfo_Click(object sender, EventArgs e)
        {
            try
            {
                frmDishInfo frm = frmDishInfo.GetSingleObject();
                frm.Show();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }
        /// <summary>
        ///  餐桌管理
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void menuTableInfo_Click(object sender, EventArgs e)
        {
            try
            {
                frmTableInfo frm = frmTableInfo.GetSingleObject(new DelInitializeFrmMainData(this.ThreadDynamicCreationHallInformation),new InitializeDelInitializeFrmTableInfoData(this.InitializeTableInfoDel));
                this.DelTableInfo = frm.InitializeDataGridViewDel;
                frm.Show();
            }
            catch (Exception objException)
            {
                MessageBox.Show(objException.Message);
            }
        }

    }
}
