using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 日期选择器
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            for (int i = 2017; i >= 1800; i--)
            {
                cboYear.Items.Add(i + "年");
            }
        }

        private void cboYear_SelectedIndexChanged(object sender, EventArgs e)
        {
            cboMonth.Text = "";
            cboMonth.Items.Clear();
            for (int i = 1; i < 13; i++)
            {
                cboMonth.Items.Add(i + "月");
            }
        }

        private void cboMonth_SelectedIndexChanged(object sender, EventArgs e)
        {
            cboDay.Items.Clear();
            cboDay.Text = "";
            //获得当前选择的年月转换成string 数组 再转换成int类型
            //string[] yearArrary = cboYear.SelectedItem.ToString().Split(new char[] { '年' }, StringSplitOptions.RemoveEmptyEntries);
            //string[] monthArrary = cboMonth.SelectedItem.ToString().Split(new char[] { '月' }, StringSplitOptions.RemoveEmptyEntries);
            int year = int.Parse((cboYear.Text.Split(new char[]{'年'},StringSplitOptions.RemoveEmptyEntries))[0]);
            int month = int.Parse((cboMonth.Text.Split(new char[] { '月' }, StringSplitOptions.RemoveEmptyEntries))[0]);
            //判断是否为闰年的2月
            if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)
            {
                for (int i = 1; i < 30; i++)
                {
                    cboDay.Items.Add(i + "日");
                }
            }
            else 
            {
                switch (month) 
                {
                    case 1:case 3: case 5: case 7: case 8: case 10:case 12:
                        for (int i = 1; i < 32; i++)
                        {
                            cboDay.Items.Add(i + "天");
                        }
                        break;
                    case 4: case 6: case 9: case 11:
                        for (int i = 1; i < 31; i++)
                        {
                            cboDay.Items.Add(i + "天");
                        }
                        break;
                    case 2:
                        for (int i = 1; i < 29; i++)
                        {
                            cboDay.Items.Add(i + "天");
                        }
                        break;
                }
            } 
        }
    }
}
